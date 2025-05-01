#ifndef UTILS_H
#define UTILS_H

#include <string>


bool isInsideMap(int x, int y);

int clamp(int value, int min, int max);

int randomInt(int min, int max);

bool fileExists(const std::string& filename);

#endif
