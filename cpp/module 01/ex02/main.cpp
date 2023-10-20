#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "str: \t"<< &str << ": " << str << std::endl;
    std::cout << "str PTR: "<< stringPTR << ": " << *stringPTR << std::endl;
    std::cout << "str REF: "<< &stringREF << ": " << stringREF << std::endl;
    
    return 0;
}