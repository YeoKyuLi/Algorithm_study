//
//  인구이동 (16234).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 11/06/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int N, L, R;
int arr[101][101];
bool visited[101][101];
int ppl, national;
queue<pair<int,int>> close_natioanl;

void BFS(int a, int b){
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    queue<pair<int,int>> q;
    
    ppl = arr[a][b];
    visited[a][b]= true;
    q.push(make_pair(a, b));
    close_natioanl.push(make_pair(a, b));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int diff = abs(arr[nx][ny]- arr[a][b]);
            if(nx >= 0 && ny >= 0 && nx < N && ny < N && L <= diff && diff <= R && !visited[nx][ny]){
                visited[nx][ny]= true;
                ppl += arr[nx][ny];
                national++;
                close_natioanl.push(make_pair(nx, ny));
                q.push(make_pair(nx,ny));
            }
            
        }
        
        
    }
    
    
}

int main()
{
    cin >> N >> L >> R;
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> arr[i][j];
        }
    }
    
    int movePpl = 0;
    while(1){
        bool found = false;
        memset(visited, false, sizeof(visited));
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N; j++){
                if(visited[i][j])
                    continue;
                national = 1;
                BFS(i,j);
                
                if(national >= 2){
                    found = true;
                    cout << "size : " << close_natioanl.size() << " " << national << endl;
                    int avr = ppl / national;
                    while(!close_natioanl.empty()){
                        arr[close_natioanl.front().first][close_natioanl.front().second] = avr;
                        close_natioanl.pop();
                    }
                }
            }
        }
        if(found)
            movePpl++;
        else
            break;
    }
    cout << movePpl << endl;
    
    return 0;
}
