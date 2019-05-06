//
//  main.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 20/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>

using namespace std;
int main() {
    int cnt, num, i=0;
    string command;
    cin >> cnt;
    int arr[50];
    
    while(cnt--){
        cin >> command;
        if (command == "push")
        {
            cin >> num;
            arr[i] = num;
            i++;
        }
        else if(command == "top"){
            if(i <= 0){
                cout << "-1" << endl;
            }
            else{
                cout << arr[i-1] << endl;
            }
        }
        else if(command == "size"){
            cout << i << endl;
        }
        else if(command == "empty"){
            if (i <= 0){
                cout << "1" << endl;
            }
            else
                cout << "0" << endl;
        }
        else if(command == "pop"){
            if (i<=0){
                cout << "-1" << endl;
            }
            else{
                cout << arr[i-1] << endl;
                i--;
            }
        }
    }
    return 0;
}
