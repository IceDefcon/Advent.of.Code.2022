#include <iostream>
#include "stack.h"

const char * init_stack_a[2] = {"Z","N"};
const char * init_stack_b[3] = {"M","C","D"};
const char * init_stack_c[1] = {"P"};

int amount[4] = {1,3,2,1};
int from[4]   = {2,1,2,1};
int to[4]     = {1,3,1,2};

int main(int argc, char const *argv[])
{

	cout << endl << "---==[ Process data ]==--- " << endl << endl; 

    class Stack s;

    for(int i = 0; i < sizeof(init_stack_a)/8 ; i++) s.push(init_stack_a[i],0);
    for(int i = 0; i < sizeof(init_stack_b)/8 ; i++) s.push(init_stack_b[i],1);
    for(int i = 0; i < sizeof(init_stack_c)/8 ; i++) s.push(init_stack_c[i],2);

    for(int x = 0; x < sizeof(amount)/4; x++)
    {
        for(int y = 0; y < amount[x]; y++)
        {
            const char * z = s.pop(from[x] - 1);
            s.push(z,to[x] - 1);
        }
    }

    for(int i = 0; i < 3; i++)
    {
	    cout << endl;
	    cout <<"Elements present in stack : ";
	    while(!s.isEmpty(i))
	    {
	        cout << s.peek(i) <<" ";
	        s.pop(i);
	    }
    }

	return 0;
}
