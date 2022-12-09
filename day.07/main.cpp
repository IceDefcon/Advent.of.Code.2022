#include <iostream>
#include <fstream>
#include "file.h"

struct parameters
{
    int position_x;
    int position_y;
    int file_size;
    int folder_size;
    string file_name;
    string folder_name;
};


void command(string line, struct parameters * current_parameters)
{
    string cmd = "";
    cmd += line[2];
    cmd += line[3];

    static string str = "";
    static int length = 0;

    if(cmd == "cd")
    {
        if(line[5] == 47) // main
        {
            str = "/";
            length = str.length();
            current_parameters->position_x = 0;
            current_parameters->position_y = 0;
            current_parameters->folder_size = length;
            current_parameters->folder_name = str;
        }
        else if(line[5] == 46) // down
        {
            length = str.length();
            current_parameters->position_x--;
            current_parameters->folder_size = length;
            current_parameters->folder_name = str;
        }
        else // up
        {
            str = "";
            for(int i = 5;;i++)
            {

                if(line[i] > 96 && line[i] < 123)
                {
                    str = str + line[i];
                }
                else break;
            }

            length = str.length();
            current_parameters->position_x++;
            current_parameters->folder_size = length;
            current_parameters->folder_name = str;
        }
    } 
    else if(cmd == "ls")
    {
        //
    }

}

int main(int argc, char const *argv[])
{

    struct parameters current_parameters;
    current_parameters.position_x = 0;
    current_parameters.position_y = 0;
    current_parameters.file_size = 0;
    current_parameters.file_name = "";
    current_parameters.folder_size = 0;
    current_parameters.folder_name = "";

    string line;
    ifstream MyReadFile("data");

    cout << endl;
    while (getline (MyReadFile, line)) 
    {

        if(line[0] == 36)
        {
            command(line, &current_parameters);  // $ command
            cout
            << " 0 "
            << " (" << current_parameters.position_x
            << ","  << current_parameters.position_y
            << ","  << current_parameters.folder_size
            << ","  << current_parameters.folder_name
            << ") " << line << endl;
        }
        else
        {
            command(line, &current_parameters);  // $ command
            cout
            << " 1 "
            << " (" << current_parameters.position_x
            << ","  << current_parameters.position_y
            << ","  << current_parameters.folder_size
            << ","  << current_parameters.folder_name
            << ") " << line << endl;
        }


    }
    return 0;
}

