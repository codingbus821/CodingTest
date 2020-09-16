//
//  main.cpp
//  bfs
//
//  Created by 김병수 on 2020/09/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int direct[4][2]={
    {0,1},//상
    {-1,0},//좌
    {0,-1},//하
    {1,0}//우
};

int ans=INT_MAX;
int now = 0; // 1 상 2 좌 3 하 4 우

void bfs(int h,int w,int cnt,int max,vector<vector<int>> map){
    if(h == max-1 && w == max-1){
        ans = min(ans,cnt);
        return;
    }
    
    int dh;
    int dw;
    
    if(now == 0){
        
    }
    
    // 상하좌우 확인.
    for(int i=0;i<4;i++){
        dh = h+direct[i][0];
        dw = w+direct[i][1];
        if(0 <= dh && dh < max && 0 <= dw && dw < max && map[dh][dw] == 0){
            map[dh][dw] = 1;
            bfs(dh,dw,cnt+1,max,map);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> maze = {{0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}, {1, 0, 1, 0}};
    
    int answer = 0;
    
//    cout << maze.size();
        
    bfs(0,0,0,4,maze);
    
    cout << ans;
    
    return 0;
}
