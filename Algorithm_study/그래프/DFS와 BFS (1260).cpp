//
//  DFS와 BFS (1260).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 23/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 1001;

bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

void DFS(int x)
{
    visit[x] = true;
    cout << x << " ";
    for(int y : adj[x]){
        if(!visit[y]){
            DFS(y);}
    }
}
void BFS(int sx){
    Q.push(sx);
    visit[sx] = true;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        cout << x << " ";
        for(int y : adj[x]){
            if(!visit[y]){
                Q.push(y);
                visit[y] = true;
            }
        }
    }
    
}
int main()
{
    
    int n, m, v;
    
    cin >> n >> m >> v;
    
    for(int i = 0 ; i < m ; i++){
        int s,e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    for(int i = 1 ; i <=n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    DFS(v);
    cout << endl;
    memset(visit, 0, sizeof(visit));
    BFS(v);
    
    return 0;
}

