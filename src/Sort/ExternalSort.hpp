#pragma once

#include <string>
#include <fstream>

namespace externalsort {
	void
	Merge(const char* input_file_path1,
		  const char* input_file_path2,
		  const char* output_file_path)
	{
		std::ifstream input_file_stream1(input_file_path1);
		std::ifstream input_file_stream2(input_file_path2);
		std::ofstream output_file_stream(output_file_path);

		std::string line1, line2;
		std::getline(input_file_stream1, line1);
		std::getline(input_file_stream2, line2);
		double element1 = std::stod(line1);
		double element2 = std::stod(line2);
		
		while (1)
		{
			if (element1 <= element2)
			{
				output_file_stream << element1 << std::endl;
				std::getline(input_file_stream1, line1);
				if (line1 == "") break;
				else element1 = std::stod(line1);
			} 
			else
			{
				output_file_stream << element2 << std::endl;
				std::getline(input_file_stream2, line2);
				if (line2 == "") break;
				else element2 = std::stod(line2);
			}
		}

		while (line1 == "" && line2 != "")
		{
			output_file_stream << element2 << std::endl;
			std::getline(input_file_stream2, line2);
			if (line2 == "") break;
			else element2 = std::stod(line2);
		}
		while (line1 != "" && line2 == "")
		{
			output_file_stream << element1 << std::endl;
			std::getline(input_file_stream1, line1);
			if (line1 == "") break;
			else element1 = std::stod(line1);
		}
	}
}