#include "FileUtils.h"
#include <fstream>
#include <stdexcept>

float FileUtils::sizeDifference(const string &fileInput, const string &fileOutput) {
    ifstream input(fileInput, ios::binary | ios::ate);
    ifstream output(fileOutput, ios::binary | ios::ate);

    if (!input.is_open() || !output.is_open()) {
        throw runtime_error("File not found");
    }

    float inputSize = input.tellg();
    float outputSize = output.tellg();

    input.close();
    output.close();

    return (outputSize / inputSize) * 100;
}
