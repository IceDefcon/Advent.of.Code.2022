

#include <iostream>
#include <sstream>
#include <string>
#include <fstream> 
#include <vector>

#include "stack.h"

using namespace std;

string number_str = "";
int number_int;

#define MAX 1000





int main(int argc, char const *argv[])
{

	ifstream file("data.h", ios::binary | ios::ate);
	streamsize size = file.tellg();
	file.seekg(0, ios::beg);

	vector<char> buffer(size);
	if (file.read(buffer.data(), size))
	{
		for (int i = 0; i < size; ++i)
		{
			cout << buffer[i];
			number_str += buffer[i];
			// if(buffer[i] == 10) break;
		}

		cout << endl << "New test" << endl;

		std::stringstream   data(number_str);
		data >> number_int;
		cout << number_int << endl;
	}

    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
   
    //print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;
   
    //print all elements in stack :
    cout <<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }
 
	return 0;
}
