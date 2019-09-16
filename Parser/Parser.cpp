#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <execution>

#include "Parser.h"

st::Parser::Parser(const std::string& path_file_input, const std::string& path_file_output)
	:	file_input_(path_file_input, std::ios::in),
		file_output_(path_file_output, std::ios::out)
{
	if (!file_input_)
	{
		file_input_.close();
		file_output_.close();

		throw std::runtime_error("Cannot open file " + path_file_input);
	}

	if (!file_output_)
	{
		file_input_.close();
		file_output_.close();

		throw std::runtime_error("Cannot open file " + path_file_output);
	}
}
st::Parser::~Parser()
{
	file_input_.close();
	file_output_.close();
}

void count_all_words()
{
	std::map<std::string, int> result;
}