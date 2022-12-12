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
	bool flag;
};


int main(int argc, char const *argv[])
{

    cout << endl << " ---====[ BEGIN ]===----" << endl << endl; 

    struct parameters current_parameters;
    current_parameters.x = 0;
    current_parameters.y = 0;
    current_parameters.z = 0;

    struct folder current_folder;
    current_folder.size = 0;
    current_folder.flag = false;

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
    struct folder folder[line_count];

    for (int i = 0; i < line_count; ++i)
    {
    	parameters[i].x = 0;
    	parameters[i].y = 0;
    	parameters[i].z = 0;
    	folder[i].size = 0;
    	folder[i].flag = false;
    }

    line_count = 0;
	static int folder_size = 0;

    static string str ="";
    static string line = "";
	ifstream MyReadFile("data");

	int previous_size = 0;
	int current_size = 0;

	cout << "(x,y,z,size)" << " line "<< endl;
    while (getline (MyReadFile, line)) 
    {
	    string cmd = "";
	    cmd += line[2];
	    cmd += line[3];

    	if(cmd == "cd" && line[5] == 47) // main ---> cd /
    	{
    		cout << " main ";
    		current_parameters.x = 0;
			current_parameters.y = 0;
    	}
    	else if(cmd == "cd"  && line[5] > 96 && line[5] < 123) // up ---> cd any
    	{
    		cout << "  up  ";
    		current_parameters.x++;
    		current_parameters.z++;
    		current_folder.size = 0; // clear folder size ---> goint up
    	}
    	else if(cmd == "cd"  && line[5] == 46) // down ---> cd ..
    	{
    		cout << " down ";
    		current_parameters.x--;
    		current_folder.size = 0; // clear folder size ---> goint down
    	}
		else if((int)line[0] > 47 && (int)line[0] < 58) // file size on front
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
    		current_parameters.y++;
    		current_folder.size = current_folder.size + folder_size;
		}
		else if(line[0] == 100)
		{
			cout << " none ";
		}
		else
		{
			cout << " none ";
			current_parameters.y = 0;
		}

		cout
		<< "("  << current_parameters.x 
		<< ","  << current_parameters.y 
		<< ","  << current_parameters.z 
		<< ","  << current_folder.size
		<< ") " << line << endl;

    	parameters[line_count].x = current_parameters.x ;
    	parameters[line_count].y = current_parameters.y ;
    	parameters[line_count].z = current_parameters.z ;
    	folder[line_count].size = current_folder.size;
    	folder[line_count].flag = current_folder.flag;

    	//
    	// Flag check
    	//
    	previous_size = folder[line_count - 1].size;
    	current_size = folder[line_count].size;

    	if(current_size > previous_size || (current_size == previous_size && current_size > 0 && previous_size > 0))
    	{
    		folder[line_count - 1].flag = false;
    		folder[line_count].flag = true;
    	} 
    	else folder[line_count].flag = false;

    	line_count++;
    }

    cout << endl << " ---====[ FINAL ]===----" << endl << endl; 

    cout << "(x,y,z,size)" << endl;
    for (int i = 0; i < line_count; ++i)
    {
		cout
		<< "("   << folder[i].flag
		<< ")("  << parameters[i].x
		<< ","   << parameters[i].y
		<< ","   << parameters[i].z
		<< ","   << folder[i].size
		<< ") "  << endl;
	}

	cout << endl << " ---====[ DESIRED ]===----" << endl << endl; 

	int flag_count = 0;

	for (int i = 0; i < line_count; ++i)
	{
		if(folder[i].flag == true && folder[i].size <= 100000)
		{
			cout
			<< "("   << folder[i].flag
			<< ")("  << parameters[i].x
			<< ","   << parameters[i].y
			<< ","   << parameters[i].z
			<< ","   << folder[i].size
			<< ") "  << endl;

			flag_count++;
		}
	}

	struct parameters flaged_parameters[flag_count];
	struct folder flaged_folder[line_count];
	int temp_flag = 0;
	for (int i = 0; i < flag_count; ++i)
	{
    	parameters[i].x = 0;
    	parameters[i].y = 0;
    	parameters[i].z = 0;
    	folder[i].size = 0;
    	folder[i].flag = false;
	}

	for (int i = 0; i < line_count; ++i)
	{
		if(folder[i].flag == true && folder[i].size <= 100000)
		{
			flaged_parameters[temp_flag] = parameters[i];
			flaged_folder[temp_flag] = folder[i];
			temp_flag++;
		}
	}

	cout << endl << " ---====[ FLAGED ]===----" << endl << endl; 

	for (int i = 0; i < flag_count; ++i)
	{
		cout
		<< "("   << flaged_folder[i].flag
		<< ")("  << flaged_parameters[i].x
		<< ","   << flaged_parameters[i].y
		<< ","   << flaged_parameters[i].z
		<< ","   << flaged_folder[i].size
		<< ") "  << endl;
	}

	cout << endl << " ---====[ TOTAL SIZE ]===----" << endl << endl; 

	cout << "Desired length ---> " << current_size << endl << endl;


	return 0;
}