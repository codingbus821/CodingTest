//
//  main.cpp
//  boj1766
//
//  Created by 김병수 on 2020/09/30.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[33333];
int inDegree[33333];
bool visited[33333];

void topologysort(vector<int> v[], int n){
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=1;i<=n;i++){
        if(inDegree[i] == 0){
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        cout << x << " ";
        
        for(int i=0;i<v[x].size();i++){
            if(--inDegree[v[x][i]] == 0){
                pq.push(v[x][i]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N, M; cin >> N >> M;
    
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        
        v[a].push_back(b);
        inDegree[b]++;
    }
    
    topologysort(v, N);
    
    return 0;
}
