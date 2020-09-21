//
//  main.cpp
//  boj1167
//
//  Created by 김병수 on 2020/09/21.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[100001];
bool visited[100001];
int dist[100001];
int max_node,max_length;
queue<int> q;

void BFS(int x){ // BFS
    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    
    while(!q.empty()){
        int s=q.front();
        q.pop();
        
        for(auto i:v[s]){ // 범위기반 for
            if(visited[i.first] == false){
                visited[i.first] = true;
                dist[i.first] = i.second + dist[s]; // dist[노드의 번호]에 노드까지의 거리 저장
                q.push(i.first);
                if(max_length < dist[i.first]){ // 루트부터 현재 노드 까지 거리가 최고일때 max_node에 노드의 번호 저장
                    max_length = dist[i.first];
                    max_node = i.first;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int V;
    
    cin >> V;
    
    for(int i=0;i<V;i++){
        int start;
        
        cin >> start;
        
        if(start == -1)
            continue;
        else{
            int end,weight;
            
            while(true){
                
                cin >> end;
                
                if(end == -1)
                    break;
                else{
                    cin >> weight;
                    v[start].push_back(make_pair(end, weight));
                }
            }
        }
    }
    
    BFS(1); // 루트에서 가장 거리가 먼 위치의 노드를 찾음
    
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    
    BFS(max_node); // 루트에서 가장 거리가 먼 노드에서 시작해 가장 거리가 먼 노드를 찾음
    
    cout << max_length;
    
    return 0;
}

