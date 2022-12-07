#include <iostream>
#include <fstream>
#include "file.h"

#define distinct 14

int main(int argc, char const *argv[])
{
    int length = 0;
    vector<char> data = read_file("data", &length);

    int check = 0;
    for (int i = distinct - 1; i > 0; --i) for (int j = 0; j < i; ++j) check++;

    for(int x = 0; x < length; x++)
    {
        char a[distinct];

        for(int y = 0; y < distinct; y++)
        {
            a[y] = data[y + x];
        }

        int count = 0;

        int base = 0;

        for (int i = distinct - 1; i > 0; --i)
        {

            for (int j = 0; j < i; ++j)
            {
                if(a[base] != a[j+1+base]) 
                {
                    count++;
                }
                else 
                {
                    count = 0;
                }

                if(count == check) 
                {
                    cout << "Marker at character ---> " << x + distinct << endl;
                    return 0;
                }
            }

            base = base + 1;

        }

    }

    return 0;
}



