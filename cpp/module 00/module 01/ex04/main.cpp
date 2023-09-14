#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
        return (1);
    }
    Replace *r = createReplace(argv[1], argv[2], argv[3]);
    if (r)
    {
        r->replace();
        delete r;
    }
    return (0);
}