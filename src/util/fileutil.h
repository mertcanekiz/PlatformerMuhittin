#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

inline std::string readFile(const char* filename)
{
	FILE* file = fopen(filename, "rt");
	fseek(file, 0, SEEK_END);
	unsigned long length = ftell(file);
	char* data  = new char[length + 1];
	memset(data, 0, length + 1);
	fseek(file, 0, SEEK_SET);
	fread(data, 1, length, file);
	fclose(file);

	std::string result(data);
	delete[] data;
	return result;
}

inline std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }

    return elems;
}

inline std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

inline std::vector<unsigned int> loadMap(const char* filename)
{
	std::string file = readFile(filename);
	std::vector<std::string> lines = split(file, '\n');
	std::string linesCombined;

	for (int i = 0; i < lines.size(); i++)
		linesCombined += lines[i] + ' ';

	std::vector<std::string> tokens = split(linesCombined, ' ');
	std::vector<unsigned int> tokensResult;

	for(unsigned int i = 0; i < tokens.size(); i++)
	{
		unsigned int number;
		if (!(std::istringstream(tokens[i]) >> number)) number = 0;
		tokensResult.push_back(number);
	}

	return tokensResult;

}


/* Patch for MinGW bug*/
namespace std
{
	template < typename T > std::string to_string( const T& n )
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

#endif