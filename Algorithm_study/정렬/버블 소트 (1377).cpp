//
//  버블 소트 (1377).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 09/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
//https://browoo.tistory.com/65
// 버블 소트의 진행한 횟수 == 좌측으로 이동한 횟수
// 기존의 인덱스 번호와 버블 소트 후 인덱스 번호를 보면, 음수이면 오른쪽 이동, 양수이면 왼쪽 이동이다.
// 여기서 제일 큰 수 + 1 하면 버블 소트 진행한 횟수가 된다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.sync_with_stdio(false);
    int cnt;
    cin >> cnt;
    vector<pair<int,int>> v(cnt);
    
    for(int i = 0 ; i < cnt ; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int result = 0;
    for(int i = 0 ; i < cnt ; i++)
        result = max(result, v[i].second - i);
    
    cout << result + 1 << endl;
    
    return 0;
}
