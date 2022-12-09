#include <iostream>
#include <fstream>
#include "file.h"








int main(int argc, char const *argv[])
{
    int length = 0;
    vector<char> data = read_file_stream("data", &length);

    for(int i = 0; i < length; i++)
    {
        cout << data[i];
    }

    return 0;
}

