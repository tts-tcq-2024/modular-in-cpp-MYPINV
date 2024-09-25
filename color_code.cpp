#include "color_code.h"
#include <iostream>
#include <iomanip>

const std::vector<std::string> MAJOR_COLORS = {"White", "Red", "Black", "Yellow", "Violet"};
const std::vector<std::string> MINOR_COLORS = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Get color pair from pair number
ColorPair getColorFromPairNumber(int pairNumber) {
    int majorIndex = (pairNumber - 1) / MINOR_COLORS.size();
    int minorIndex = (pairNumber - 1) % MINOR_COLORS.size();
    
    return {MAJOR_COLORS[majorIndex], MINOR_COLORS[minorIndex]};
}

// Get pair number from color pair
int getPairNumberFromColor(const std::string& major, const std::string& minor) {
    int majorIndex = -1, minorIndex = -1;

    for (int i = 0; i < MAJOR_COLORS.size(); ++i) {
        if (MAJOR_COLORS[i] == major) {
            majorIndex = i;
            break;
        }
    }

    for (int i = 0; i < MINOR_COLORS.size(); ++i) {
        if (MINOR_COLORS[i] == minor) {
            minorIndex = i;
            break;
        }
    }

    if (majorIndex == -1 || minorIndex == -1) {
        return -1; // Invalid pair
    }
    
    return (majorIndex * MINOR_COLORS.size()) + minorIndex + 1;
}

// Print color code manual
void printColorCodeManual() {
    std::cout << std::setw(10) << "Pair Number" << std::setw(15) << "Major Color" << std::setw(15) << "Minor Color" << std::endl;
    for (int i = 1; i <= 25; ++i) {
        ColorPair colorPair = getColorFromPairNumber(i);
        std::cout << std::setw(10) << i << std::setw(15) << colorPair.majorColor << std::setw(15) << colorPair.minorColor << std::endl;
    }
}
