#pragma once

#include <fstream>

#include "common.h"


std::vector<std::vector<std::string>> parseCsv(const std::string& filename);
std::vector<std::vector<int>> parseCsvInt(const std::string& filename);