#ifndef REPLACE_H
#define REPLACE_H

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
public:
    Replace(const char *infile, const char *s1, const char *s2);
    ~Replace();
    void    replace();
private:
    const char  *_infile;
    std::string _outfile;
    const char  *_s1;
    const char  *_s2;
    int         _s1len;
};

Replace *createReplace(const char *infile, const char *s1, const char *s2);

#endif