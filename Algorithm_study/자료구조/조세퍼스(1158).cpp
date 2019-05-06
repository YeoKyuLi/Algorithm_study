//
//  조세퍼스(1158).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 27/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    queue<int> que;
    
    cin >> N >> M;
    
    for(int i = 1 ; i <= N; i++){
        que.push(i);
    }
    cout << "<" ;
    while(!que.empty()){
        if(que.size() == 1){
            cout << que.front() << ">" << endl;
            que.pop();
            break;
        }
        for(int j = 1 ; j < M ; j++){
            que.push(que.front());
            que.pop();
        }
        cout << que.front() <<", ";
        que.pop();
    }
    return 0;
}
