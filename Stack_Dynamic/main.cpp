#include <iostream>

using namespace std;

struct node
{
    int data;
    node* prev;
};

class Stack
{
private:
    node* top;
    int sSize;
public:
    Stack()
    {
        top = NULL;
        sSize = 0;
    }
    
    ~Stack()
    {
        clear();
    }
    
    void push(int value)
    {
        node* newnode = new node;
        newnode->data = value;
        newnode->prev = top;
        top = newnode;
        sSize++;
    }
    
    void pop()
    {
        if(isEmpty())
        {
            cout << "Stekas tuscias" << "\n";
        }
        else
        {
            node* temp = top;
            top = top->prev;
            delete temp;
            sSize--;
        }
    }
    
    int topElement()
    {
        if(isEmpty())
        {
            cout << "Stekas tuscias" << "\n";
            return NULL;
        }
        else
        {
            return top->data;
        }
    }
    
    int size()
    {
        return sSize;
    }
    
    void clear()
    {
        while(!isEmpty())
        {
            pop();
        }
    }
    
    bool isEmpty()
    {
        return top == NULL;
    }
};

void display(Stack& stack)
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
    
    cout << "\n" << "___________" << "\n";
}

int main()
{
    Stack s;
    s.push(1);
    s.push(5);
    s.push(8);
    display(s);
    
    s.pop();
    display(s);
    
    cout << "Virsutinins elementas: " << s.topElement() << "\n";
    cout << "Elementu kiekis: " << s.size() << "\n";
    
    s.clear();
    display(s);
}
