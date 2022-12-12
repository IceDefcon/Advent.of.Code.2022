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
    int consecutive;
    string file_name;
    string folder_name;
    bool desired;
};


void process_line(string line, struct parameters * current_parameters)
{
    string cmd = "";
    cmd += line[2];
    cmd += line[3];

    static bool reset_position_y = false;
    static int file_size = 0;
    static int folder_size = 0;
    static string folder_name = "";
    static string file_name = "";

    if(cmd == "cd")
    {

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
            current_parameters->consecutive = 0;
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
            if((int)line[i] > 47 && (int)line[i] < 58) // file size
            {
                str = str + line[i];
            }
            else if(line[i] == 32) // file name
            {
                if((int)line[i-1] > 47 && (int)line[i-1] < 58)
                {
                    for(int j = i; j < line.length(); j++)
                    {
                        file_name = file_name + line[j + 1];
                    }

                    if(reset_position_y == true)
                    {
                        current_parameters->position_y = 0;
                        reset_position_y = false;
                    } 
                    else
                    {
                        current_parameters->position_y++;
                        current_parameters->consecutive++;
                    }
                }
                break;
            }
            else
            {
                file_name = "-1";
                file_size = -1;
            }
        }

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
    current_parameters.consecutive = 0;
    current_parameters.file_size = 0;
    current_parameters.file_name = "";
    current_parameters.folder_size = 0;
    current_parameters.folder_name = "";
    current_parameters.desired = false;

    string line;
    int objects = 0;
    ifstream line_count("data");
    while (getline (line_count, line)) objects++;

    struct parameters object_parameters[objects];
    for (int i = 0; i < objects; ++i)
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


    cout << endl << " ---====[ FINAL ]===----" << endl << endl; 

    for (int i = 0; i < objects; ++i)
    {
        cout 
        << " (" << object_parameters[i].position_x
        << ","  << object_parameters[i].position_y
        << ","  << object_parameters[i].file_size
        << ") " << endl;
    }

    //
    // Final Test
    //
    int desired = 100000;
    int desired_objects = 0;
    int depth = 0;
    int sum = 0;


    for (int i = 0; i < objects; ++i)
    {
        if(object_parameters[i].position_x > depth) depth = object_parameters[i].position_x;
    }

    cout << endl << "Max Depth:" << depth << endl;

    for (int i = 0; i < objects; ++i)
    {
        // if(object_parameters[i].position_x >= depth -1 && object_parameters[i].file_size != -1)
        if(object_parameters[i].file_size <= desired && object_parameters[i].file_size != -1)
        {
            cout << endl
            << " (" << object_parameters[i].position_x
            << ","  << object_parameters[i].position_y
            << ","  << object_parameters[i].folder_size
            << ","  << object_parameters[i].folder_name
            << ","  << object_parameters[i].file_size
            << ","  << object_parameters[i].file_name
            << ") ";
            
            object_parameters[i].desired = true;

            desired_objects++;
        } 
    }

    int j = 0;
    struct parameters desired_parameters[desired_objects];

    for (int i = 0; i < desired_objects; ++i)
    {
        desired_parameters[i].position_x = 0;
        desired_parameters[i].position_y = 0;
        desired_parameters[i].file_size = 0;
        desired_parameters[i].file_name = "";
        desired_parameters[i].folder_size = 0;
        desired_parameters[i].folder_name = "";
        desired_parameters[i].desired = false;
    }

    for (int i = 0; i < objects; ++i)
    {
        // if(object_parameters[i].position_x >= depth -1 && object_parameters[i].file_size != -1)
        if(object_parameters[i].desired == true)
        {
            desired_parameters[j] = object_parameters[i];
            j++;

        } 
    }

    cout << endl << endl << " ---====[ DESIRED ]===----" << endl; 

    for (int i = 0; i < desired_objects; ++i)
    {
            cout << endl
            << " ("  << desired_parameters[i].position_x
            << ","   << desired_parameters[i].position_y
            << ") (" << desired_parameters[i].consecutive
            << ") (" << desired_parameters[i].folder_size
            << ","   << desired_parameters[i].folder_name
            << ","   << desired_parameters[i].file_size
            << ","   << desired_parameters[i].file_name
            << ") ";

        if(desired_parameters[i+1].position_x == desired_parameters[i].position_x && desired_parameters[i+1].position_y == desired_parameters[i].position_y + 1)
        {
            cout << " " << sum;
            sum = sum + desired_parameters[i].file_size;
        }


    }

    cout << endl << endl << "Sum:" << sum << endl;

    cout << endl << " ---====[ END ]===----" << endl; 

    return 0;
}

