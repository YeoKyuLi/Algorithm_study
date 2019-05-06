//
//  나머지(10430).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
using namespace std;

int main()
{
    int a, b , c;
    
    cin >> a >> b >> c;
    
    cout << (a+b)%c << endl;
    cout << ((a%c) + (b%c))%c << endl;
    cout << (a*b)%c << endl;
    cout << ((a%c) * (b%c))%c << endl;
    return 0;
}
