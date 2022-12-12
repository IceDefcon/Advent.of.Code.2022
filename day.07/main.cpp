#include <iostream>
#include <fstream>
#include <sstream>
#include "file.h"



struct parameters
{
	int x;
	int y;
	int z;
};

struct folder
{
	int size;
	string name;
};


int main(int argc, char const *argv[])
{

    cout << endl << " ---====[ BEGIN ]===----" << endl << endl; 

    struct parameters current_parameters;
    current_parameters.x = 0;
    current_parameters.y = 0;
    current_parameters.z = 0;

    //
    // Line count
    //
    static string temp = "";
	static int line_count = 0;
	ifstream linec_count("data");
    while (getline (linec_count, temp)) 
    {
    	line_count++;
    }

    //
    // Init structres
    //
    struct parameters parameters[line_count];
    struct folder folders[line_count];

    for (int i = 0; i < line_count; ++i)
    {
    	parameters[i].x = 0;
    	parameters[i].y = 0;
    	parameters[i].z = 0;
    	folders[i].size = 0;
    	folders[i].name = "";
    }

	static int folder_size = 0;
	static int folder_count = 0;

    static string str ="";
    static string line = "";
	ifstream MyReadFile("data");
    while (getline (MyReadFile, line)) 
    {
	    string cmd = "";
	    cmd += line[2];
	    cmd += line[3];

    	if(cmd == "cd" && line[5] == 47)
    	{
    		cout << " main ";
    		current_parameters.x = 0;
			current_parameters.y = 0;
    	}
    	else if(cmd == "cd"  && line[5] > 96 && line[5] < 123)
    	{
    		cout << "  up  ";
    		current_parameters.x++;
    		folder_count++;
    	}
    	else if(cmd == "cd"  && line[5] == 46)
    	{
    		cout << " down ";
    		current_parameters.x--;
    	}
		else if((int)line[0] > 47 && (int)line[0] < 58)
		{
			str = "";
			folder_size = 0;

	        for(int i = 0;;i++)
	        {
	            if((int)line[i] > 47 && (int)line[i] < 58) // file size
	            {
	                str = str + line[i];
	            }
	            else break;
	        }

	        stringstream ss;
	        ss << str;  
	        ss >> folder_size; 

    		cout << " file ";
		}
		else
		{
			cout << " none ";
		}

		cout
		<< "(" << folder_count 
		<< ")(" << current_parameters.x 
		<< ","  << current_parameters.y 
		<< ","  << current_parameters.z 
		<< ") " << line << endl;
    }

	return 0;
}