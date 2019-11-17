//
//  FindTheFrequency.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 2019/11/17.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
/*
 Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.

  

 Input Format:
 First line of input contains number of testcases T. For each testcase there will be three lines. First line of which contains N, size of vector. Second line contains N positive integers seperated by space, and third line contains X, whose frequency is required.

 Output Format:
 For each testcase, print the frequency of X.

 User Task:
 Your task is to complete the function findFrequency() which should count the frequency of X and return it.

 Constraints:
 1 <= T <= 100
 1 <= N <= 106
 1 <= V[i] <= 1016

 Example:
 Input:
 1
 5
 1 1 1 1 1
 1
 Output:
 5

 Explanation:
 Testcase 1: Frequency of 1 is 5.
 */

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Function to find frequency of x
* x : element whose frequency is to be found
* v : input vector
*/
//Initial Template for C++
#include <iostream>
#include <vector>

using namespace std;

int findFrequency(vector<int> v, int x){
    
    int result = 0;
    // Your code here
    for(int val : v)
    {
        if(val == x)
            result++;
    }
    
    return result;
    return count(v.begin(), v.end(), x);
    
}


//Position this line where user code will be pasted.
// Driver code
int main() {
    
    int testcase;
    
    cin >> testcase;
    
    while(testcase--){
        int N;
        cin >> N;
        
        // Declaring vector
        vector<int> v;
            
        // Taking vector element input
        for(int i = 0;i<N;i++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        
        // element whose frequency to be find
        int x;
        cin >> x;
        
        cout << findFrequency(v, x) << endl;
    }
    
    return 0;
}
