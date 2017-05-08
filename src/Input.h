#ifndef INPUT_H_
#define INPUT_H

#include <string>
#include <stdexcept>

class Input {
public:
    Input(int argc, const char** argv);

    float getErrorRate() {return errorRate;}
    int getReadsLength() {return readsLength;}
    int getReadsCount() {return readsCount;}
private:
    void throwError(std::string msg);

    int readsLength;
    int readsCount;
    float errorRate;
};

#endif // INPUT_H_
