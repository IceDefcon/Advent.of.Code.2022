#include <iostream>
#include <fstream>
#include <sstream>
#include "file.h"


#define desired 100000

struct parameters
{
	int x;
	int y;
	int dir;
	int file;
	int size;
};

int main(int argc, char const *argv[])
{
	cout << endl << " ---====[ BEGIN ]====--- " << endl << endl;

	struct parameters current_parameters;
	current_parameters.x = 0;
	current_parameters.y = 0;
	current_parameters.dir = 0;
	current_parameters.file = 0;
	current_parameters.size = 0;

	static int folder_size = 0;
	static string str = "";
	static bool ls_flag = false;
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
	    	current_parameters.x = 0;
	    }
	    else if(cmd == "$ cd"  && buffer[5] > 96 && buffer[5] < 123)
	    {
	    	//
	    	// UP
	    	//
	    	current_parameters.x++;
	    }
	    else if(cmd == "$ cd"  && buffer[5] == 46) 
	    {
	    	//
	    	// DOWN
	    	//
	    	current_parameters.y++;
	    }
	    else if(cmd == "$ ls")
	    {
	    	current_parameters.dir = 0;
	    	current_parameters.file = 0;
	    	ls_flag = true;
	    }
	    else if(ls_flag == true)
	    {
	    	if(cmd == "dir ")
	    	{
	    		current_parameters.dir++;
	    	}
	    	else if((int)buffer[0] > 47 && (int)buffer[0] < 58)
	    	{
				str = "";
				folder_size = 0;
		        for(int i = 0;;i++)
		        {
		        	//
					// file
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

	    		current_parameters.size = current_parameters.size + folder_size;
	    	}
	    }
    }






	return 0;
}