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

