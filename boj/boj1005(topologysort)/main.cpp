//
//  main.cpp
//  boj1005
//
//  Created by 김병수 on 2020/09/30.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, K;
int nodeWeight[1111];
int inDegree[1111];
int dist[1111]; // 현재노드까지 오는 최장 시간을 저장함.

int topoloysort(vector<int> v[],int w){
    
    queue<int> q;
    
    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0){
            q.push(i);
            dist[i] = nodeWeight[i];
        }
    }
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            if(--inDegree[v[x][i]] == 0){
                q.push(v[x][i]);
            }
            if(dist[v[x][i]] < dist[x] + nodeWeight[v[x][i]]){
                // 한 노드까지 걸리는 시간은 무조건 이전 노드까지의 시간 + 현재 노드에서 걸리는 시간이 최장시간인 것으로 선택해야함.
                dist[v[x][i]] = dist[x] + nodeWeight[v[x][i]];
            }
        }
    }
    
    return dist[w];
}

int main(int argc, const char * argv[]) {
    
    int T; cin >> T;
    
    while(T--){ // 테스트 케이스만큼 반복.
        vector<int> v[1111];
        memset(inDegree,0,sizeof(inDegree));
        memset(dist,0,sizeof(dist));
        cin >> N >> K;
        for(int i=1;i<=N;i++){
            cin >> nodeWeight[i]; // 노드당 걸리는 시간 저장.
        }
        for(int i=0;i<K;i++){
            int a,b; cin >> a >> b;
            v[a].push_back(b);
            inDegree[b]++;
        }
        int W; cin >> W;
        
        cout << topoloysort(v, W) << '\n'; // 위상정렬 사용
    }
    
    return 0;
}
