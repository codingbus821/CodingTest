//
//  main.cpp
//  boj1504
//
//  Created by 김병수 on 2020/09/24.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

int N,E;
vector<pair<int, int>> arr[801];

int dijkstra(int start,int end){
    int dist[801];
    for(int i=0;i<=N;i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        
        if(distance > dist[current])
            continue;
        for(int i=0;i<arr[current].size();i++){
            int next = arr[current][i].first;
            int nextdistance = distance + arr[current][i].second;
            
            if(dist[next] > nextdistance){
                dist[next] = nextdistance;
                pq.push(make_pair(-nextdistance, next));
            }
        }
    }
    
    return dist[end];
}

int main(int argc, const char * argv[]) {
    
    int a,b,c;
    int v,vv;
    
    cin >> N >> E;
    
    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }
    
    cin >> v >> vv;
    
    int f = dijkstra(1, v);
    int ff = dijkstra(1, vv);
    int s = dijkstra(v, vv);
    int t = dijkstra(vv, N);
    int tt = dijkstra(v, N);
    
    int ans = min(f+s+t,ff+s+tt);
    
    if(ans >= INF){
        cout << -1;
    }else{
        cout << ans;
    }
    
    return 0;
}
