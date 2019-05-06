//
//  알파벳 찾기(10809).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
int main(){
    int alphabet[26];
    fill_n(alphabet, 26, -1);
    string str;
    
    cin >> str;
    
    for(int i = 0 ; i < str.length(); i++){
        if((alphabet[str[i] - 'a']) == -1)
            alphabet[str[i] - 'a'] = i;
    }

    for(int j = 0 ; j < 26; j++)
        cout << alphabet[j] << " ";
    cout << endl;
    
}
