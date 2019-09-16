#pragma once

namespace st
{
	class Parser
	{
	public:
		Parser(const std::string& path_file_input, const std::string& path_file_output);
		~Parser();

		void count_all_words();

	private:
		std::ifstream file_input_;
		std::ofstream file_output_;
	};
}