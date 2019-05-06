//
//  연결 요소의 개수 (11724).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 23/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1001;

bool visit[MAX];
vector<int> graph[MAX];

void DFS(int x)
{
    visit[x] = true;
    for(int y : graph[x]){
        if(!visit[y]){
            DFS(y);}
    }
}
int main()
{
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0 ; i < m ; i++){
        int s,e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    int cnt = 0;
    
    for(int i = 0 ; i <= n ; i++){
        if(!visit[i]){
            DFS(i);
            cnt++;
        }
    }
    
    cout << cnt;
    return 0;
}



