//
//  아기상어 (16236).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 30/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int arr[101][101];
int s_size=2;
int d;
int dist[101][101]; //최단거리
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

vector<pair<int,int>> eat;
pair<int,int> last;

void BFS(int a, int b){
    d=100000;
    eat.clear();
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if( nx <= 0 && ny <= 0 && nx > N && ny > N){
                if(dist[nx][ny]==0 && s_size >= arr[nx][ny]){
                    dist[nx][ny] = dist[x][y]+1; // 최단거리 구하기.
                    if(0 < arr[nx][ny] && arr[nx][ny] < s_size){
                        if(d >= dist[nx][ny]){
                            eat.push_back(make_pair(nx,ny));
                            d = dist[nx][ny];
                            last.first = nx;
                            last.second = ny;
                        }
                    }
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}


int main()
{
    cin >> N;
    int cnt=0, minN=0;
    int x=0,y=0;
    for(int i = 0 ; i < N; i ++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j]==9){
                x = i;
                y = j;
                arr[i][j]=0;
            }
        }
    }
    
    while(true){
        BFS(x,y);
        if(eat.empty())
            break;
        else{
            if(eat.size() == 1){
                x = last.first;
                y = last.second;
            }
            else{
                // 여기서 조건을 더해줘야함.. 크기가 여러개인 경우!
                for(int i = 0 ; i < eat.size(); i++){
                    int cx = eat[i].first;
                    int cy = eat[i].second;
                    if(d == dist[cx][cy]){
                        if(last.first == cx){
                            if(last.second > cy){
                                last = eat[i];
                            }
                        }
                        else if(last.first > cx){
                            last = eat[i];
                        }
                    }
                }
            }
            cout << "eheh" << endl;
            cnt++;
            x = last.first;
            y = last.second;
            arr[x][y]=0;
            cout << "dist ==" << dist[x][y] << endl;
            minN += dist[x][y];
            if(s_size == cnt){
                s_size++;
                cnt=0;
            }
        }
    }
    cout << "sss" << minN << "\n";
    return 0;
}
