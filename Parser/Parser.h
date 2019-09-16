#pragma once

namespace st
{
	class Parser
	{
	public:
		Parser(const std::string& path_file_input, const std::string& path_file_output);
		~Parser();

	private:
		std::ifstream file_input_;
		std::ofstream file_output_;
	};
}