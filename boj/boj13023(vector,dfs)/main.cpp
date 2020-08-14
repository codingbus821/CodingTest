//
//  main.cpp
//  boj13023
//
//  Created by 김병수 on 2020/08/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N,M;
vector<int> v[2000];
bool visited[2001];
bool visit_check = false;

void dfs(int s,int visit){
    
    if(visit == 4){
        visit_check = true;
        return;
    }
    
    for(int i=0;i<v[s].size();i++){
        int next = v[s][i];
        if(!visited[next]){
            visited[next] = true;
            dfs(next,visit+1);
            visited[next] = false;
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> N >> M;
    
    for(int i=0;i<M;i++){
        int a,b;
        
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        memset(visited, false, sizeof(visited));
        
        visited[i] = true;
        
        dfs(i,0);
        if(visit_check)
            break;
    }
    
    if(visit_check == false){
        cout << 0;
    }else{
        cout << 1;
    }
    
    return 0;
}
