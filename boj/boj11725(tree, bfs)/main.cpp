//
//  main.cpp
//  boj11725
//
//  Created by 김병수 on 2020/09/18.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int parent[MAX];
bool visited[MAX];

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    
    int N;
    vector<vector<int>> v;
    
    cin >> N;
    
    v.resize(N+1); // 배열의 인덱스 0~N번까지 초기화
    
    for(int i=0;i<N-1;i++){ // BFS를 위해 벡터에 넣음
        int w,h;
        
        cin >> h >> w;
        v[h].push_back(w);
        v[w].push_back(h);
    }
    
    queue<int> q;
    
    parent[1] = 0; // 루트인 1 부터 push
    visited[1] = true;
    q.push(1);
    
    while(!q.empty()){ // BFS
        int x = q.front();
        q.pop();
        
        for(int y : v[x]){ // 범위기반for
            if(!visited[y]){
                visited[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    
    for(int i=2;i<=N;i++){ // 결과 출력
        cout << parent[i] << '\n';
    }
    
    return 0;
}
