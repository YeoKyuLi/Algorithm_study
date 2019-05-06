//
//  1로 만들기(1463).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int cnt, i;
    int DP[1000001]{0};
    cin >> cnt;
    for(i = 2; i <= cnt ; i++){
        DP[i] = DP[i-1] + 1;
        if(i % 2 == 0) DP[i] = min(DP[i], DP[i/2]+1);
        if(i % 3 == 0) DP[i] = min(DP[i], DP[i/3]+1);
    }
    
    cout << DP[cnt];
    
    return 0;
}
