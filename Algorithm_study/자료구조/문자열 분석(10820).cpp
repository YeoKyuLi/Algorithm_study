//
//  문자열 분석(10820).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
   
//    cout << str << endl;
//    for(char a ='a' ; a <= 'z' ;a++ )
//        small += count(str.begin(), str.end(), a);
//    for(char a ='A' ; a <= 'Z' ;a++ )
//        capital += count(str.begin(), str.end(), a);
//
//    for(char a ='1' ; a <= '9' ;a++ )
//        num += count(str.begin(), str.end(), a);
    string str;
    while(getline(cin, str)){
        int small=0, capital=0, num=0, space=0;
        for(int i = 0 ; i < str.length(); i++){
            if(str[i] >= 'a' and str[i] <= 'z')
                small++;
            else if(str[i] >= 'A' and str[i] <= 'Z')
                capital++;
            else if(str[i] >= '0' and str[i] <= '9')
                num++;
            else if(str[i] == ' ')
                space++;
        }
        cout << small << " " << capital << " " << num << " " << space << endl;
    }
    return 0;
}
