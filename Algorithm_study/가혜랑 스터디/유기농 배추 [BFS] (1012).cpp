//
//  유기농 배추 (1012).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 02/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
// 인접리스트로 풀기!!
#include <iostream>
#include <queue>
#include <cstring> // memset
using namespace std;
int V, H;
int arr[101][101];
bool visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void input()
{
    int N;
    cin >> V >> H >> N;
    while(N--){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    
    
}

void BFS(int a , int b){
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    visited[a][b] = true;
    
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < V && ny < H ){
                if(!visited[nx][ny]){
                    if(arr[nx][ny] == 1){
                        visited[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    
    while(T--){
        int earthworm=0;
        input();
        for(int i = 0 ; i < V ; i ++){
            for(int j = 0 ; j < H; j++){
                if(!visited[i][j] && arr[i][j]){
                    BFS(i,j);
                    earthworm++;
                }
            }
        }
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cout <<earthworm << endl;
    }
    
    
    return 0;
}
