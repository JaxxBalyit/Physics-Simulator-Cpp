#ifndef UTILS_H
#define UTILS_H

#include "physics.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void saveToCSV(const std::string& filename, const std::vector<State>& data);

#endif // UTILS_H