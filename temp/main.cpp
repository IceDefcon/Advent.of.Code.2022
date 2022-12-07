#include <iostream>
#include <fstream>
#include "file.h"

int main(int argc, char const *argv[])
{
    int length = 0;
    vector<char> data = read_file("data", &length);

    // Read first 4 characters
    for(int i = 0; i < length; i++)
    {
        cout << data[i];
    }

    return 0;
}

