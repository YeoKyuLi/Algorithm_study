//
//  2*n 타일링(11726).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 31/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
using namespace std;

int main()
{
    int DP[1001]{0};
    
    DP[0] = DP[1] = 1;
    
    int cnt;
    cin >> cnt;
    
    for(int i = 2; i <= cnt; i++){
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }
    
    cout << DP[cnt];
    return 0;
}
