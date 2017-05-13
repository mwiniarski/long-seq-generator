#ifndef INPUT_H_
#define INPUT_H

#include <string>
#include <stdexcept>

class Input {
public:
    Input(int argc, const char** argv);

    int getErrorRate() {return errorRate;}
    int getReadsLength() {return readsLength;}
    int getCoverage() {return coverage;}
    int getSequenceLength() {return sequenceLength;}
private:
    void findParameter(std::string &arg1, std::string &arg2);
    void throwError(std::string msg);

    int sequenceLength;
    int coverage;
    int readsLength;
    int errorRate;
};

#endif // INPUT_H_
