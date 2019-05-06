//
//  최대공약수과 최소공배수(2609).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;

int gcd (int a , int b){
    return b == 0 ? a : gcd (b, a%b);
}
int main()
{
    
    int a , b;
    cin >> a >> b;
    int c;
    c = gcd(a,b);
    cout << c << endl;
    cout << (a*b)/c << endl;
    return 0;
}
