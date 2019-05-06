//
//  수 정렬하기2 (2751).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 08/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
int cnt;
int main()
{
    // dynamic arrary
//    int cnt, *arr;
//    cin >> cnt;
//    arr = new int[cnt];
    cin >> cnt;
    
    for(int i = 0 ; i < cnt ; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < cnt ; i++)
        cout << v[i] << endl;
    
    
    return 0;
    
}
