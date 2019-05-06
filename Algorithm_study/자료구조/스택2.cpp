//
//  스택2.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 20/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    int cnt, num;
    string command;
    cin >> cnt;
    stack<int> st;
    while(cnt--){
        cin >> command;
        if (command == "push")
        {
            cin >> num;
            st.push(num);
        }
        else if(command == "top"){
            if(st.empty()){
                cout << "-1" << endl;
            }
            else{
                cout << st.top() << endl;
            }
        }
        else if(command == "size"){
            cout << st.size() << endl;
        }
        else if(command == "empty"){
            if (st.empty()){
                cout << "1" << endl;
            }
            else
                cout << "0" << endl;
        }
        else if(command == "pop"){
            if (st.empty()){
                cout << "-1" << endl;
            }
            else{
                cout << st.top() << endl;
                st.pop();
            }
        }
    }
    return 0;
}
