//
//  ModularExponentiationForLargeNumber.cpp
//  Algorithm_study
//
//  Created by Yeo Kyu Li on 2019/11/17.
//  Copyright © 2019 Yeo Kyu Li. All rights reserved.
//
/*
 Implement pow(A, B) % C.

 In other words, given A, B and C, find (AB)%C.

  

 Input:

 The first line of input consists number of the test cases.

  The following T lines consist of 3 numbers each separated by a space and in the following order:

 A B C

 'A' being the base number, 'B' the exponent (power to the base number) and 'C' the modular.

  

 Output:

 In each separate line print the modular exponent of the given numbers in the test case.


 Constraints:

 1 ≤ T ≤ 70

 1 ≤ A ≤ 10^5

 1 ≤ B ≤ 10^5

 1 ≤ C ≤ 10^5


 Example:

 Input:

 3
 3 2 4
 10 9 6
 450 768 517

 Output:

 1
 4
 34
 */

#include <iostream>
#include <cmath>
using namespace std;

// long long int pow(base, exponent)
// {
//     if(exponenet == 0)
//         return 1;
    
// }
long long int  calculator(int  base, int  exponent, int  modular)
{
    long long int tmp = 1;
    while(exponent--)
        tmp = tmp * base;
        
    return tmp % modular;
}
int main() {
    //code
    
    int T, A, B,C;
    long long int result;
    cin >> T;
    
    while(T--)
    {
        cin >> A >> B >> C;
        result = calculator(A,B,C);
        cout << result << endl;
    }
    
    return 0;
}



#include<iostream>
using namespace std;
#define nl printf("\n")
typedef long long int ll;

int modExp(int a, int b, int c){
    if(b==0)
        return 1;
    return (a*modExp(a,b-1,c))%c;
}

int main()
 {
    int t;
    cin>>t;
    while(t--){
      int a,b,c;
      cin>>a>>b>>c;
      cout<<modExp(a,b,c)<<endl;
    }
    
    return 0;
}
