//
//  1,2,3 더하기(9095).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>

using namespace std;
int main()
{
    int cnt;
    cin >> cnt;
    
    while(cnt--){
        int num;
        int DP[11]{0};
        DP[0] = 1;

        cin >> num;
        for(int i = 1 ; i <= num; i++){
            if(i-1 >= 0)
                DP[i] += DP[i-1];
            if(i-2 >= 0)
                DP[i] += DP[i-2];
            if(i-3 >= 0)
                DP[i] += DP[i-3];
        }
        cout << DP[num] << endl;
    }
    
    return 0;
}
