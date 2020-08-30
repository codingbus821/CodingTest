//
//  main.cpp
//  boj9663
//
//  Created by 김병수 on 2020/08/24.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 15+1

using namespace std;

int N;
int ans = 0;
int arr[MAX];
bool hvisited[MAX];
vector<pair<int, int>> v;

// dfs 과정중 pruning을 위하여 isPossible함수를 만듬.
bool isPossible(int h, int w){
    
    // 같은 열에 있는지 확인.
    if(hvisited[w]){
        return false;
    }
    
    // 이전의 행의 퀸의 위치와 그 위치의 +1, -1 열에 위치에 있는지 확인.
    if(!v.empty() && (w == v.back().second || w == v.back().second+1 || w == v.back().second-1)){
        
        return false;
    }
    
    // 대각선 확인.
    for(int j=0;j<v.size();j++){
        if(v[j].first-h == v[j].second-w || v[j].first-h == w-v[j].second){
            return false;
        }
    }
    
    return true;
}

//dfs를 통해 문제해결
void func(int cnt){
    
    if(cnt == N){
        ans++;
        return;
    }
    
    for(int i=1;i<=N;i++){
        if(isPossible(cnt+1,i)){
            hvisited[i] = true;
            arr[cnt] = i;
            v.push_back(make_pair(cnt+1, i));
            func(cnt+1);
            v.pop_back();
            hvisited[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    func(0);
    
    cout << ans;
    
    return 0;
}
