#ifndef CSV_UTILS
#define CSV_UTILS

#include<string>
#include<vector>

std::string trim(const std::string& text);
std::vector<std::string> parseCsvLine(const std::string& line);
std::string csvEscape(const std::string& value);
std::string joinPath(const std::vector<std::string>& path);


#endif