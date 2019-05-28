//
//  연구소 (14502).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 21/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;
int N,M;
int arr[101][101];
int copyMap[101][101];
int cnt = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int result;
void BFS(){
    
    int afterSpread[101][101];
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            afterSpread[i][j] = copyMap[i][j];
        }
    }
    
    
    queue <pair<int,int>> q;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(afterSpread[i][j]==2)
                q.push(make_pair(i, j));
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(afterSpread[nx][ny]== 0 ){
                    afterSpread[nx][ny]= 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    
    // 빈칸세기
    int saftZone=0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(afterSpread[i][j]==0)
                saftZone++;
        }
    }
    
    result = max(result, saftZone);
}

void makeWall(int cnt)
{
    if(cnt == 3){
        BFS();
        return;
    }
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(copyMap[i][j]==0){
                copyMap[i][j] = 1;
                makeWall(cnt+1);
                copyMap[i][j] = 0;
            }
        }
    }
    
    
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
            if(arr[i][j]==0){
                memcpy(&copyMap, &arr, sizeof(arr));
                copyMap[i][j] = 1;
                makeWall(1);
                copyMap[i][j] = 0;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}
