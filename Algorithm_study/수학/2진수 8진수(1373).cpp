//
//  2진수 8진수(1373).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 01/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
int main()
{
    
    string str;
    cin >> str;
    
    if(str.length()%3 == 1)
        str = "00" + str;
    else if(str.length()%3 == 2)
        str =  "0" + str;
    

    for(int i = str.length()%3 ; i < str.length(); i= i+3){
        cout << (str[i] - '0') *4 + (str[i+1] - '0')*2 + str[i+2]-'0';
    }
    return 0;
}
