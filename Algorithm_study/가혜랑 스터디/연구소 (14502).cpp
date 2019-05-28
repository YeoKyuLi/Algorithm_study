//
//  연구소 (14502).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 21/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
int N,M;
int arr[101][101];
int visited[101][101];
int cnt = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void BFS(int a, int b){
    queue <pair<int,int>> q;
    q.push(make_pair(a,b));
    visited[a][b] = true;
    cnt += 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(arr[nx][ny]== 0 && !visited[nx][ny]){
                    visited[nx][ny]= true;
                    cnt += 1;
                    q.push(make_pair(nx, ny));
                    break;
                }
            }
        }
    }
}

void make_wall()
{
    
    
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> arr[i][j];
        }
    }
    
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(arr[i][j] == 0 && !visited[i][j])
                BFS(i,j);
        }
    }
    
    cout << cnt << endl;
    return 0;
}
