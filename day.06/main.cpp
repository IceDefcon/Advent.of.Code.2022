#include <iostream>
#include <fstream>
#include "file.h"

int main(int argc, char const *argv[])
{
    vector<char> data = read_file("data");

    // Read first 4 characters
    cout << data[0] << data[1] << data[2] << data[3] << endl;

    return 0;
}