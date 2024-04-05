#include <iostream>

#define MAXSIZE 10

using namespace std;

class Stack
{
private:
    char stackArr[MAXSIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char value)
    {
        if (isFull())
        {
            cout << "Stekas pilnas." << value << "\n";
            return;
        }

        top++;
        stackArr[top] = value;
    }

    char topElement()
    {
        if (!isEmptyS())
        {
            return stackArr[top];
        }

        return -1;
    }

    void pop()
    {
        if (!isEmptyS())
        {
            top--;
        }
    }

    bool isEmptyS()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAXSIZE - 1;
    }
};

class Queue
{
private:
    int first, last;
    char qArr[MAXSIZE] = { 0 };

public:
    Queue()
    {
        first = -1;
        last = -1;
    }

    ~Queue()
    {
        clear();
    }

    void enqueue(char value)
    {
        if (isFull())
        {
            cout << "Dekas pilnas." << "\n";
            return;
        }
        else if (isEmpty())
        {
            first = 0;
            last = 0;
            qArr[last] = value;
        }
        else
        {
            last++;

            if (last == MAXSIZE)
            {
                last = 0;
            }

            qArr[last] = value;
        }
    }

    void dequeue()
    {
        if (isEmpty())
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

    void reverse()
    {
        if (isEmpty())
        {
            cout << "Eile tuscia, nera ko apsukti." << "\n";
            return;
        }

        Stack tempS;

        while (!isEmpty())
        {
            tempS.push(qArr[first]);
            dequeue();
        }

        while (!tempS.isEmptyS())
        {
            enqueue(tempS.topElement());
            tempS.pop();
        }
    }

    char front()
    {
        if (isEmpty())
        {
            cout << "Eile tuscia." << "\n";
            return -1;
        }

        return qArr[first];
    }

    char back()
    {
        if (isEmpty())
        {
            cout << "Eile tuscia." << "\n";
            return -1;
        }

        return qArr[last];
    }

    void clear()
    {
        first = -1;
        last = -1;
    }

    bool isFull()
    {
        return (last + 1 == first) || (last + 1 == MAXSIZE && first == 0);
    }

    bool isEmpty()
    {
        return first == -1 && last == -1;
    }
};

void display(Queue& queue)
{
    int size = 0;
    Queue tempQueue = queue;

    while (!tempQueue.isEmpty())
    {
        tempQueue.dequeue();
        size++;
    }

    while (size != 0)
    {
        char temp = queue.front();
        cout << temp << " ";
        queue.dequeue();
        queue.enqueue(temp);
        size--;
    }
}

int main()
{
    Queue q;
    q.enqueue('p');
    q.enqueue('k');
    q.enqueue('l');
    display(q);

    q.dequeue();
    cout << "\n";
    display(q);

    cout << "\n" << "REVERSE" << "\n";
    q.reverse();
    display(q);
};
