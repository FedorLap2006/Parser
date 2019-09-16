#include <iostream>
#include <fstream>

#include "Parser.h"

st::Parser::Parser(const std::string& path_file_input, const std::string& path_file_output)
{
	file_input_.open(path_file_input, std::ios::in);
	if (!file_input_)
		throw "Cannot open file " + path_file_input;

	file_output_.open(path_file_output, std::ios::out);
	if (!file_output_)
		throw "Cannot open file " + path_file_output;
}
st::Parser::~Parser()
{
	file_input_.close();
	file_output_.close();
}