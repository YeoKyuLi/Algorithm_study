//
//  해쉬 - array.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 10/06/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

#define LOAD_FACTOR 20

struct Node{
    int data;
    struct Node* next;
};

struct HashNode{
    int key;
    int count;
    struct Node* list;
};
struct HashTable{
    int size;
    int numOfData;
    struct HashNode** table;
};

struct HashTable* CreateHashTable(int tableSize);
int GetKey(int data, int tableSzie);
bool HashSearch(struct HashTable* hTable, int data);
void HashInsert(struct HashTable* hTable, int data);
void HashDelete(struct HashTable* hTable, int data);
void DeleteHashTable(struct HashTable* hTable);
void PrintHashTable(struct HashTable* hTable);
struct HashTable* ReHash(struct HashTable* hTable);

int main(void){
    int tableSize;
    cout << "Table Size를 입력: ";
    cin >> tableSize;
    //(1) HashTable 생성
    struct HashTable* hTable = CreateHashTable(tableSize);
    //(2) HashTable 요소 삽입
    cout << "데이터 삽입 (0-99)" << endl;
    for(int i = 0 ; i < 100; i++){
        HashInsert(hTable, i);
    }
    //(3) HashTable 출력
    PrintHashTable(hTable);
    
    //(4) HashTable 요소 삭제
    cout << "모든 데이터 삭제" << endl;
    for(int i = 0 ; i < 100; i++){
        HashDelete(hTable, i);
    }
    //(5) HashTable 출력
    PrintHashTable(hTable);
    //(6) HashTable 소멸
    DeleteHashTable(hTable);
    
    return 0;
}

struct HashTable* CreateHashTable(int tableSize){
    //생성
    struct HashTable* hTable;
    hTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    
    if(!hTable){
        cout << "Memory Allocation Fail" << endl;
        return NULL;
    }
    hTable->size = tableSize;
    hTable->numOfData = 0;
    hTable->table = (struct HashNode**)malloc(sizeof(struct HashNode*)*tableSize);
    
    if(!hTable->table){
        cout << "Memory Allocation Fail" << endl;
        return NULL;
    }
    //메모리 할당 및 초기화
    for(int i = 0 ; i < tableSize; i++){
        hTable->table[i] = (struct HashNode*)malloc(sizeof(struct HashNode));
        if(!hTable->table[i]){
            cout << "Momory Allocation Fail" << endl;
            return NULL;
        }
        hTable->table[i]->key = i;
        hTable->table[i]->count = 0;
        hTable->table[i]->list = NULL;
    }
    cout << "HashTable Create" << endl;
    return hTable;
}
int GetKey(int data, int tableSize){
    return data%tableSize;
}

bool HashSearch(struct HashTable* hTable, int data){
    struct Node* temp = NULL;
    temp = hTable->table[GetKey(data, hTable->size)]->list;
    
    if(!temp){
        return false;
    }
    while(temp){
        if(temp->data==data){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void HashInsert(struct HashTable* hTable, int data){
    struct HashNode* first;
    first = hTable->table[GetKey(data,hTable->size)];
    
    struct Node* temp;
    temp = first->list;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(!node){
        cout << "Memory Allocation Fail" << endl;
        return;
    }
    node->data=data;
    node->next=NULL;
    
    //(1) Empty
    if(!temp){
        first->list = node;
    }
    //(2) Exist Duplication (앞에서 움직임)
    else{
        struct Node* temp2;
        temp2 = first->list;
        first->list = node;
        node->next = temp2;
    }
    //cout << "Data Insertion Success" << endl;
    first->count++;
    
    //ReHash 조건 검사
    if((first->count / hTable->size) > LOAD_FACTOR){
        hTable = ReHash(hTable);
    }
}
void HashDelete(struct HashTable* hTable, int data){
    struct HashNode* first;
    first = hTable->table[GetKey(data, hTable->size)];
    
    struct Node* temp;
    temp = first->list;
    
    struct Node* before = temp;
    if(!temp){
        return;
    }
    while(temp){
        if(temp->data==data){
            if(before == temp){
                first->list = temp->next;
            }
            else{
                before->next = temp->next;
            }
            free(temp);
            break;
        }
        before = temp;
        temp = temp->next;
    }
    cout << "Data Deletion Success" << endl;
    first->count--;
}
void DeleteHashTable(struct HashTable* hTable){
    for(int i = 0 ; i < hTable->size; i++){
        struct Node* temp = NULL;
        struct Node* before = NULL;
        temp = hTable->table[i]->list;
        before=temp;
        while(temp){
            before = temp;
            temp = temp -> next;
            free(before);
        }
    }
    for(int i = 0 ; i < hTable->size; i++){
        free(hTable->table[i]);
    }
    free(hTable);
    cout << "HashTable Delete"<< endl;
}
void PrintHashTable(struct HashTable* hTable){
    cout << "All Print Hash Table Data" << endl;
    for(int i = 0; i < hTable->size; i++){
        struct HashNode* first = hTable->table[i];
        struct Node* temp = first->list;
        cout << "Key " << i << ": ";
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

struct HashTable* ReHash(struct HashTable* hTable){
    //New create
    struct HashTable* oldTable = hTable;
    hTable = CreateHashTable(hTable->size *2);
    if(!hTable){
        cout << "Memory Allocation Fail" << endl;
        return NULL;
    }
    
    //Data Copy
    for(int i = 0 ; i < oldTable->size;i++){
        struct HashNode* first = oldTable->table[i];
        struct Node* temp = first->list;
        
        while(temp){
            HashInsert(hTable, temp->data);
            temp = temp->next;
        }
    }
    DeleteHashTable(oldTable);
    cout << "Rehash by Load Factor" << endl;
    return hTable;
}
