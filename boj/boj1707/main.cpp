//
//  main.cpp
//  boj1707
//
//  Created by 김병수 on 2024/06/23.
//  Copyright © 2024 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct node {
    int node;
    struct node* next;
}NODE;

NODE head[22222];
NODE pool[444444];

int K, V, E;
int cnt;
int check[22222];

void init() {
    cnt = 0;
    for (int i = 1; i <= V; i++) {
        head[i].node = 0;
        head[i].next = 0;
        check[i] = 0;
    }
}

void make(int f, int s) {
    NODE *nd = &pool[cnt++];
    
    nd->node = s;

    nd->next = head[f].next;
    head[f].next = nd;
}

int dfs(int s, int c) {
    check[s] = c;
    for (NODE* p = head[s].next; p; p = p->next) {
        if (check[p->node] == c)
            return 0;
        if (!check[p->node]) {
            if (!dfs(p->node, 3 - c)) return 0;
        }
    }
    return 1;
}

int main(void)
{
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> V >> E;

        init();

        for (int j = 0; j < E; j++){
            int f, s;

            cin >> f >> s;
            make(f, s);
            make(s, f);
        }

        int flag = 0;
        for (int j = 1; j <= V; j++) {
            if (!check[j]) {
                flag = dfs(j, 1);
                if (!flag) break;
            }
        }

        if (flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}
