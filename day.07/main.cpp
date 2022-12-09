#include <iostream>
#include <fstream>
#include <sstream>
#include "file.h"

#define ASCII_OFFSET 48

struct parameters
{
    int current_x;
    int current_y;
    int current_z;
    int current_file_size;
    int current_folder_size;
    string current_file_name;
    string current_folder_name;
};

struct folder
{
    int folder_x;
    int folder_y;
    int folder_z;
    int folder_size;
    string folder_name;
};

struct file
{
    int file_x;
    int file_y;
    int file_z;
    int file_size;
    string file_name;
    folder folder;
};


//
// This is only valid if the same files and folders are not printed printed again
//
void init(int *files, int *folders)
{
    string text;
    ifstream MyReadFile("data");

    while (getline (MyReadFile, text)) 
    {
        for(int i = 0;;)
        {
            if((int)text[0] > 47 && (int)text[0] < 58)
            {
                *files += 1;
                break;
            }
            else break;
        }

        for(;;)
        {
            if(text[0] == 100 && text[1] == 105 && text[2] == 114)
            {
                *folders += 1;
                break;
            }
            else break;
        }

    }
}

void command(string data, bool * skip, struct parameters * current_parameters)
{

    static string str = "";
    static int length = 0;

    if(data[2] == 99)                                               // cd
    {
        if(data[5] == 47)                                           // main
        {
            str = "";
            current_parameters->current_y = 0;
            str = "/";
            length = str.length();
            current_parameters->current_folder_size = length;
            current_parameters->current_folder_name = str;
        }
        else if(data[5] == 46)                                     // down
        {
            str = "";
            current_parameters->current_y--;
            length = str.length();
            current_parameters->current_folder_size = length;
            current_parameters->current_folder_name = str;
        }
        else                                                        // up
        {
            str = "";
            current_parameters->current_y++;

            for(int i = 5;;i++)
            {

                if(data[i] > 96 && data[i] < 123)
                {
                    str = str + data[i];
                }
                else break;
            }
            length = str.length() - length;
            current_parameters->current_folder_size = length;
            current_parameters->current_folder_name = str;
        }
    } 
    else                                                            // ls
    {
        length = str.length();
        current_parameters->current_folder_size = length;
        current_parameters->current_folder_name = str;
    }

    *skip = false;
}

int main(int argc, char const *argv[])
{
    int files = 0;
    int folders = 0;
    init(&files, &folders);

    // Must add main folder
    folders += 1;

    int current_object = 0;
    int next = 0;

    struct parameters current_parameters;
    current_parameters.current_x = 0;
    current_parameters.current_y = 0;
    current_parameters.current_z = 0;
    current_parameters.current_file_size = 0;
    current_parameters.current_folder_size = 0;
    current_parameters.current_file_name = "";
    current_parameters.current_folder_name = "";

    struct file file_object[files];
    for (int i = 0; i < files; ++i)
    {
        file_object[i].file_x = 0;
        file_object[i].file_y = 0;
        file_object[i].file_z = 0;
        file_object[i].file_size = 0;
        file_object[i].file_name = "";
        file_object[i].folder.folder_x = 0;
        file_object[i].folder.folder_y = 0;
        file_object[i].folder.folder_z = 0;
        file_object[i].folder.folder_size = 0;
        file_object[i].folder.folder_name = "";
    }

    string text;
    ifstream MyReadFile("data");

    bool skip = false;

    while (getline (MyReadFile, text)) 
    {
        if(text[0] == 36) 
        {
            command(text, &skip, &current_parameters);  // $
            cout << text << endl;
        }

        if(skip == false) next = 0;
        //
        // Read data
        //
        if(skip) 
        {
            int num;
            string str = "";
            for(int i = 0;;i++)
            {
                if((int)text[i] > 47 && (int)text[i] < 58)
                {
                    str = str + text[i];

                }
                else break;
            }
            
            if(text[0] == 100)
            {
                cout << "    " << text << endl;
            }
            else
            {

                stringstream ss;
                ss << str;  
                ss >> num; 
                cout << text << endl;
                
                file_object[current_object].file_y = current_parameters.current_y;
                file_object[current_object].file_z = current_parameters.current_z + next;
                file_object[current_object].file_size = num;
                file_object[current_object].folder.folder_size = current_parameters.current_folder_size;
                file_object[current_object].folder.folder_name = current_parameters.current_folder_name;
                current_object++;
                next++;
            }

        }
        skip = true;
    }

    cout << endl << " ---==[ Final ]==--- " << endl << endl;

    for (int i = 0; i < files; ++i)
    {
        cout << "folder_size " << file_object[i].folder.folder_size << " folder_name " << file_object[i].folder.folder_name << " file_object "<< i << " file_x " << file_object[i].file_x << " file_y " << file_object[i].file_y << " file_z " << file_object[i].file_z << " file_size " << file_object[i].file_size << endl;
    }


    int test_1 = 0;
    for (int i = 0; i < files; ++i)
    {
        if(file_object[i].folder.folder_name == "a" || file_object[i].folder.folder_name == "a") test_1 += file_object[i].file_size;
    }

    cout << endl << " ---==[ " << test_1 << " ]==--- " << endl;

    return 0;
}

