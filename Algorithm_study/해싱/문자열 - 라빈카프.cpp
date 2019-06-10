//
//  문자열 - 라빈카프.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 10/06/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>

using namespace std;

void findString(string parent, string pattern){
    long parentSize = parent.size();
    long patternSize = pattern.size();
    int parentHash =0, patternHash =0, power=1;
    
    for(int i = 0 ; i <= parentSize - patternSize; i++){
        if(i==0){
            for(int j = 0 ; j < patternSize; j++){
                parentHash = parentHash + parent[patternSize -1 -j] * power;
                patternHash = patternHash + pattern[patternSize - 1- j] * power;
                if(j < patternSize -1) power = power *2;
            }
        }else{
            parentHash = 2* (parentHash - parent[i-1] * power) + parent[patternSize-1+i];
        }
        if(parentHash == patternHash){
            bool finded = true;
            for(int j = 0 ; j < patternSize; j++){
                if(parent[i+j] != pattern[j]){
                    finded = false;
                    break;
                }
            }
            if(finded)
                cout << i+1 << "번째에서 발견했습니다." << endl;
        }
    }
}
int main()
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    findString(parent, pattern);
    cout << "finished";
    return 0;
}
