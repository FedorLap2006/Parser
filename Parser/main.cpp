#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <execution>

#include "Parser.h"

int main(const int argc, const char* argv[])
{
	try
	{
		if (argc < 3)
			throw std::runtime_error("Invalid Arguments\nUse: Parser.exe <path_input> <path_output>");

		st::Parser prarser(static_cast<std::string>(argv[1]), static_cast<std::string>(argv[2]));
	}
	catch (std::exception& exception)
	{
		std::cerr << "Exeption: " << exception.what() << std::endl;

		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Expresion of an undetermined type." << std::endl;
		return EXIT_FAILURE;
	}



	return EXIT_SUCCESS;
}