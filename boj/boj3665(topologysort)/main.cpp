//
//  main.cpp
//  boj3665
//
//  Created by 김병수 on 2020/09/25.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 501

using namespace std;

vector<int> v;
int g[MAX][MAX];

void solve(){
    memset(g,0,sizeof g);
    int n; cin >> n; v.resize(n);
    for(auto &i : v) cin >> i;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            g[v[i]][v[j]] = 1;
        }
    }
    int m; cin >> m;
    while(m--){
        int a, b; cin >> a >> b;
        swap(g[a][b], g[b][a]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(g[v[j]][v[i]]) swap(v[i], v[j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(g[v[j]][v[i]]){
                cout << "IMPOSSIBLE\n"; return;
            }
        }
    }
    
    for(auto i : v) cout << i << " "; cout << "\n";
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
