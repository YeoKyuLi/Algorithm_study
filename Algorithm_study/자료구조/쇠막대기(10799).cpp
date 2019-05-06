//
//  쇠막대기(10799).cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 27/03/2019.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    string str;
    int result = 0;

    getline(cin, str, '\n');
    
    for(int i = 0 ; i < str.length(); i++){
        if (str[i] == '(')
            st.push('(');
        else if(str[i] == ')'){
            st.pop();
            if(str[i-1] == '(')
                result += st.size();
            else
                result += 1;
        }
    }
    cout << result << endl;
    
    return 0;
}
