//
//  수 정렬하기3 (11989).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 09/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int cnt;
    int v[100];
    cin >> cnt;
    
    for(int i = 0 ; i < cnt; i++){
        cin >> v[i];
    }
    sort(v, v+cnt);
    
    for(int i = 0 ; i < cnt; i++){
        cout << v[i] << endl;
    }
    return 0;
}
