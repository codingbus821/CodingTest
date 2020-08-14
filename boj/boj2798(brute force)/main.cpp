//
//  main.cpp
//  boj2798
//
//  Created by 김병수 on 2020/07/18.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int ans;
vector<int> v;

// idx는 브루트포스를 시작할 vector v의 인덱스
// sum은 현재까지의 합
// cnt는 선택된 숫자의 개수
void bf(int idx, int sum, int cnt){
    
    /* 이런 조건을 사용하는것이 최적이라는 것을 증명할 수 없다면, 아예 사용해서는 안됨.
    if(sum > M || idx >= N || cnt > 3){
        return;
    }
    */
    
    // cnt가 3이고 sum이 M보다 작거나 같을때 sum과 ans중 큰것을 ans로 갱신.
    if(cnt == 3 && sum <= M){
        ans = max(ans,sum);
        return;
    }
    //
    
    // idx가 카드의 개수N과 같거나 크면 break;
    if(idx >= N){
        return;
    }
    //
    
    // idx 0 부터 시작해서 +1을 해가면서 0->1->2, 0->1->3 이런 순서로 브루트 포스 진행.
    for(int i=idx;i<v.size();i++){
        bf(i+1,sum+v[i],cnt+1);
    }
    //
}

int main(int argc, const char * argv[]) {
    
    int tmp;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end());
    
    // v의 0번부터 브루트포스
    bf(0,0,0);
    
    cout << ans;
    
    return 0;
}
