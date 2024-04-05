#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

class bidirectionalLinkedList
{
private:
    node* head;
    node* tail;
    node* pre;
    node* nxt;
    node* cur;
public:
    bidirectionalLinkedList()
    {
        head = NULL;
        tail = NULL;
        cur = NULL;
        pre = NULL;
        nxt = NULL;
    }
    
    ~bidirectionalLinkedList()
    {
        clear();
    }
    
void addNodeStart(int value)
{
    node* temp = new node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
        
    if (isEmpty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
    
void addNodeEnd(int value)
{
    node* temp = new node;
    temp->data = value;
    temp->next= NULL;
    temp->prev = NULL;
        
    if (isEmpty())
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void addNodePos(int pos, int value)
{
    if (pos <= 0 || pos > size() + 1)
    {
        cout << "Klaida";
        return;
    }
    
    if (pos == 1)
    {
        addNodeStart(value);
        return;
    }
    
    if(pos == size() + 1)
    {
        addNodeEnd(value);
        return;
    }
    
    node* temp = new node;
    temp->data = value;
    temp->next= NULL;
    temp->prev = NULL;
    
    if (size() / 2 >= pos)
    {
        pre = head;
        
        for (int i = 1; i < pos - 1; i++)
        {
            pre = pre->next;
        }
        
        temp->next = pre->next;
        pre->next = temp;
        temp->prev = pre;
        temp->next->prev = temp;
    }
    else
    {
        nxt = tail;
        
        for (int i = 1; i < pos - 1; i++)
        {
            nxt = nxt->prev;
        }
        
        temp->prev = nxt->prev;
        nxt->prev = temp;
        temp->next = nxt;
        temp->prev->next = temp;
    }
}
    
void deleteNodeStart()
{
    if (isEmpty())
    {
        cout << "Listas tuscias." << "\n";
        return;
    }

    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {

        head = head->next;
        delete head->prev;
        head->prev = NULL;
    }
}
    
void deleteNodeEnd()
{
    if (isEmpty())
    {
        cout << "Listas tuscias." << "\n";
        return;
    }

    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
}

void deleteNodePos(int pos)
{
    if (pos <= 0 || pos > size())
    {
        cout << "Klaida";
        return;
    }

    if (pos == 1)
    {
        deleteNodeStart();
        return;
    }

    if (pos == size())
    {
        deleteNodeEnd();
        return;
    }

    cur = head;
        
    if (pos <= size() / 2)
    {
        for (int i = 1; i < pos; i++)
        {
            cur = cur->next;
        }
    }
    else
    {
        cur = tail;
        
        for (int i = 1; i <= size() - pos; i++)
        {
            cur = cur->prev;
        }
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}
    
void search(int value)
    {
    node* temp = head;
    int position = 1;
        
    while (temp != NULL)
    {
        if (temp->data == value){
                
            cout << "\n" << "Reiksmes pozicija: " << position << "\n";
            return;
        }
            
        temp = temp->next;
        position++;
    }
        
    cout << "\n" << "Reiksme nerasta." << "\n";
}
    
int size()
{
    int size = 0;
    node* temp = head;
    
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    
    return size;
}

void reverse()
{
    if (isEmpty() || head == tail)
    {
        return;
    }

    cur = head;
    node* temp = NULL;

    while (cur != NULL)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;

        cur = cur->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}

bool isEmpty()
{
    return head == NULL && tail == NULL;
}
    
void clear()
{
    cur = head;
    
    while (cur != NULL)
    {
        node* next = cur->next;
        delete cur;
        cur = next;
    }
    
    head = NULL;
    tail = NULL;
}
    
void display()
{
    node* temp = head;
        
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
};

int main()
{
    bidirectionalLinkedList listas;
    listas.addNodeEnd(4);
    listas.addNodeEnd(9);
    listas.addNodeEnd(2);
    listas.display();
    
    cout << "\n";
    
    listas.addNodeStart(45);
    listas.addNodeStart(6);
    listas.deleteNodeStart();
    listas.deleteNodeEnd();
    listas.display();
    
    cout << "\n";
    cout << listas.size();
    listas.search(9);
    
    listas.reverse();
    listas.deleteNodePos(2);
    listas.addNodePos(2, 100);
    listas.display();
    
    return 0;
}
