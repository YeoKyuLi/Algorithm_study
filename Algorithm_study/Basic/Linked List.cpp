//
//  Linked List.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 30/07/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
/*
* insert(location, value)
* remove(location), remove(value)
* search(value)
* print all
*/
#include <iostream>
#include <string>

using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr){}
};
class LinkedList{
private:
    Node *head, *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr){}

    void Create(int inputValue){
        Node *temp = new Node(0);
        temp->data = inputValue;
        temp->next = nullptr;
        if(head==nullptr){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    
    void Disply(){
        Node *temp = new Node(0);
        temp = head;
        while(temp!=nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

//disply

//insert
// particular position, end, start
//delete


void printAll(){
    
}
int main()
{
    LinkedList list;
//    int value;
//    cin >> value;
//    while(getline(cin, value)){
    list.Create(10);
    list.Create(29);
    
    list.Disply();
    
    
    return 0;
}
