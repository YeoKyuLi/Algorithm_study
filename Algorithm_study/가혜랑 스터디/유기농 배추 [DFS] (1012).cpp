//
//  유기농 배추 [인접 리스트] (1012).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 02/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
// 인접리스트 :: BFS

#include <iostream>
#include <cstring> // memset
int arr[101][101];
char visited[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int H, V, N;
using namespace std;

void DFS(int x , int y){
    if(visited[x][y])
        return;
    visited[x][y] = true;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0  && ny >= 0 && nx < V && ny < H ){
            if(arr[nx][ny]){
                DFS(nx, ny);
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
    
    while(T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cin >> V >> H >> N;
        while(N--){
            int a , b;
            cin >> a >> b;
            arr[a][b] = 1;
        }
        
        int cnt=0;
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < H; j++){
                if(!visited[i][j] && arr[i][j]){
                    DFS(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}
