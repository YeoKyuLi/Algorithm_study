//
//  ROT13(11655).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>

using namespace std;

int main()
{
    string str;
    
    getline(cin, str);
    
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= 'A' and str[i] <= 'Z')
            str[i] = (str[i] -'A' + 13)%26 +'A';
        if(str[i] >= 'a' and str[i] <= 'z')
            str[i] = (str[i] -'a' + 13)%26 +'a';
//        if(str[i] >= 'a' and str[i] <= 'm'){
//            str[i] += 13;
//        }
//        else if(str[i] >= 'n' and str[i] <= 'z'){
//            str[i] -= 13;
//        }
//        if(str[i] >= 'A' and str[i] <= 'M'){
//            str[i] += 13;
//        }
//        else if(str[i] >= 'N' and str[i] <= 'z'){
//            str[i] -= 13;
//        }
    }
    cout << str << endl;
    
    return 0;
}
