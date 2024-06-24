//
//  main.cpp
//  boj2606
//
//  Created by 김병수 on 2024/06/23.
//  Copyright © 2024 coconut. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

typedef struct st{
    int node;
    struct st *next;
}NODE;

NODE head[111];
NODE pool[11111];
int cnt;
int ans = 0;
bool visited[111];

void init(){
    for(int i=0;i<111;i++){
        head[i].node = 0;
        head[i].next = 0;
        visited[i] = 0;
        cnt = 0;
    }
}

void make(int f, int s){
    NODE *nd = &pool[cnt++];
    nd->node = s;
    nd->next = head[f].next;
    head[f].next = nd;
}

void bfs(){
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()){
        int tmp = q.front();
        q.pop();
        
        for(NODE *p = head[tmp].next;p;p = p->next){
            if(visited[p->node] == false){
                visited[p->node] = true;
                q.push(p->node);
                ans++;
            }
        }
    }
    
}

int c_num, e_num;

int main() {
    
    int f,s;
    
    cin >> c_num >> e_num;
    
    init();
    
    for(int i=0;i<e_num;i++){
        cin >> f >> s;

        make(f,s);
        make(s,f);
    }
//    cout << "hi";
    bfs();
    
    cout << ans;
    
    return 0;
}
