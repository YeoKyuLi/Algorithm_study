//
//  좌표 정렬하기 2 (11651).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 08/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int cnt;
    cin >> cnt;
    
    vector <pair<int, int>> v(cnt);
    
    //x is second, y is first
    // because y is using for cmp fucntion
    for(int i = 0 ; i < cnt; i ++)
        cin >> v[i].second >> v[i].first;
    
    sort(v.begin(), v.end());
    
    for(int i = 0 ; i < cnt ; i++)
        cout << v[i].second << " " << v[i].first << endl;
    
    
    return 0;
}
