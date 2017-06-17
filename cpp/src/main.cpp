#include <iostream>

#include "Generator.h"

void readAndGenerate(int argc, const char** argv) {

    Generator gen(std::make_unique<Input>(argc, argv));
    gen.run();
}

int main(int argc, const char** argv) {
    readAndGenerate(argc, argv);
    return 1;
}
