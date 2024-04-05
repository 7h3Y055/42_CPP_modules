#include <iostream>
#include <locale>

std::string ft_touppercase(std::string str)
{
	std::string new_str;
	int i = 0;

	while (str[i])
	{
		new_str += toupper(str[i]);
		i++;
	}
	return (new_str);
}

int	main(int argc, char **argv)
{
	int i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	while (i < argc)
	{
		std::cout << ft_touppercase(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return 0;
}
