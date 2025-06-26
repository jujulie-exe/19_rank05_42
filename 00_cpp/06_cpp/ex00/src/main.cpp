#include "../include/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	ScalarConverter::convert("c");
	ScalarConverter::convert("100");
	ScalarConverter::convert("1.10");
	ScalarConverter::convert("1.1000");
	ScalarConverter::convert("214748364899");
	ScalarConverter::convert("214748364899");
	ScalarConverter::convert("Abcde");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("0");
	ScalarConverter::convert(".");
	ScalarConverter::convert("1abcd-inff");
	ScalarConverter::convert("");
	ScalarConverter::convert("               ");
	ScalarConverter::convert("        1       ");
    return 0;
}
