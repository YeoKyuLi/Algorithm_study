//
//  이진 트리 (13325).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int const MAX =22;
int arr[MAX];
int result;
int N, treeSize;

int DFS(int idx){
    if(idx*2 >= treeSize){
        result += arr[idx];
        return arr[idx];
    }
    else{
        int leftNode = DFS(idx*2);
        int rightNode = DFS(idx*2+1);
        result += arr[idx] + abs(leftNode - rightNode);
        return arr[idx] + max(leftNode, rightNode);
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin >> N;
    treeSize = 1 << (N+1);
    for(int i = 2 ; i < treeSize; i++){
        cin >> arr[i];
    }
    DFS(1);
    cout << result << "\n";
    
    return 0;
}
