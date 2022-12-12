#include <iostream>
#include <fstream>
#include <sstream>
#include "file.h"





struct parameters
{
	int x;
	int size;
	int amount;
	bool flag;
	string name;
};



int main(int argc, char const *argv[])
{

	struct parameters current_parameters;
	current_parameters.x = 0;
	current_parameters.size = 0;
	current_parameters.amount = 0;
	current_parameters.flag = false;
	current_parameters.name = "";

    //
    // Line count
    //
    static string count_buffer = "";
	static int line_count = 0;
	ifstream file_1("data");
    while (getline (file_1, count_buffer)) 
    {
    	line_count++;
    }

    struct parameters folder_parameters[line_count];
    for (int i = 0; i < line_count; ++i)
    {
		folder_parameters[i].x = 0;
		folder_parameters[i].size = 0;
		folder_parameters[i].amount = 0;
		folder_parameters[i].flag = 0;
		folder_parameters[i].name = "";
    }

    static string folder_name = "";
	static int previous_size = 0;
	static int current_size = 0;
	static int count = 0;
	static string str = "";
	static int folder_size = 0;
	static int amount = 0;
    static string buffer = "";
	ifstream file_2("data");
    while (getline (file_2, buffer)) 
    {
	    string cmd = "";
	    cmd += buffer[0];
	    cmd += buffer[1];
	    cmd += buffer[2];
	    cmd += buffer[3];

	    if(cmd == "$ cd"  && buffer[5] == 47) // MAIN
	    {
	    	current_parameters.x = 0;
	    	current_parameters.name = "/";
	    }
	    else if(cmd == "$ cd"  && buffer[5] > 96 && buffer[5] < 123) // UP
	    {
	    	current_parameters.x++;
	    	current_parameters.size = 0;
	    	current_parameters.amount = 0;
    		
    		folder_name = "";
            for(int i = 5;;i++) // $ cd xxxx
            {
                if(buffer[i] > 96 && buffer[i] < 123)
                {
                    folder_name = folder_name + buffer[i];
                }
                else break;
            }

            current_parameters.name = folder_name;
	    }
	    else if(cmd == "$ cd"  && buffer[5] == 46) // DOWN
	    {
	    	current_parameters.x--;
	    	current_parameters.size = 0;
	    	current_parameters.amount = 0;
	    }
	    else if(cmd == "$ ls")
	    {

	    }
		else if((int)buffer[0] > 47 && (int)buffer[0] < 58) // folder size
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
	    else if(cmd == "dir ")
	    {
	    	current_parameters.amount++;
	    }

	    cout
	    << " (" << current_parameters.flag
	    << ")(" << current_parameters.x
	    << ", " << current_parameters.amount
	    << ", " << current_parameters.size
	    << ", " << current_parameters.name
	    << ") " << buffer << endl;

		folder_parameters[count] = current_parameters;

    	//
    	// Flag check + amount of other folders
    	//
    	previous_size = folder_parameters[count - 1].size;
    	current_size = folder_parameters[count].size;

    	if(buffer[5] != 47 && (current_size > previous_size || (current_size == previous_size && current_size > 0 && previous_size > 0)))
    	{
    		folder_parameters[count - 1].flag = false;
    		folder_parameters[count].flag = true;
    		folder_parameters[count].amount = current_parameters.amount;
    	} 
    	else folder_parameters[count].flag = false;

	    count++;

    }

    cout << endl << " ---====[ FINAL ]====--- " << endl << endl;

    static int total = 0;
    for (int i = 0; i < count; ++i)
    {
    	if(folder_parameters[i].flag == true && folder_parameters[i].size <= 100000)
    	{
		    cout
		    << " ("  << folder_parameters[i].amount
		    << ") (" << folder_parameters[i].x
		    << ") (" << folder_parameters[i].size
		    << ","   << folder_parameters[i].name
		    << ") "  << endl;

		    total = total + folder_parameters[i].size;
    	}

    }

    cout << endl << " ---====[ " << total << " ]====--- " << endl << endl;

	return 0;
}