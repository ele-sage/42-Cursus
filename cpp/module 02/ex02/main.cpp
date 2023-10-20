#include "Fixed.hpp"

int main (void)
{
    Fixed        a;
    Fixed const  b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max(a++, b) << std::endl;
	a = 0;
	while (++a < 1)
		std::cout << a << std::endl;
	std::cout << "----------------" << std::endl;
	while (a-- > 0)
		std::cout << a << std::endl;
    return 0;
}