#include "Input.h"

void Input::findParameter(std::string &arg1, std::string &arg2) {
    if(arg1 == "-L") {
        readsLength = stoi(arg2);

        if(readsLength < 2)
            throwError("Length of reads must be at least 2.");

    } else
    if(arg1 == "-E") {
        errorRate = stof(arg2);

        if(errorRate < 0 || errorRate > 99)
            throwError("Error rate must be between 0 and 99.");

    } else
    if(arg1 == "-C") {
        coverage = stoi(arg2);

        if(coverage < 1)
            throwError("Coverage must be at least 1.");

    } else
        throwError("Parameter " + arg1 + " doesn't exist");
}

Input::Input(int count_, const char** argv_)
    :coverage(10), readsLength(10000), errorRate(0.0f)
{
    //argument count is always even
    if (count_%2 != 0 || count_ < 2)
        throwError("Wrong format of parameters.");

    std::string arg1(argv_[1]);
    sequenceLength = stoi(arg1);

    for(int i = 2; i < count_; i += 2) {

        std::string arg1(argv_[i]);
        std::string arg2(argv_[i+1]);

        findParameter(arg1, arg2);
    }
}

void Input::throwError(std::string msg) {
    throw std::runtime_error(msg);
}
