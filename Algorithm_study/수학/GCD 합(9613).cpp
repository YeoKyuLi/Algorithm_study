//
//  GCD 합(9613).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
using namespace std;
int num[100]{0};
int gcd(int a , int b){
    return b == 0 ? a : gcd(b, a%b);
}
int main()
{
    
    int cnt;
    cin >> cnt;
    while(cnt--){
        int arrNum;
        cin >> arrNum;
        for(int i = 0 ; i < arrNum; i++)
            cin >> num[i];
        
        long long result = 0;
        for(int i = 0 ; i< arrNum-1; i++){
            for(int j = i+1 ; j < arrNum ; j++){
                result += gcd(num[i], num[j]);
            }
        }
        cout << result << endl;
    }
    return 0;
}
