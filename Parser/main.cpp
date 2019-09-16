#include <iostream>
#include <fstream>
#include <string>

#include "Parser.h"

int main(const int argc, const char* argv[])
{
	try
	{
		if (argc < 3)
			throw std::string("Invalid Arguments\nUse: Parser.exe <path_input> <path_output>");


		st::Parser pr(static_cast<std::string>(argv[1]), static_cast<std::string>(argv[2]));
	}
	catch (const std::string problem)
	{
		std::cerr << problem << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}