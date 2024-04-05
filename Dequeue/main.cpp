#include <iostream>

using namespace std;

#define MAXSIZE 10

class Deque
{
private:
    int first, last;
    int dequeArr[MAXSIZE] = {0};
public:
    Deque()
    {
        first = -1;
        last = -1;
    }
    
    ~Deque()
    {
        clear();
    }
    
    void pushBack(int value)
    {
        if(isFull())
        {
            cout << "Dekas pilnas." << "\n";
            return;
        }
        else if(isEmpty())
        {
            first = 0;
            last = 0;
            dequeArr[last] = value;
        }
        else
        {
            last++;
            
            if (last == MAXSIZE)
            {
                last = 0;
            }
            
            dequeArr[last] = value;
        }
    }
    
    void pushFront(int value)
    {
        if(isFull())
        {
            cout << "Dekas pilnas." << "\n";
            return;
        }
        else if(isEmpty())
        {
            first = 0;
            last = 0;
            dequeArr[first] = value;
        }
        else
        {
            first--;
            if (first < 0)
            {
                first = MAXSIZE - 1;
            }
            dequeArr[first] = value;
        }
    }
    
    void popFront()
    {
        if(isEmpty())
        {
            cout << "Dekas tuscias." << "\n";
            return;
        }
        
        if (first == last)
        {
            first = last = -1;
        }
        else
        {
            first++;
            
            if (first == MAXSIZE)
            {
                first = 0;
            }
        }
    }
    
    void popBack()
    {
        if(isEmpty())
        {
            cout << "Dekas tuscias." << "\n";
            return;
        }
        
        if (first == last)
        {
            first = last = -1;
        }
        else
        {
            last--;
            
            if(last < 0)
            {
                last = MAXSIZE - 1;
            }
        }
    }
    
    int front()
    {
        if(isEmpty())
        {
            cout << "Dekas tuscias." << "\n";
            return -1;
        }
        
        return dequeArr[first];
    }
    
    int back()
    {
        if(isEmpty())
        {
            cout << "Dekas tuscias." << "\n";
            return -1;
        }
        
        return dequeArr[last];
    }
    
    void clear()
    {
        first = last = -1;
    }
    
    bool isFull()
    {
        return (first == 0 && last == MAXSIZE -1) || (first == last + 1);
    }
    
    bool isEmpty()
    {
        return first == -1;
    }
};

void display(Deque& deque)
{
    Deque temp;
    
    while(!deque.isEmpty())
    {
        cout << deque.front() << " ";
        temp.pushBack(deque.front());
        deque.popFront();
    }
    
    while(!temp.isEmpty())
    {
        deque.pushBack(temp.front());
        temp.popFront();
    }
    
    cout << "\n" << "___________" << "\n";
}

void reverseDeq(Deque& deque)
{
    Deque temp;
    
    while(!deque.isEmpty())
    {
        temp.pushBack(deque.back());
        deque.popBack();
    }
    
    while(!temp.isEmpty())
    {
        deque.pushBack(temp.front());
        temp.popFront();
    }
}

int main()
{
    Deque d;
    
    d.pushBack(6);
    d.pushBack(3);
    d.pushBack(24);
    display(d);
    
    d.pushFront(7);
    d.pushFront(0);
    display(d);
    
    d.popBack();
    d.popFront();
    display(d);
    
    cout << "FRONT: " << d.front() << "\n";
    cout << "BACK: " << d.back() << "\n";
    
    reverseDeq(d);
    display(d);
    
    d.clear();
    display(d);
    
    return 0;
}
