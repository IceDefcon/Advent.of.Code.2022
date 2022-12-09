#include <iostream>
#include <fstream>
#include "file.h"




void command(string line)
{
    string cmd = "";
    cmd += line[2];
    cmd += line[3];

    cout << cmd  << endl;
    if(cmd == "cd")
    {
        
    } 
    if(cmd == "ls")
    {
        
    }

}




int main(int argc, char const *argv[])
{

    int files = 0;
    int folders = 0;
    init(&files, &folders);

    string line;
    ifstream MyReadFile("data");

    bool skip = false;

    cout << endl;
    while (getline (MyReadFile, line)) 
    {


        if(line[0] == 36) command(line);  // $ command

    }
    return 0;
}

