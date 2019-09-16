#include <iostream>
#include <string>

#include "Parser.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Invalid Arguments" << std::endl;
		std::cerr << "Use: Parser.exe <path_input> <path_output>" << std::endl;

		return EXIT_FAILURE;
	}

	prs::Parser pr(argv[1], argv[2]);

	return 0;
}