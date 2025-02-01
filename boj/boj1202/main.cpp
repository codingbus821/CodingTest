//
//  main.cpp
//  boj1202
//
//  Created by 김병수 on 2024/06/28.
//  Copyright © 2024 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

pair<int,int> jew[300001];
int bag[300001];
priority_queue<int> pq;

int main() {
    
    cin >> N >> K;
    
    for(int i=0;i<N;++i){
        cin >> jew[i].first >> jew[i].second;
    }
    for(int i=0;i<K;++i){
        cin >> bag[i];
    }
    
    sort(jew,jew+N);
    sort(bag,bag+K);
    
    int idx = 0;
    long long sum = 0;
    
    for(int i=0;i<K;i++){
        while(idx < N && bag[i] >= jew[idx].first){
            pq.push(jew[idx].second);
            idx++;
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    
    cout << sum;
    
    return 0;
}
