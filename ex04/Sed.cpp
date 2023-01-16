#include "Sed.hpp"

Sed::Sed(std::string name)
{
	this->infile_name = name;
	this->outfile_name = name.append(".replace");
	this->text = "";
}

Sed::~Sed()
{
}

bool	Sed::read_file(void)
{
	std::string	str;
	std::ifstream infile(this->infile_name.c_str(), std::ifstream::in);
	if (!infile.is_open())
		return (false);
	getline(infile, str, '\0');
	this->text.append(str);
	infile.close();
	return (true);
}

bool	Sed::write_file(void)
{
	std::ofstream outfile(this->outfile_name.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!outfile.is_open())
		return (false);
	outfile << this->text;
	outfile.close();
	return (true);
}

void	Sed::replace_text(std::string from, std::string to)
{
	size_t start = 0;
	size_t end;
	std::string new_text = "";
	while ((end = this->text.find(from, start)) != std::string::npos)
	{
		new_text.append(this->text.substr(start, end - start));
		new_text.append(to);
		start = end + from.length();
	}
	new_text.append(this->text.substr(start, this->text.length() - start));
	this->text = new_text;
}