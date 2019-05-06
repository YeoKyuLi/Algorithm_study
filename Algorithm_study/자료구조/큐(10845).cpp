//
//  큐(10845).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 27/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
    int cnt, num;
    queue<int> que;
    string command;
    cin >> cnt;
    while(cnt--){
        cin >> command;
        if(command == "push"){
            cin >> num;
            que.push(num);
        }
        else if(command == "pop"){
            if(que.empty())
                cout << "-1" << endl;
            else{
                cout << que.front() << endl;
                que.pop();
            }
        }
        else if(command == "size"){
            cout << que.size() << endl;
        }
        else if(command == "empty"){
            if(que.empty()){
                cout << "1" << endl;
            }
            else
                cout << "0" << endl;
        }
        else if(command == "front"){
            if(que.empty()){
                cout << "-1" << endl;
            }
            else
                cout << que.front() << endl;
        }
        else if(command == "back"){
            if(que.empty()){
                cout << "-1" << endl;
            }
            else
                cout << que.back() << endl;
        }
    }
    
}
