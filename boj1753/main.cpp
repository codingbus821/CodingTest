//
//  main.cpp
//  boj1753
//
//  Created by 김병수 on 2020/09/23.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000

using namespace std;

vector<pair<int, int>> arr[20001];
int dist[20001];

void dijkstra(int start){ // start노드를 기준으로 하는 다익스트라
    dist[start] = 0; // 자기 자신으로 가는 최단 거리는 0
    priority_queue<pair<int, int>> pq; // 가장 비용이 적은 노드를 방문하기 위한 heap
    pq.push(make_pair(0, start)); // 첫번째 인자는 가중치 두번째인자는 노드의 번호
    
    while(!pq.empty()){
        int current = pq.top().second; // 현재 노드
        int distance = -pq.top().first; // 현재 노드까지 가중치의 합
        pq.pop();
        
        if(dist[current] < distance) continue;
        for(int i=0;i<arr[current].size();i++){
            int next = arr[current][i].first; // 연결된 다음 노드
            int nextdistance = distance + arr[current][i].second; // 연결된 다음 노드까지 가중치의 합.
            
            if(nextdistance < dist[next]){ // 다음 노드까지의 가중치의 합이 현재까지 구한 최단 경로보다 작으면 갱신 후 priority queue에 push
                dist[next] = nextdistance;
                pq.push(make_pair(-nextdistance,next));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int V,E,K;
    
    cin >> V >> E;
    cin >> K;
    
    for(int i=1;i<=V;i++){
        dist[i] = INF;
    }
    
    for(int i=0;i<E;i++){
        int u,v,w;
        
        cin >> u >> v >> w;
        
        arr[u].push_back(make_pair(v, w));
    }
    
    dijkstra(K);
    
    for(int i=1;i<=V;i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }else{
            cout << dist[i] << '\n';
        }
    }
    
    return 0;
}
