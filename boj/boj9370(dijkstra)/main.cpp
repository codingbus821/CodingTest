//
//  main.cpp
//  boj9370
//
//  Created by 김병수 on 2020/09/25.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

vector<pair<int, int>> v[2001];

vector<int> dijkstra(int start, int end){
    vector<int> dist;
    for(int i=0;i<=2000;i++){
        dist.push_back(INF);
    }
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        
        if(distance > dist[cur]) continue;
        
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nextdist = distance + v[cur][i].second;
            
            if(dist[next] > nextdist){
                dist[next] = nextdist;
                pq.push(make_pair(-nextdist, next));
            }
        }
    }
    
    return dist;
}

int main(int argc, const char * argv[]) {
    
    int Tc;
    
    cin >> Tc;
    
    for(int i=0;i<Tc;i++){
        int n,m,t,s,g,h;
        int x;
        priority_queue<int> anspq;
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        
        for(int j=0;j<m;j++){
            int a,b,d;
            cin >> a >> b >> d;
            v[a].push_back(make_pair(b, d));
            v[b].push_back(make_pair(a, d));
        }
        
        for(int k=0;k<t;k++){
            cin >> x;
            
            vector<int> best = dijkstra(s, x);
            int bestdist = best[x];
            
            vector<int> best2 = dijkstra(g, x);
            vector<int> best3 = dijkstra(h, x);
            int sg = best[g];
            int sh = best[h];
            int gh = best2[h];
            int gx = best2[x];
            int hx = best3[x];
            
            int best4 = min(sg+gh+hx,sh+gh+gx);
            
            if(bestdist == best4){
                anspq.push(-x);
            }
        }
        
        while(!anspq.empty()){
            cout << -anspq.top() << " ";
            anspq.pop();
        }
        cout << '\n';
        for(int i=0;i<2001;i++){
            v[i].clear();
        }
    }
    return 0;
}
