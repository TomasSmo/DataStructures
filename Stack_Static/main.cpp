#include <iostream>

using namespace std;

#define MAXSIZE 5

class Stack
{
private:
    int top;
    int arr[MAXSIZE];
public:
    Stack()
    {
        top = -1;
    }
    
    ~Stack()
    {
        clear();
    }
    
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stekas pilnas";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    
    void pop()
    {
        if(isEmpty())
        {
            cout << "Stekas tuscias";
        }
        else
        {
            top--;
        }
    }
    
    int topElement()
    {
        if(!isEmpty())
        {
            return arr[top];
        }
        else
        {
            return -1; //jeigu tuscias stekas -> returnina -1.
        }
    }
    
    void clear()
    {
        top = -1;
    }
    
    int size()
    {
        return top + 1;
    }
    
    bool isFull()
    {
        return top == MAXSIZE - 1;
    }
    
    bool isEmpty()
    {
        return top == -1;
    }
};


void display(Stack &stack)
{
    Stack temp;
    
    while(!stack.isEmpty())
    {
        cout << stack.topElement() << " ";
        temp.push(stack.topElement());
        stack.pop();
    }
    
    while(!temp.isEmpty())
    {
        stack.push(temp.topElement());
        temp.pop();
    }
    
    cout << "\n" << "____________" << "\n";
}


int main()
{
    Stack s;
    s.push(4);
    s.push(7);
    s.push(2);
    display(s);
    
    s.pop();
    display(s);
    
    cout << "\n" << "Virsutinis elementas: " << s.topElement() << "\n";
    cout << "Kiekis: " << s.size() << "\n";
    
    s.clear();
    display(s);
    
    return 0;
}
