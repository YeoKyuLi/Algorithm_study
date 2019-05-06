//
//  최소공배수(1934).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>

using namespace std;

int gcd(int a , int b){
    return b==0 ? a : gcd(b, a%b);
}
int main()
{
    int cnt, a, b;
    cin >> cnt;
    while(cnt--){
        cin >> a  >> b;
        cout << (a*b)/gcd(a,b) << endl;
    }
    return 0;
}
