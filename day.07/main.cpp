#include <iostream>
#include <fstream>
#include <sstream>
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


void process_line(string line, struct parameters * current_parameters)
{
    string cmd = "";
    cmd += line[2];
    cmd += line[3];

    static bool reset_position_y = false;
    static bool read_file_name = false;
    static int file_size = 0;
    static int folder_size = 0;
    static string folder_name = "";
    static string file_name = "";

    if(cmd == "cd")
    {
        current_parameters->position_y = 0;

        if(line[5] == 47) // main
        {
            folder_name = "/";
            folder_size = folder_name.length();
            current_parameters->position_x = 0;
            current_parameters->position_y = 0;
            current_parameters->file_name = "-1";
            current_parameters->file_size = -1;
            current_parameters->folder_size = folder_size;
            current_parameters->folder_name = folder_name;
        }
        else if(line[5] == 46) // down
        {
            folder_size = folder_name.length();
            current_parameters->position_x--;
            current_parameters->file_name = "-1";
            current_parameters->file_size = -1;
            current_parameters->folder_size = folder_size;
            current_parameters->folder_name = folder_name;
        }
        else // up
        {
            folder_name = "";
            for(int i = 5;;i++)
            {

                if(line[i] > 96 && line[i] < 123)
                {
                    folder_name = folder_name + line[i];
                }
                else break;
            }

            folder_size = folder_name.length();
            current_parameters->position_x++;
            current_parameters->file_name = "-1";
            current_parameters->file_size = -1;
            current_parameters->folder_size = folder_size;
            current_parameters->folder_name = folder_name;
        }
    } 
    else if(cmd == "ls")
    {
        reset_position_y = true;
    }
    else // Read objects in folder
    {

        file_size = 0;
        string str = "";
        string file_name = "";
        for(int i = 0;;i++)
        {
            if((int)line[i] > 47 && (int)line[i] < 58)
            {
                str = str + line[i];
            }
            else if(line[i] == 32)
            {
                if((int)line[i-1] > 47 && (int)line[i-1] < 58)
                {
                    for(int j = i; j < line.length(); j++)
                    {
                        file_name = file_name + line[j + 1];
                    }
                }
                read_file_name = true;
                break;
            }
            else
            {
                file_name = "-1";
                file_size = -1;
            }
        }

        if(reset_position_y == true)
        {
            current_parameters->position_y = 0;
            reset_position_y = false;
        }
        else current_parameters->position_y++;

        stringstream ss;
        ss << str;  
        ss >> file_size; 
        current_parameters->file_size = file_size;
        current_parameters->file_name = file_name;
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
    int lines = 0;
    ifstream line_count("data");
    while (getline (line_count, line)) lines++;

    struct parameters object_parameters[lines];
    for (int i = 0; i < lines; ++i)
    {
        object_parameters[i] = current_parameters;
    }
    
    ifstream MyReadFile("data");

    cout << endl << " ---====[ BEGIN ]===----" << endl << endl; 

    while (getline (MyReadFile, line)) 
    {

        static int i = 0;
        if(line[0] == 36)
        {
            process_line(line, &current_parameters);  // $ process command ---> $
            cout
            << " (" << current_parameters.position_x
            << ","  << current_parameters.position_y
            << ","  << current_parameters.folder_size
            << ","  << current_parameters.folder_name
            << ","  << current_parameters.file_size
            << ","  << current_parameters.file_name
            << ") " << line << endl;
        }
        else
        {
            process_line(line, &current_parameters);  // $ process read
            cout
            << " (" << current_parameters.position_x
            << ","  << current_parameters.position_y
            << ","  << current_parameters.folder_size
            << ","  << current_parameters.folder_name
            << ","  << current_parameters.file_size
            << ","  << current_parameters.file_name
            << ") " << line << endl;
        }

        object_parameters[i] = current_parameters;
        i++;
    }

    for (int i = 0; i < lines; ++i)
    {
        cout 
        << " (" << object_parameters[i].position_x
        << ","  << object_parameters[i].position_y
        << ","  << object_parameters[i].file_size
        << ") " << endl;
    }

    cout << endl << " ---====[ FINAL ]===----" << endl << endl; 





    cout << endl << " ---====[ END ]===----" << endl; 

    return 0;
}

