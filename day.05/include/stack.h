
#include <bits/stdc++.h>

using namespace std;

#define MAX 128

class Stack {
    int top[9];
 
public:
    const char * a[MAX];
    const char * b[MAX];
    const char * c[MAX];
    const char * d[MAX];
    const char * e[MAX];
    const char * f[MAX];
    const char * g[MAX];
    const char * h[MAX];
    const char * i[MAX];
 
 	Stack();
	~Stack();

    bool push(const char * x,int y);
    const char * pop(int y);
    const char * peek(int y);
    bool isEmpty(int y);
};