
//
//  덱(10866).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    
    int cnt;
    string command;
    int num;
    cin >> cnt;
    deque<int> deq;
    while(cnt--){
        cin >> command;
        if(command == "push_front"){
            cin >> num;
            deq.push_front(num);
        }
        else if(command == "push_back"){
            cin>>num;
            deq.push_back(num);
        }
        else if(command == "pop_front"){
            if(!deq.empty()){
                cout << deq.front() << endl;
                deq.pop_front();
            }
            else
                cout << -1 << endl;
        }
        else if(command == "pop_back"){
            if(!deq.empty()){
                cout << deq.back() << endl;
                deq.pop_back();
            }
            else
                cout << -1 << endl;
        }
        else if(command == "size")
            cout << deq.size() << endl;
        else if(command == "empty"){
            if(deq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(command == "front"){
            if(deq.empty()) cout << -1 << endl;
            else cout << deq.front() << endl;
        }
        else if(command == "back"){
            if(deq.empty()) cout << -1 << endl;
            else cout << deq.back() << endl;
        }
    }
    return 0;
}

