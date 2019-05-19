//
//  로봇청소기 (14503).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 12/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
// 핵심 포인트, 처음에 dx, dy를 어떤 순서대로 넣어 줄 것인가!
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[101][101];
bool visited[101][101];
int N, M, r,c,d;
//int dx[] = {0, 1, 0, -1}; // 북,동,남,서
//int dy[] = {1, 0, -1, 0};
int dx[] = {-1, 0, 1, 0}; // 서, 북, 동, 남
int dy[] = {0, 1, 0, -1};
int cnt = 0;

int directionNext(int d){
    // 북->서, 서->남, 남->동, 동->북
    if(d == 0)
        return 3;
    else if(d == 3)
        return 2;
    else if(d == 2)
        return 1;
    else
        return 0;
}
int directionBack(int d){
    // 북->남, 남->북, 동->서, 서->동
    if(d == 0)
        return 2;
    else if(d == 1)
        return 3;
    else if(d == 2)
        return 0;
    else
        return 1;
}
void BFS(int a, int b, int d){
    //0 N, 1 E, 2 S, 3 W
    cnt += 1;
    
    queue<pair<int,int>> que;
    que.push(make_pair(a,b));
    visited[a][b]= true;
    int next = d;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        bool go = false;
        que.pop();
        for(int i = 0 ; i < 4 ; i++){
            // 여기서 방향을 정해줘야함
            next = directionNext(next);
            int nx = x + dx[next];
            int ny = y + dy[next];
            //움직일지 여부
            if(nx >= 0 && ny >= 0 && nx < N && ny < M ){
                if(arr[nx][ny] == 0 && !visited[nx][ny]){
                    go = true;
                    visited[nx][ny] = true;
                    que.push(make_pair(nx,ny));
                    cnt += 1;
                    break;
                }
            }
        }
        if(go == false){
            int back = directionBack(next);
            int bx = x + dx[back];
            int by = y + dy[back];
            //            cout << "back " << back << " next " << next << endl;
            //            cout <<"x,y (" << x <<" , " << y << ") " <<"bx, by (" << bx << ", " << by << ") arr[bx][by] : " <<  arr[bx][by] << endl;
            if(arr[bx][by] == 1)
                break;
            
            que.push(make_pair(bx,by));
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >>  r >> c >> d;
    
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j++){
            cin >> arr[i][j];
        }
    }
    BFS(r,c,d);
    
    cout << cnt << endl;
    return 0;
}

