#include <iostream>
#include <fstream>

#include "file.h"

vector<char> read_file(string name)
{
    ifstream file(name, ios::binary | ios::ate);
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    vector<char> buffer(size);
    file.read(buffer.data(), size);

    return (vector<char>)buffer;
}