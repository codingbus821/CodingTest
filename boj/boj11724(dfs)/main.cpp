//
//  main.cpp
//  boj11724
//
//  Created by 김병수 on 2020/07/14.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int N,M;
int arr[1001][1001]={0,};
int visited[1001]={0,};
int ans=0;

void DFS(int s){
    int i = 0;
    visited[s] = 1;
    for(i=1;i<=N;i++){
        if(arr[s][i] && !visited[i]){
            DFS(i);
        }
    }
    if(i == N)
        return;
}

int main(int argc, const char * argv[]) {
    
    int h,w;
    
    cin >> N >> M;
    
    // 배열로 입력받기
    for(int i=0;i<M;i++){
        cin >> h >> w;
        
        arr[h][w] = 1;
        arr[w][h] = 1;
    }
    
    // 간선을 찾기 위한 DFS
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            ans++;
            DFS(i);
        }
    }
    
    cout << ans;
        
    return 0;
}
