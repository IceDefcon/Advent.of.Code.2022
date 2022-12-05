

#include <iostream>
#include <sstream>
#include <string>
#include <fstream> 
#include <vector>


using namespace std;

string number_str = "";
int number_int;

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



	return 0;
}
