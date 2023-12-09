#ifndef HUFFMANN_FILEUTILS_H
#define HUFFMANN_FILEUTILS_H

#include <string>

using namespace std;

/**
 * @class FileUtils
 * @brief Utility class for file operations related to Huffman compression.
 *
 * Provides static methods for calculating the size difference between input and output files.
 */
class FileUtils {
public:
    /**
     * Calculate the percentage size difference between input and output files.
     * @param fileInput Path to the input file.
     * @param fileOutput Path to the output file.
     * @return The size difference as a percentage of the input file size.
     * @throws std::runtime_error if files cannot be opened.
     */
    static float sizeDifference(const string &fileInput, const string &fileOutput);
};

#endif //HUFFMANN_FILEUTILS_H
