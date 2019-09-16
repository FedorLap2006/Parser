#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

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

	std::vector<std::pair<size_t, std::string>> items(result.size());
	size_t i = 0;
	for (auto iter = result.begin(); iter != result.end(); iter++, i++)
	{
		items[i].first = iter->second;
		items[i].second = iter->first;
	}

	std::sort(items.begin(), items.end(), std::greater<std::pair<size_t, std::string>>());

	for (auto iter = items.begin(); iter != items.end(); iter++)
		file_output_ << iter->second << " " << iter->first << '\n';

	return EXIT_SUCCESS;
}