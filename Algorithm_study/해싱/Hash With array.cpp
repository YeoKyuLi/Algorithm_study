//
//  Hash With array.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 12/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;
class Hash{
    int BUCKET;
    list<int> *table;
public:
    Hash(int V);
    void insertItem(int value);
    void deleteItem(int value);
    int hashFunction(int value){
        return (value % BUCKET); //return key
    }
    void displayHash();
};

Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
void Hash::insertItem(int value){
    int key = hashFunction(value);
    table[key].push_back(value);
}
void Hash::deleteItem(int value){
    int key = hashFunction(value);
    list<int> :: iterator i;
    for(i = table[key].begin(); i != table[key].end(); i++){
        if(*i == value)
            break;
    }
    if(i != table[key].end())
        table[key].erase(i);
}
void Hash::displayHash(){
    for(int key = 0 ; key < BUCKET ; key++){
        cout << key;
        for(auto value: table[key])
            cout << " --> " << value;
        cout << endl;
    }
}
int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);
    Hash h(7);
    for(int i = 0 ; i < n; i++)
        h.insertItem(a[i]);
    
    h.deleteItem(12);
    h.displayHash();
    return 0;
}
