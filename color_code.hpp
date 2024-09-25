#ifndef COLOR_CODE_H
#define COLOR_CODE_H

#include <string>
#include <vector>

// Define a structure for color pairs
struct ColorPair {
    std::string majorColor;
    std::string minorColor;
};

// Constants
extern const std::vector<std::string> MAJOR_COLORS;
extern const std::vector<std::string> MINOR_COLORS;

// Function declarations
ColorPair getColorFromPairNumber(int pairNumber);
int getPairNumberFromColor(const std::string& major, const std::string& minor);
void printColorCodeManual();

#endif // COLOR_CODE_H
