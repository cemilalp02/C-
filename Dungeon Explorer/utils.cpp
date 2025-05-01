#include "utils.h"
#include <cstdlib>
#include <ctime>
#include <fstream>


bool isInsideMap(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}


int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}


int randomInt(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        std::srand(std::time(nullptr));
        initialized = true;
    }
    return min + std::rand() % (max - min + 1);
}


bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
