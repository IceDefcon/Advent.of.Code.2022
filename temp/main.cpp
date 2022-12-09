#include <iostream>
#include <fstream>
#include "file.h"

int main(int argc, char const *argv[])
{
    int length = 0;
    vector<char> data = read_file_stream("data", &length);

    // Read first 4 characters
    for(int i = 0; i < length; i++)
    {
        cout << data[i];
    }

    string text;
    ifstream MyReadFile("data");

    bool skip = false;

    cout << endl;
    while (getline (MyReadFile, text)) 
    {

        cout << "Line number ---> " << text << endl;
    }
    return 0;
}

