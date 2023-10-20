#include "Replace.hpp"

Replace::Replace(const char *infile, const char *s1, const char *s2)
{
    std::string outfile(infile);
    outfile += ".replace";
    _infile = infile;
    _outfile = outfile;
    _s1 = s1;
    _s2 = s2;
    _s1len = std::string(s1).length();
}

Replace::~Replace()
{

}

void Replace::replace()
{
    std::ifstream ifs(_infile, std::ios::in);
    std::ofstream ofs(_outfile.c_str(), std::ios::out);
    char *buf = new char[_s1len + 1];

    if (!ifs.is_open())
    {
        std::cout << "Error 2 : " << _infile << " could not be opened." << std::endl;
        return;
    }
    if (!ofs.is_open())
    {
        std::cout << "Error 3 : " << _outfile << " could not be opened." << std::endl;
        return;
    }
    while (ifs.good())
    {
        if (ifs.eof())
            break;
        while (ifs.peek() != _s1[0] && ifs.good())
            ofs << (char)ifs.get();
        ifs.read(buf, _s1len);
        buf[_s1len] = '\0';
        if (ifs.gcount() == _s1len)
        {
            if (std::string(buf) == _s1)
                ofs << _s2;
            else
                ofs << buf;
        }
        else
            ofs << buf;
        buf[0] = '\0';
    }
    ifs.close();
    ofs.close();
    delete[] buf;
}

Replace *createReplace(const char *infile, const char *s1, const char *s2)
{
    std::ifstream ifs(infile, std::ios::in);

    if (!ifs.is_open())
    {
        std::cout << "Error 1 : " << infile << " could not be opened." << std::endl;
    }
    ifs.close();
    return (new Replace(infile, s1, s2));
}