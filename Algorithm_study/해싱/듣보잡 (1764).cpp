//
//  듣보잡 (1764).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 08/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<string> arrN(N);
    vector<string> arrM(M);
    vector<string> same;
    
    for(int i = 0 ; i < N ; i++)
        cin >> arrN[i];
    
    for(int i = 0 ; i < M ; i++)
        cin >> arrM[i];
    
    for(int i = 0 ; i < M; i++){
        for(int j = 0 ; j < N; j++){
            if(arrN[j] == arrM[i]){
                same.push_back(arrN[j]);
                break;
            }
        }
    }
    cout << same.size() << "\n";
    for(int i = 0 ; i < same.size(); i++)
        cout << same[i] << "\n";
    return 0;
}
