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

using namespace std;

int N,M;
int arr[51][51]={0,};
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
vector<tuple<int,int,int>> v;
int ans = -1;

void DFS(int idx, int h, int w, int cnt){
    
    int dh,dw;
    
    if(idx > (v.size()-1))
        return;
    
    for(int i=0;i<8;i++){
        
        dh = h + direct[i][0];
        dw = w + direct[i][1];
        
        
        
        if(dh >=0 && dh<N && dw>=0 && dw<M){
            arr[h][w] = 0;
            arr[dh][dw] = 1;
            
            DFS(idx+1, dh, dw, cnt+1);
            
            arr[h][w] = 1;
            arr[dh][dw] = 0;
        }
    }
    
    ans = max(ans,cnt);
    
}

int main(int argc, const char * argv[]) {
    
    string str;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> str;
        for(int j=0;j<str.size();j++){
            if(str[j] == '.')
                continue;
            else{
                v.push_back(make_tuple(str[j] - '0',i,j));
                arr[i][j] = str[j] - '0';
            }
        }
    }
    
    DFS(0,get<1>(v[0]),get<2>(v[0]),1);
    
    cout << ans;
    
    
    return 0;
}
