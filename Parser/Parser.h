#pragma once

namespace prs
{
	class Parser
	{
	public:
		Parser(char* path_file_input = nullptr, char* path_file_output = nullptr)
			:	path_file_input_(path_file_input),
				path_file_output_(path_file_output)
		{
			std::cout << path_file_input_ << std::endl;
			std::cout << path_file_output_ << std::endl;
		}
		//~Parser();

	private:
		char* path_file_input_;
		char* path_file_output_;

		FILE* file_input;
		FILE* file_output;
	};
}