//
//  트리의 높이와 너비 (2250).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 29/04/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10001;
pair<int, int> tree[MAX];
pair<int, int> minMax[MAX];
int minX[MAX] = {10000};
int maxX[MAX];
int findNode[MAX];
int x_coordinate = 1;
int height;

void DFS (int node, int level){
    
    
    if(tree[node].first > 0)
        DFS(tree[node].first, level+1);
    
//    cout << " node : " << node <<  " level: " << level << " X : " << x_coordinate << endl;

    minX[level] = min(minX[level], x_coordinate);
    maxX[level] = max(maxX[level], x_coordinate);
    height = max(height, level);
//    cout <<"level : " << level << " min: " << minX[level] << " max: " << maxX[level] << endl;
    
    x_coordinate++;
    
    if(tree[node].second > 0)
        DFS(tree[node].second, level+1);
            
}
int main()
{
    
    int N;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        int node, left, right;
        cin >> node >> left >> right;
        
        findNode[node]++;
        
        if(!tree[node].first)
            findNode[left]++;
        tree[node].first = left;
        
        if(!tree[node].second)
            findNode[right]++;
        
        tree[node].second = right;
    }
    
    int root = 0;
    for(int i = 1 ; i <= N ; i++){
        if(findNode[i] == 1)
            root = i;
    }
    fill_n(minX, MAX, MAX);
    DFS(root, 1);
    int sum, maxVal=0, levelNum=0;
    for(int i = 1 ; i <= height ; i++){
        sum = maxX[i] - minX[i] + 1;
        if(sum > maxVal){
            maxVal = sum;
            levelNum = i;
        }
    }
    
    cout << levelNum << " " << maxVal;
    return 0;
}
