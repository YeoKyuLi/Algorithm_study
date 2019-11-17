#include <iostream>
using namespace std;
struct Node
{
public:
    int val;
    Node* next = nullptr;
    Node(int x) : val(x), next(nullptr){}
};

class LinkedList
{
private:
    Node *head, *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr){}
    
    void create(int inputValue)
    {
        Node* node = new Node(inputValue);
        
        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        
    }
    
    void disply()
    {
        Node* temp = head;
        while(temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    
    void push_front(int inputValue)
    {
        
    }
    
    void pop_front()
    {
        
    }
    
    void insert_after(int inputValue, int index)
    {
        
    }
    
    void erase_after(int index)
    {
        
    }
    
    void push_back(int inputValue)
    {
        
    }
    
    void pop_back()
    {
        
    }
    
    
};

int main()
{
    
    LinkedList list;
    
    list.create(20);
    list.create(2);
    list.disply();
    
    
    return 0;
}

