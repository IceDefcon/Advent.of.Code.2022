#include <iostream>
#include <fstream>
#include <sstream>
#include "file.h"


#define desired 100000

struct parameters
{
	int n;
	int x;
	int dir;
	int file;
	int size;
	bool flag;
};

int main(int argc, char const *argv[])
{
	cout << endl << " ---====[ BEGIN ]====--- " << endl << endl;

	static int dir_count = 0;
	static int line_count = 0;
    static string line_buffer = "";
	ifstream line_file("data");
    while (getline (line_file, line_buffer)) 
    {
	    string cmd = "";
	    cmd += line_buffer[0];
	    cmd += line_buffer[1];
	    cmd += line_buffer[2];
	    cmd += line_buffer[3];

	    if(cmd == "dir ")
	    {
	    	dir_count++;
	    }

	    line_count++;

    }

    struct parameters dir_parameters[dir_count];
    for (int i = 0; i < dir_count; ++i)
    {
    	dir_parameters[i].n = 0;
		dir_parameters[i].x = 0;
		dir_parameters[i].dir = 0;
		dir_parameters[i].file = 0;
		dir_parameters[i].size = 0;
		dir_parameters[i].flag = false;
    }

    struct parameters line_parameters[line_count];
    for (int i = 0; i < line_count; ++i)
    {
    	line_parameters[i].n = 0;
		line_parameters[i].x = 0;
		line_parameters[i].dir = 0;
		line_parameters[i].file = 0;
		line_parameters[i].size = 0;
		line_parameters[i].flag = false;
    }

	struct parameters current_parameters;
	current_parameters.n = 0;
	current_parameters.x = 0;
	current_parameters.dir = 0;
	current_parameters.file = 0;
	current_parameters.size = 0;
	current_parameters.flag = false;

	struct parameters previous_parameters;
	previous_parameters.n = 0;
	previous_parameters.x = 0;
	previous_parameters.dir = 0;
	previous_parameters.file = 0;
	previous_parameters.size = 0;
	previous_parameters.flag = false;

	static int folder_size = 0;
	static string str = "";
    static string buffer = "";
    ifstream file("data");
    while (getline (file, buffer)) 
    {
	    string cmd = "";
	    cmd += buffer[0];
	    cmd += buffer[1];
	    cmd += buffer[2];
	    cmd += buffer[3];

	    if(cmd == "$ cd"  && buffer[5] == 47)
	    {
	    	//
	    	// MAIN
	    	//
	    	cout << " MAIN ";
	    	current_parameters.x = 0;
	    }
	    else if(cmd == "$ cd"  && buffer[5] > 96 && buffer[5] < 123)
	    {
	    	//
	    	// UP
	    	//
	    	cout << "  UP  ";
	    	current_parameters.x++;
	    	current_parameters.dir = 0;
	    	current_parameters.file = 0;
	    	current_parameters.size = 0;
	    }
	    else if(cmd == "$ cd"  && buffer[5] == 46) 
	    {
	    	//
	    	// DOWN
	    	//
	    	cout << " DOWN ";
	    	current_parameters.x--;
	    	current_parameters.dir = 0;
	    	current_parameters.file = 0;
	    	current_parameters.size = 0;	    	
	    }
	    else if(cmd == "$ ls")
	    {
	    	cout << "  LS  ";
	    }
	    else if(cmd == "dir ")
    	{
    		cout << " FOLD ";
    		current_parameters.dir++;
    	}
    	else if((int)buffer[0] > 47 && (int)buffer[0] < 58)
    	{
    		cout << " FILE ";
			str = "";
			folder_size = 0;
	        for(int i = 0;;i++)
	        {
	        	//
				// One file
				//
	            if((int)buffer[i] > 47 && (int)buffer[i] < 58)
	            {
	                str = str + buffer[i];
	            }
	            else break;
	        }

	        stringstream ss;
	        ss << str;  
	        ss >> folder_size; 

	        current_parameters.file++;
	        current_parameters.size = current_parameters.size + folder_size;
    	}

    	line_parameters[current_parameters.n] = current_parameters;

    	if
    	(
    		buffer[5] != 47 && 
			(
				line_parameters[current_parameters.n].size >= line_parameters[current_parameters.n - 1].size || 
				(
					line_parameters[current_parameters.n].size == line_parameters[current_parameters.n - 1].size && 
					line_parameters[current_parameters.n].size > 0 && 
					line_parameters[current_parameters.n - 1].size > 0
				)
			)
		)
    	{
    		line_parameters[current_parameters.n - 1].flag = false;
    		line_parameters[current_parameters.n].flag = true;
    		line_parameters[current_parameters.n].dir = current_parameters.dir;
    	} 
    	else if(line_parameters[current_parameters.n].size == 0 && line_parameters[current_parameters.n].dir > 0) line_parameters[current_parameters.n].flag = true;
    	else line_parameters[current_parameters.n].flag = false;

    	current_parameters.flag = line_parameters[current_parameters.n].flag;
    	cout
    	<< "  F:" << current_parameters.flag
    	<< "  X:" << current_parameters.x
    	<< "  D:" << current_parameters.dir
    	<< "  F:" << current_parameters.file
    	<< "  S:" << current_parameters.size
    	<< "            " << buffer << endl;

    	current_parameters.n++;
    }

    line_parameters[current_parameters.n] = current_parameters;

	// cout << endl << " ---====[ PARAMETERS ]====--- " << endl << endl;

	static bool dir_flag = false;
    for (int i = 0; i < line_count; ++i)
    {
    	// cout
    	// << " F:" << line_parameters[i].flag
    	// << " N:" << line_parameters[i].n
    	// << " X:" << line_parameters[i].x
    	// << " D:" << line_parameters[i].dir
    	// << " F:" << line_parameters[i].file
    	// << " S:" << line_parameters[i].size
    	// << endl;

    }

	cout << endl << " ---====[ UPDATED ]====--- " << endl << endl;

    for (int i = 0; i < line_count; ++i)
    {
    	cout
    	<< "  F:" << line_parameters[i].flag
    	<< "  X:" << line_parameters[i].x
    	<< "  D:" << line_parameters[i].dir
    	<< "  F:" << line_parameters[i].file
    	<< "  S:" << line_parameters[i].size
    	<< endl;
    }

	// cout << endl << " ---====[ FINAL ]====--- " << endl << endl;

    // for (int i = 0; i < line_count; ++i)
    // {
    // 	if(line_parameters[i].flag == 1 && line_parameters[i].size < 100000)
    // 	{
    // 		cout
	//     	<< "  F:" << line_parameters[i].flag
	//     	<< "  X:" << line_parameters[i].x
	//     	<< "  D:" << line_parameters[i].dir
	//     	<< "  F:" << line_parameters[i].file
	//     	<< "  S:" << line_parameters[i].size
	//     	<< endl;
    // 	}
    // }

	return 0;
}