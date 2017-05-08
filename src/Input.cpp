#include "Input.h"

Input::Input(int count_, const char** argv_)
{
    //argument count is always even
    if (count_%2 != 1)
        throwError("Wrong format of parameters.");

    for(int i = 1; i < count_; i++) {

        std::string arg1(argv_[i]);
        std::string arg2(argv_[i+1]);

        if(arg1 == "-L") {
            readsLength = stoi(arg2);

            if(readsLength < 2)
                throwError("Length of reads must be at least 1.");

        } else
        if(arg1 == "-R") {
            errorRate = stof(arg2);

            if(errorRate < 0 || errorRate > 99)
                throwError("Error rate must be between 0 and 99.");

        } else
        if(arg1 == "-C") {
            readsCount = stoi(arg2);

            if(readsCount < 1)
                throwError("Number of reads must be positive.");
        }

        i += 2;
    }
}

void Input::throwError(std::string msg) {
    throw std::runtime_error(msg);
}
