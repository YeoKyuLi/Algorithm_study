//
//  적록색약 (10026).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 02/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
//Pair :: https://blockdmask.tistory.com/64
// 
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N;
char arr[101][101];
bool visited[101][101];

//상, 왼, 하, 오
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void Input(){
    cin >> N;
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j <N ; j++){
            cin >> arr[i][j];
        }
    }
}
void BFS(int a, int b){
    queue<pair<int, int>> Q;
    Q.push(make_pair(a,b));
    visited[a][b] = true;
    
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(!visited[nx][ny]){
                    if(arr[nx][ny] == arr[x][y]){
                        visited[nx][ny] = true;
                        Q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        
    }
    
}
int main()
{
    Input();
    
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int normal, colorWeak;
    normal = colorWeak = 0;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            if(!visited[i][j]){
                BFS(i,j);
                normal++;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            if(arr[i][j] == 'G')
                arr[i][j] = 'R';
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            if(!visited[i][j]){
                BFS(i,j);
                colorWeak++;
            }
        }
    }
    
    cout << normal << " " << colorWeak << endl;
    
    return 0;
}
