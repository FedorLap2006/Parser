#pragma once

namespace st
{
	class Parser
	{
	public:
		Parser(const std::string& path_file_input, const std::string& path_file_output);
		~Parser();

		int count_all_words();

		long find_word(const std::string& str);
		int replace_all_ch(const char ch, const char new_ch);

	private:
		std::ifstream file_input_;
		std::ofstream file_output_;
	};
}