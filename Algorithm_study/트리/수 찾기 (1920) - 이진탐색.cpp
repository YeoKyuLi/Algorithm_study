//
//  수 찾기 (1920).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 21/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v(N);
int BinarySearch(int low, int high, int target){
    if(low > high)
        return 0;
    else{
        int mid = (low+high)/2;
        if(v[mid] == target)
            return 1;
        else if(v[mid] > target)
            return BinarySearch(low, mid-1, target);
        else
            return BinarySearch(mid+1, high, target);
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for(int i = 0 ; i < N; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    
    // need to sorting for using binaray serach
    sort(v.begin(), v.end());
    
    cin >> M;
    for(int j = 0; j < M; j++){
        int num;
        cin >> num;
        cout << BinarySearch(0, N-1, num) << "\n";

    }
    //        for(int j = 0 ; j < N ; j++){
    //            if(num == v[j]){
    //                cout << "1" << endl;
    //                break;
    //            }
    //            else if(j == N-1)
    //                cout << "0" << endl;
    //        }
    return 0;
}
