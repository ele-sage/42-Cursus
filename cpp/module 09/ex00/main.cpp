#include "Bitcoin.hpp"

int main(int argc, char **argv)
{
    try
    {
        Bitcoin btc("data.csv");
        if (argc == 2)
            btc.printValues(argv[1]);
        else
        {
            cout << "Usage: ./btc input.txt" << endl;
            return (1);
        }
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return (0);
}