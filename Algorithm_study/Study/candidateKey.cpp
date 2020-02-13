#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void com(int begin, int xBegin, vector<vector<string>>& relation, vector<string>& tmp)
{
//    if(begin == relation.size())
//    {
//        return ;
//    }
//
    for(auto a : tmp)
        cout << a << " ";
    cout << endl;
   
    cout <<relation.size() << " " << relation[0].size() << endl;
//    for(int i = xBegin; i < xBegin+1; i++)
//    {
        for(int j = begin; j < relation[xBegin].size();j++)
        {
            tmp.push_back(relation[xBegin][j]);
            com(j+1,0,relation, tmp);
            tmp.pop_back();
        }
        
//    }
    
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    cout << "H"<<endl;
    vector<string> tmp;
    int xBegin =0;
    com(1,xBegin,relation, tmp);
//     int width = relation[0].size();
//     int hight = relation.size();
//     unordered_map<string, int> map;
//     bool flag=0;
//     for(int i = 0 ; i < width; i++)
//     {
//         map.clear();
//         cout << map.size();
//         flag = 1;
//         for(int j = 0 ; j < hight; j++)
//         {
            
//             // if(map.find(relation[j][i]) == map.end())
//             //     map.insert(make_pair(relation[j][i], 1));
//             // else
//             // {
//             //     cout << "Error!!" << relation[j][i] << endl;
//             //     flag = 0;
//             //     break;
//             // }
//         }
//         cout << endl;
//     }
    return answer;
}

int main(){
    vector<vector<string>> relation = {
        {"100","ryan","music","2"},
        {"200","apeach","math","2"},
        {"300","tube","computer","3"},
        {"400","con","computer","4"},
        {"500","muzi","music","3"},
        {"600","apeach","music","2"}
    };
    int re = solution(relation);
    return 0;
    
}
