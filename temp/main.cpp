#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
char arr[51][51] = { 0 };
pair<int, int> visit[51][51];
pair<int, int> visit2[51][51];
int dn[8] = { -2,-2,2,2,-1,1,-1,1 };
int dm[8] = { -1,1,-1,1,-2,-2,2,2 };
int main() {
    int n, m, k = 0, temp = 1000000000;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            arr[i][j + 1] = str[j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] != '.')
            {
                k++;
                int num = arr[i][j] - '0';
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j].first++; //visit(방문 횟수, 말여러개 합친 이동횟수)
                visit2[i][j].first = 1; //visit2(color, 이동횟수)
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int p = 0; p < 8; p++)
                    {
                        if (x + dn[p] < 1 || x + dn[p] > n || y + dm[p] < 1 || y + dm[p] > m)
                            continue;
                        else if (visit2[x + dn[p]][y + dm[p]].first == 0)
                        {
                            q.push(make_pair(x + dn[p], y + dm[p]));
                            visit2[x + dn[p]][y + dm[p]].first = 1;
                            visit2[x + dn[p]][y + dm[p]].second = visit2[x][y].second + 1;
                            visit[x + dn[p]][y + dm[p]].first++;
                            if (visit2[x + dn[p]][y + dm[p]].second % num != 0)
                                visit[x + dn[p]][y + dm[p]].second += (visit2[x + dn[p]][y + dm[p]].second / num) + 1;
                            else
                                visit[x + dn[p]][y + dm[p]].second += (visit2[x + dn[p]][y + dm[p]].second / num);
                        }
                    }
                }
            }
            fill(&visit2[0][0], &visit2[0][0] + 51 * 51, make_pair(0, 0));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visit[i][j].first == k)
                temp = min(temp, visit[i][j].second);
            else
                continue;
        }
    }
    if (temp != 1000000000)
        cout << temp;
    else
        cout << -1;
}
