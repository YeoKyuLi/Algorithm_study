//
//  문자열 - KMP.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 21/05/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
//https://www.acmicpc.net/blog/view/67
// https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220927272165
#include <iostream>
#include <vector>

using namespace std;
vector<int> makeTable(string pattern){
    long patternSize = pattern.size();;
    vector<int> table(patternSize, 0);
    int j = 0;
    for(int i =1; i < patternSize;i++){
        while(j>0 && pattern[i] != pattern[j]){
            cout << j << endl;
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }

    return table;

}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    long parentSize = parent.size();
    long patternSize = pattern.size();
    int j = 0;
    for(int i = 0; i < parentSize; i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[i-1];
        }
        if(parent[i] == pattern[j]){
            if(j==patternSize-1){
                cout << (i - patternSize)+2 << "번째에서 찾았습니다." << endl;
                j = table[i];
            }
            else{
                j++;
            }
        }
    }
}

int main()
{
    // dynamic allocation
    string parent = "ababacabacaabacaaba";
    string pattern ="abacaaba";
    KMP(parent,pattern);

    cout <<" ??"<<endl;

//    vector<int> table = makeTable(pattern);
//    for(int i = 0; i < table.size(); i++){
//        cout << table[i] << " ";
//    }
    return 0;
}

//vector<int> makeTable(char* pattern){
//    unsigned long patternSize = strlen(pattern);
//
//    vector<int> table(patternSize, 0);
//    int j = 0;
//    for(int i =1; i < patternSize;i++){
//        cout << i << ": " << pattern[j] <<" " << pattern[i];
//        while(j >= 0 && pattern[i] != pattern[j]){
//            j = table[j-1];
//        }
//        if(pattern[i] == pattern[j]){
//            cout << "j";
//            table[i] = ++j;
//        }
//    }
//
//
//
//    return table;
//
//}
//int main()
//{
//    // dynamic allocation
//    char *pattern;
//    int N, result=-1000000;
//    cin >> N;
//    pattern = new char[N];
//
//    for(int i = 0; i < N; i ++)
//        cin >> pattern[i];
////    for(int i = 0; i < N; i ++)
////        cout << pattern[i];
//    vector<int> table = makeTable(pattern);
//    for(int i = 0; i < table.size(); i++){
//        cout << table[i] << " ";
//        result = max(result, table[i]);
//    }
//    delete [] pattern;
//    cout << result;
//    return 0;
//}

