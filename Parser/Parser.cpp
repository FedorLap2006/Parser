#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <vector>
#include <unordered_map>

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

int st::Parser::count_all_words()
{
	std::unordered_map<std::string, size_t> result;

	std::string buff;

	while (file_input_)
	{
		file_input_ >> buff;

		if (file_input_)
			result[buff]++;
	}

	std::vector<std::pair<size_t, std::string>> sortered_result(result.size());
	size_t i = 0;
	for (auto iter = result.begin(); iter != result.end(); iter++, i++)
	{
		sortered_result[i].first = iter->second;
		sortered_result[i].second = iter->first;
	}

	std::sort(sortered_result.begin(), sortered_result.end(), std::greater<std::pair<size_t, std::string>>());

	for (auto iter = sortered_result.begin(); iter != sortered_result.end(); iter++)
		file_output_ << iter->second << " " << iter->first << '\n';

	return EXIT_SUCCESS;
}

long st::Parser::find_word(const std::string& str)
{
	std::string buff;

	while (file_input_)
	{
		file_input_ >> buff;

		if (str == buff)
			return static_cast<long>(file_input_.tellg()) - buff.size();
	}

	return -1;
}

int st::Parser::replace_all_ch(const char ch, const char new_ch)
{
	char buff;
	while (file_input_.get(buff))
	{
		if (buff == ch)
			file_output_ << new_ch;
		else
			file_output_ << buff;
	}

	return EXIT_SUCCESS;
}