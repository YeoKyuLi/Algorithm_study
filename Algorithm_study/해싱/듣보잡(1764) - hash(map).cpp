//
//  듣보잡(1764) - hash(map).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 12/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <map>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n,m;
    map<string, int> hash;
    cin >> n >> m;
    for(auto i=0; i<n; i++){
        string temp;
        cin >> temp;
        hash[temp]++;
    }
    for(auto i = 0 ; i < m; i++){
        string temp;
        cin >> temp;
        hash[temp]++;
    }
    priority_queue<string, vector<string>, greater<>> pq;
    for(auto i : hash){
        if(i.second == 2){
            pq.push(i.first);
        }
    }
    cout << pq.size() << "\n";
    while(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }
    return 0;
}
