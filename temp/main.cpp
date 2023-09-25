#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

int main(int argc, const char * argv[])
{
    int N, K;
    queue<pair<int,int>> q;
    
    cin >> N >> K;
    
    q.push(make_pair(N, 0));
    
    while(!q.empty())
    {
        if (q.front().first == K)
        {
            cout << q.front().second;
            break ;
        }
        if (q.front().first * 2 <= 100000 && visited[q.front().first] == 0)
            q.push(make_pair(q.front().first*2, q.front().second+1));
        if (q.front().first + 1 <= 100000 && visited[q.front().first] == 0)
            q.push(make_pair(q.front().first+1, q.front().second+1));
        if (q.front().first - 1 >= 0 && visited[q.front().first] == 0)
            q.push(make_pair(q.front().first-1, q.front().second+1));
        visited[q.front().first] = 1;
        q.pop();
    }

    return 0;
}
