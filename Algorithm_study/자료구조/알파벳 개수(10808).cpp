//
//  알파벳 개수(10808).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// a - 97 == 0
int alphabet[26];
int main()
{
    string str;
    cin >> str;
    for(int i = 0 ; i <str.length() ; i++){
        alphabet[str[i]-'a']++;
    }
    for(int j = 0 ; j < 26 ; j++)
        cout << alphabet[j] << " ";
    cout << endl;
    
//    for(char a = 'a' ; a <= 'z'; a++){
//        cout<< count(str.begin(), str.end(), a) << " ";
//    }
//    cout << endl;
    return 0;
}
