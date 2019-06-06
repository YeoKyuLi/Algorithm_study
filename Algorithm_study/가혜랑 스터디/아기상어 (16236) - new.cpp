//
//  아기상어 (16236) - new.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 06/06/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[101][101];
int dist[101][101];
int d;
int x,y;
int s_size = 2;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pair<int,int>> eat;
pair<int, int> last;

void BFS(int a, int b){
    eat.clear();
    d = 1000000;
    memset(dist, 0, sizeof(dist));
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >=0 && ny >=0 && nx < N && ny < N){
                if(dist[nx][ny]==0 && arr[nx][ny] <= s_size){
                    dist[nx][ny] = dist[x][y]+1;
                    if(arr[nx][ny] > 0 && arr[nx][ny] < s_size){
                        if(d >= dist[nx][ny]){
                            eat.push_back(make_pair(nx, ny));
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
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                x = i;
                y = j;
                arr[i][j] = 0;
            }
        }
    }
    int cnt= 0;
    int result=0;
    while(true){
        BFS(x,y);
        if(eat.empty()){
            break;
        }
        else{
            if(eat.size()==1){
                x = last.first;
                y = last.second;
            }
            else{
                for(int i = 0 ; i < eat.size();i++){
                    int cx = eat[i].first;
                    int cy = eat[i].second;
                    if(dist[cx][cy] == d){
                        if(last.first == cx){
                            if(last.second > cy ){
                                last = eat[i];
                            }
                        }else if(last.first > cx){
                            last = eat[i];
                        }
                    }
                }
            }
            cnt++;
            x = last.first;
            y = last.second;
            arr[x][y]= 0;
            result += dist[x][y];
            if(cnt == s_size){
                s_size++;
                cnt=0;
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
