

#include "../include/iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << "\n";

    iter(intArray, intLength, increment);

    std::cout << "After incrementing: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << "\n";

    std::string strArray[] = {"hello", "world", "template", "test"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strLength, printElement<std::string>);
    std::cout << "\n";

    std::cout << "Uppercase string hex: ";
	int intHexArray[] = {0x2a, 0x51ac};
	size_t	HexLengh = 2;

    iter(intHexArray, HexLengh, printUppercase<int>);
    std::cout << "\n";

    return 0;
}
