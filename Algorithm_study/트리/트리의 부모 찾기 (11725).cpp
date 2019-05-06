//
//  트리의 부모 찾기 (11725).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 18/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;

vector<vector<int>> tree(MAX);
int parents[MAX];
bool visited[MAX];

int main()
{
    
    int cnt;
    
    cin >> cnt;
    
    for(int i = 0 ; i < cnt-1; i++){
        int a,b;
        
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    queue<int> q;
    parents[1] = 0;
    visited[1] = true;
    q.push(1);
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : tree[x]){
            if(!visited[y]){
                visited[y] = true;
                parents[y] = x;
                q.push(y); 
            }
        }
    }
    
    for(int i = 2; i <= cnt ; i++)
        cout << parents[i] << "\n";
    return 0;
}
