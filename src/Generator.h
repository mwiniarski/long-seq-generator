#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <chrono>
#include <memory>
#include <fstream>
#include <iostream>
#include <cstring>
#include <random>
#include "Input.h"

class Generator {
public:
    Generator(std::unique_ptr<Input> input_);

    void run();

private:
    void createGenome();
    void createAndSaveReads();
    void saveCorrectGenome();
    void throwError(std::string msg);

    std::unique_ptr<Input> input;
    std::unique_ptr<unsigned char[]> genome;
};

#endif // GENERATOR_H_
