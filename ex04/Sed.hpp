#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <fstream>

class Sed
{
	private:
		std::string infile_name;
		std::string outfile_name;
		std::string	text;

	public:
		Sed(std::string);
		~Sed();
		
		bool	read_file(void);
		bool	write_file(void);
		void	replace_text(std::string from, std::string to);
};

#endif