//
//  Linked List.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 30/07/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
// https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
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

    // Create It's added in the end of Linked List.
    void Create(int inputValue){
        Node *temp = new Node(0);
        temp->data = inputValue;
        temp->next = nullptr;
        if(head==nullptr){
            head = temp;
            tail = temp;
            temp = nullptr;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    //disply
    void Disply(){
        Node *temp = new Node(0);
        temp = head;
        while(temp!=nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // insert start
    void Insert_start(int inputValue){
        Node *temp = new Node(0);
        temp->data = inputValue;
        temp->next = head;
        head=temp;
        
    }
    // insert end
    void Insert_end(int inputValue){
        Node *temp = new Node(0);
        temp->data = inputValue;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    // insert particular position
    void Insert_particular(int position, int inputValue){
        Node *temp = new Node(0);
        Node *pos = new Node(0);
        temp->data = inputValue;
        pos = head;
        int a = 2;
        while(pos!=NULL){
            if(position == a){
                temp->next = pos->next;
                pos->next = temp;
                break;
            }
            pos = pos->next;
            a++;
        }
        
        Node *cur = new Node(0);
        Node *pre = new Node(0);
        Node *temp1 = new Node(0);
        cur = head;
        for(int i = 1 ; i < position ; i++){
            pre = cur;
            cur = cur->next;
        }
        temp1->data = inputValue;
        pre->next = temp1;
        temp1->next = cur;
    }
    // delete start
    void Delete_start(){
        Node *temp = new Node(0);
        temp = head;
        head = head->next;
        delete temp;
        
    }
    // delete end
    void Delete_end(){
        Node *cur = new Node(0);
        Node *pre = new Node(0);
        cur = head;
        while(cur->next != nullptr){
            pre = cur;
            cur = cur->next;
        }
        tail = pre;
        tail->next = nullptr;
        delete cur;
    }
    // delete particular position
    void Delete_particular(int position){
        Node *cur = new Node(0);
        Node *pre = new Node(0);
        cur = head;
        for(int i = 1; i< position; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }
};


int main()
{
    LinkedList list;
//    int value;
//    cin >> value;
//    while(getline(cin, value)){
    cout << "==================Creat==================" << endl;
    list.Create(10);
    list.Create(29);
    list.Create(30);
    list.Disply();
    cout << "==================Insert in begin==================" << endl;
    list.Insert_start(0);
    list.Disply();
    
    cout << "==================Insert in end==================" << endl;
    list.Insert_end(50);
    list.Disply();
    
    cout << "==================Insert in particular==================" << endl;
    list.Insert_particular(3, 60);
    list.Disply();
    
    cout << "==================Delete in begin==================" << endl;
    list.Delete_start();
    list.Disply();
    
    cout << "==================Delete in end==================" << endl;
    list.Delete_end();
    list.Disply();
    
    cout << "==================Delete in particular==================" << endl;
    list.Delete_particular(4);
    list.Disply();
    
    
    return 0;
}
