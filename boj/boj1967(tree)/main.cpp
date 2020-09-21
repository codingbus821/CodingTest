//
//  main.cpp
//  boj1967
//
//  Created by 김병수 on 2020/09/21.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10001];
int dist[10001];
queue<int> q;
int max_node,max_length;

void BFS(int s){
    visited[s] = true;
    q.push(s);
    dist[s] = 0;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(auto i:v[x]){
            if(visited[i.first] == false){
                visited[i.first] = true;
                dist[i.first] = i.second + dist[x];
                q.push(i.first);
                if(dist[i.first] > max_length){
                    max_length = dist[i.first];
                    max_node = i.first;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    int s,e,w;
    
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        cin >> s >> e >> w;
        v[e].push_back(make_pair(s, w));
        v[s].push_back(make_pair(e, w));
    }
    
    BFS(1);
    
    memset(visited,false,sizeof(visited));
    memset(dist,0,sizeof(dist));
    
    BFS(max_node);
    
    cout << max_length;
    
    return 0;
}

