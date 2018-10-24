#include "parse_csv.h"




std::vector<std::vector<std::string>> parseCsv(const std::string& filename)
{
	std::ifstream data_file(filename, std::ios::in);
	std::string line_str;
	std::vector<std::vector<std::string>> str_array;
	while (std::getline(data_file, line_str))
	{
		std::stringstream ss(line_str);
		std::string str;
		std::vector<std::string> line_array;
		// °´ÕÕ¶ººÅ·Ö¸ô
		while (getline(ss, str, ','))
			line_array.push_back(str);
		str_array.push_back(line_array);
	}

	data_file.close();
	return str_array;
}

std::vector<std::vector<int>> parseCsvInt(const std::string& filename)
{
	auto str_array = parseCsv(filename);

	std::vector<std::vector<int>> int_array;
	for (auto &str_line : str_array)
	{
		std::vector<int> int_line;
		for (auto &str : str_line)
		{
			int_line.push_back(std::stoi(str));
		}
		int_array.push_back(int_line);
	}
	return int_array;
}