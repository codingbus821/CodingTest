//
//  main.cpp
//  boj2252
//
//  Created by 김병수 on 2020/09/25.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

#define MAX 32001

using namespace std;

int N, M;
vector<int> arr[MAX];
int inDegree[MAX];

void topologysort(){
    int result[MAX];
    queue<int> q;
    
    for(int i=1;i<=N;i++){ // 먼저 진입차수가 0인것을 큐에 넣음.
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    for(int i=1;i<=N;i++){ // 위상 정렬 실행.
        //한 번에 하나씩 큐에서 pop하고 result에 넣으므로 총 N번이면 위상정렬이 끝남.
        
        if(q.empty()){ // 큐가 비면 사이클이 있음.
            return;
        }
        
        int x = q.front();
        q.pop();
        result[i] = x; // 결과값을 넣어 줌.
        
        for(int j = 0;j<arr[x].size();j++){ // 현재 노드에 연결된 간선을 제거하고 간선을 제거당한 노드의 진입차수를 확인함.
            if(--inDegree[arr[x][j]] == 0){
                q.push(arr[x][j]);
            }
        }
    }
    
    for(int i=1;i<=N;i++){ // 결과 출력.
        cout << result[i] << " ";
    }
}

int main(int argc, const char * argv[]) {
    
    int A, B;
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++){ // 벡터를 이용해 방향 그래프를 만들고 진입차수를 계산함.
        cin >> A >> B;
        arr[A].push_back(B);
        inDegree[B]++;
    }
    
    topologysort();
    
    return 0;
}
