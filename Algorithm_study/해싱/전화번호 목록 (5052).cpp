//
//  전화번호 목록 (5052).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 06/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while(T--){
        int N;
        cin >> N;
        vector<string> arr(N);
        
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
//        sort(arr, arr+N);
        
        bool isConsistency=true;
        for(int i = 1 ; i < arr.size(); i++){
            if(arr[i-1] == arr[i].substr(0, arr[i-1].size())){
                isConsistency = false;
                break;
            }
        }
        puts(isConsistency ? "YES" : "NO");
//        if(isConsistency)
//            cout << "YES" << endl;
//        else
//            cout << "NO" << endl;
    }
    return 0;
}
