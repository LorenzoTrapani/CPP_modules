#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

void handleInput(const std::string& filename, const std::map<std::string, float>& exchangeData);
std::map<std::string, float> loadExchangeData(const std::string& filename);

#endif

