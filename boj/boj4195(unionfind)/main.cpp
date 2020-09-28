//
//  main.cpp
//  boj4195
//
//  Created by 김병수 on 2020/09/29.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int parent[222222];
int netnum[222222];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    // 부모가 작은 곳에 netnum을 더해 줌.
    if(a<b){
        parent[b] = a;
        netnum[a] = netnum[a] + netnum[b];
        netnum[b] = 0;
        return netnum[a];
    }else if (a>b){
        parent[a] = b;
        netnum[b] = netnum[a] + netnum[b];
        netnum[a] = 0;
        return netnum[b];
    }
    return netnum[a]; // 부모가 같으면 둘 중 하나를 골라 출력.
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상
    
    int tc; cin >> tc;
    
    while(tc--){
        map<string,int> m; // map을 사용해 string 으로 주어지는 노드의 이름을 int로 바꿔줌.
        string f1, f2;
        int count = 1; // 노드는 1부터 시작.
        int f; cin >> f;
        
        for(int i = 1;i<=2*f;i++){
            parent[i] = i; // parent 초기화
            netnum[i] = 1; // 노드들의 네트워크에 몇 명이 있는지 구하기위해 처음엔 1로 초기화 한 후 노드들이 연결될때마다 갱신해줌.
        }
        
        for(int i=0;i<f;i++){

            cin >> f1 >> f2;
            
            // map에 해당하는 key 값이 있는지 확인 없으면 int값을 1씩 증가시키며 추가.
            if(m.count(f1) == 0)
                m[f1] = count++;
            if(m.count(f2) == 0)
                m[f2] = count++;
            
            // 노드를 연결시키고 해당 노드 네트워크안에 총 노드의 수 출력
            cout << unionParent(m[f1], m[f2]) << '\n';
        }
    }
    
    return 0;
}
