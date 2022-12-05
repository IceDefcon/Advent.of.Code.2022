


#include "stack.h"



Stack::Stack()
{
	top[0] = -1;
    top[1] = -1;
    top[2] = -1;
    top[3] = -1;
    top[4] = -1;
    top[5] = -1;
    top[6] = -1;
    top[7] = -1;
    top[8] = -1;
}

Stack::~Stack()
{

}


bool Stack::push(const char * x,int y)
{
    if (top[y] >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        if(y == 0) a[++top[y]] = x;
        if(y == 1) b[++top[y]] = x;
        if(y == 2) c[++top[y]] = x;
        if(y == 3) d[++top[y]] = x;
        if(y == 4) e[++top[y]] = x;
        if(y == 5) f[++top[y]] = x;
        if(y == 6) g[++top[y]] = x;
        if(y == 7) h[++top[y]] = x;
        if(y == 8) i[++top[y]] = x;
        cout << x << " pushed into stack " << y << endl;
        return true;
    }
}
 
const char * Stack::pop(int y)
{
    if (top[y] < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        const char * x;
        if(y == 0) x = a[top[y]--];
        if(y == 1) x = b[top[y]--];
        if(y == 2) x = c[top[y]--];
        if(y == 3) x = d[top[y]--];
        if(y == 4) x = e[top[y]--];
        if(y == 5) x = f[top[y]--];
        if(y == 6) x = g[top[y]--];
        if(y == 7) x = h[top[y]--];
        if(y == 8) x = i[top[y]--];
        return x;
    }
}

const char * Stack::peek(int y)
{
    if (top[y] < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        const char * x;
        if(y == 0) x = a[top[y]];
        if(y == 1) x = b[top[y]];
        if(y == 2) x = c[top[y]];
        if(y == 3) x = d[top[y]];
        if(y == 4) x = e[top[y]];
        if(y == 5) x = f[top[y]];
        if(y == 6) x = g[top[y]];
        if(y == 7) x = h[top[y]];
        if(y == 8) x = i[top[y]];
        return x;
    }
}
 
bool Stack::isEmpty(int y)
{
    return (top[y] < 0);
}

