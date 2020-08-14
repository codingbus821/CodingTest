//
//  main.cpp
//  boj1795
//
//  Created by 김병수 on 2020/07/15.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
char arr[51][51] = {0,};
pair<int,int> visit[51][51];
pair<int,int> visit2[51][51];
int direct[8][2]={
    {1,2},
    {-1,2},
    {2,1},
    {-2,1},
    {2,-1},
    {-2,-1},
    {1,-2},
    {-1,-2}
};
int k=0;

int main(int argc, const char * argv[]) {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string str;
    int ans = 10000000;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> str;
        for(int j=0;j<str.size();j++){
            arr[i][j] = str[j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j] != '.'){
                k++;
                queue<pair<int, int>> q;
                int num = arr[i][j] - '0';
                
                q.push(make_pair(i, j));
                
                visit[i][j].first++;
                visit2[i][j].first = 1;
                
                while (!q.empty()) {
                    int h = q.front().first;
                    int w = q.front().second;
                    q.pop();
                    
                    int dh,dw;
                    
                    for(int i=0;i<8;i++){
                        dh = h + direct[i][0];
                        dw = w + direct[i][1];
                        
                        if(dh < 0 || dh >= N || dw < 0 || dw >= M)
                            continue;
                        else if(visit2[dh][dw].first == 0){
                            q.push(make_pair(dh, dw));
                            
                            visit2[dh][dw].first = 1;
                            visit2[dh][dw].second = visit2[h][w].second+1;
                            
                            visit[dh][dw].first++;
                            
                            if(visit2[dh][dw].second % num != 0)
                                visit[dh][dw].second += (visit2[dh][dw].second / num) + 1;
                            else
                                visit[dh][dw].second += (visit2[dh][dw].second / num);
                        }
                    }
                }
            }
            fill(&visit2[0][0], &visit2[0][0] + 51 * 51, make_pair(0, 0));
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visit[i][j].first == k){
                ans = min(ans,visit[i][j].second);
            }
        }
    }
    
    if(ans == 10000000){
        cout << -1;
    }else{
        cout << ans;
    }
    
    return 0;
}
