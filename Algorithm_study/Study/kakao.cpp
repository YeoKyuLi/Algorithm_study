/*
 * test.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: ezyeoky
 */

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = {0, 1, 1}; // right, below, diagonal
int dy[] = {1, 0, 1};
void BFS(int _x, int _y, int width, int hight, vector<string> &board)
{

    queue<pair<int, int>> q;

    q.push(make_pair(_x, _y));

    char pivot = board[_x][_y];


    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        board[x][y] = '*';

        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            cout << nx << " " << ny << " ";

            if (nx >= 0 && ny >= 0 && nx < width && ny < hight)
            {
                cout << nx << " " << ny << " " <<  board[nx][ny]<< endl;
                if (pivot == board[nx][ny])
                {
                    cout << "a " << endl;
                    q.push(make_pair(nx, ny));
                }
                else
                {
                    cout << " b" << endl;
                    for (int j = i; j != 0 ; j--)
                    {
                            q.pop();
                    }
                    break;
                }
            }
        }
    }
}

void reArrange(int width, int hight, vector<string> &board)
{
    int empPoint;
    for (int i = 0; i < width; i++)
    {
        empPoint = 0;
        for (int j = hight - 1; j >= 0; j--)
        {
            if (board[j][i] == '*' && j > empPoint)
            {
                empPoint = j;
            }
            if (empPoint != 0 && board[j][i] != '*')
            {
                swap(board[empPoint][i], board[j][i]);
//                board[empPoint][i] = board[j][i];
//                board[j][i] = '*';
                empPoint--;
            }

        }
    }
}
int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    cout << m << n << endl;
    cout << board.size() << endl;


        for (int i = 0; i < m-1; i++)
        {
            for (int j = 0; j < n -1; j++)
            {

                if (board[i][j] == board[i + dx[0]][j + dy[0]] && board[i][j] == board[i + dx[1]][j + dy[1]] && board[i][j] == board[i + dx[2]][j + dy[2]])
                {

                    BFS(i, j, m, n, board);
                    reArrange(m, n, board);
                }
            }
            cout << endl;
        }



//    for (auto v : board)
//        cout << v << " ";
//    cout << endl;
//
    for (auto &v : board)
        answer += count(v.begin(), v.end(), '*');

    return answer;
}

int main()
{
    vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    int m = 4, n = 5;
//    int m = 6, n = 6;
//    vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};

    cout << " ggg " << endl;

    cout << solution(m, n, board);

    cout << " ggg " << endl;
}
