#include <iostream>
#include <fstream>

#include "file.h"

vector<char> read_file(string name)
{
    ifstream file(name, ios::binary | ios::ate);
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    vector<char> buffer(size);
    if (file.read(buffer.data(), size))
    {
        cout << buffer[0] << buffer[1] << buffer[2] << buffer[3] << endl;
    }

    return (vector<char>)buffer;
}