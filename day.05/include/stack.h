
#include <bits/stdc++.h>

#define MAX 1000

class Stack {
    int top;
 
public:
    int a[MAX]; // Maximum size of Stack
    int b[MAX]; // Maximum size of Stack
    int c[MAX]; // Maximum size of Stack
 
 	Stack();
	~Stack();

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};