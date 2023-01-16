#include "Sed.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	Sed sed(argv[1]);
	if (!sed.read_file())
		return (1);
	sed.replace_text(argv[2], argv[3]);
	if (!sed.write_file())
		return (1);
	return (0);
}