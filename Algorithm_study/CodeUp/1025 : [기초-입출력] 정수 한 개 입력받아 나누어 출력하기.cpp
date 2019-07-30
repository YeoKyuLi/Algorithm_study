//
//  1025 : [기초-입출력] 정수 한 개 입력받아 나누어 출력하기.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 19/06/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cin >> num;
    
    string s = to_string(num);
    
    reverse(s.begin(), s.end());
    cout.flags(ios::left);
    cout.fill('0');
    for(int i = 4 ; i >= 0 ; i--){
        cout << "[";
        cout.width(i+1);
        cout << s[i] -'0' << "]" << endl;
        
    }
    
    return 0;
}
