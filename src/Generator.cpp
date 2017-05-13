#include "Generator.h"

Generator::Generator(std::unique_ptr<Input> input_)
    :input(std::move(input_))
{}

void Generator::createGenome()
{
    char base[] = {'A', 'G', 'T', 'C'};

    int length = input->getSequenceLength();
    genome = std::make_unique<unsigned char[]>(length);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    for(int i = 0; i < length; i++) {
        genome[i] = base[dis(gen)];
    }
}

void Generator::saveCorrectGenome()
{
    FILE *fp = fopen("whole_correct_genome", "w");

    if(fp == nullptr)
        throwError("Can't open file to save");

    int length = input->getSequenceLength();
    fwrite(genome.get(), 1, length, fp);
    fclose(fp);
}

void Generator::createAndSaveReads()
{
    FILE *fp = fopen("out", "w");

    if(fp == nullptr)
        throwError("Can't open file to save");

    int length = input->getReadsLength();

    std::random_device rd;
    std::mt19937 gen(rd());
    char bases[] = {'A', 'G', 'T', 'C'};
    //cuts
    std::uniform_int_distribution<> dis(0, input->getSequenceLength() - length);
    //error places
    std::uniform_int_distribution<> err(0, length-1);
    //error bases
    std::uniform_int_distribution<> base(0, 3);

    //choose cut
    std::unique_ptr<char[]> cut(new char[length]);
    std::string str("@read_0\n");

    int readsCount = ceil(input->getSequenceLength() / (float)length * input->getCoverage());
    unsigned char* startPosition;
    char a;
    int chosenBase, errorPlace;

    for(int i = 0; i < readsCount; i++)
    {
        startPosition = genome.get() + dis(gen);
        std::copy(startPosition, startPosition + length, cut.get());

        //apply errors
        for(int j = 0; j < input->getErrorRate() * length / 100; j++)
        {
            chosenBase = base(gen);
            a = bases[chosenBase];
            errorPlace = err(gen);
            if(a != cut[errorPlace])
                cut[errorPlace] = a;
            else
                cut[errorPlace] = bases[(chosenBase+1)%4];
        }

        fwrite(str.c_str(), 1, str.length(), fp);
        fwrite(cut.get(), 1, length, fp);

        str = "\n+\n@read_" + std::to_string(i + 1) + "\n";
    }
}

void Generator::run()
{
    using namespace std::chrono;
    typedef high_resolution_clock Time;

    auto start = Time::now();

        createGenome();

    std::cout << "Creating genome: " << duration_cast<milliseconds> (Time::now() - start).count()<< "ms"<< std::endl;
    start = Time::now();

        saveCorrectGenome();

    std::cout << "Saving to file: " << duration_cast<milliseconds> (Time::now() - start).count() << "ms"<< std::endl;
    start = Time::now();

        createAndSaveReads();

    std::cout << "Saving to file: " << duration_cast<milliseconds> (Time::now() - start).count() << "ms"<< std::endl;
}

void Generator::throwError(std::string msg)
{
    throw std::runtime_error(msg);
}
