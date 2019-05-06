//
//  트리 순회 (1991).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 18/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>

using namespace std;
int tree[26][2];

void preOrder(int node){
    if(node == int('.' -'A'))
        return;
    
    cout << (char)(node + 'A');
    preOrder(tree[node][0]);
    preOrder(tree[node][1]);
}

void inOrder(int node){
    if(node == int('.' -'A'))
        return;
    
    inOrder(tree[node][0]);
    cout << (char)(node + 'A');
    inOrder(tree[node][1]);
}

void postOrder(int node){
    if(node == int('.' -'A'))
        return;
    
    postOrder(tree[node][0]);
    postOrder(tree[node][1]);
    cout << (char)(node + 'A');
}

int main(){
    int cnt;
    
    cin >> cnt;
    
    char node, left, right;
    
    while(cnt--){
        cin >> node >> left >> right;
        tree[node - 'A'][0] = left - 'A';
        tree[node - 'A'][1] = right - 'A';
        
    }
    
    preOrder(0);
    cout << endl;
    inOrder(0);
    cout << endl;
    postOrder(0);
    cout << endl;
    
    return 0;
}
