//
//  K번째 수(11004).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 09/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.sync_with_stdio(false);
    std::ios::sync_with_stdio(false);
    int cnt, k;
    cin >> cnt >> k;
    
    int* arr = new int[cnt];
    
    for(int i = 0 ; i < cnt ;i ++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[cnt]);
    
    cout << arr[k-1] << endl;
    delete []arr;
    return 0;
}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    int cnt, k;
//    cin >> cnt >> k;
//
//    vector<int> v;
//
//    for(int i = 0 ; i < cnt; i++){
//        int num;
//        cin >> num;
//        v.push_back(num);
//    }
//    sort(v.begin(), v.end());
//
//    cout << v[k-1] << endl;
//
//    return 0;
//}

