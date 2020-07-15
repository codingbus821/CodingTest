//
//  main.cpp
//  boj11724
//
//  Created by 김병수 on 2020/07/14.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int w,h;
int arr[51][51]={0,};
int direct[8][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1},
    {1,1},
    {1,-1},
    {-1,1},
    {-1,-1}
};

void DFS(int ph, int pw){
    int dh,dw;
    
    arr[ph][pw] = 0;
    
    for(int i=0;i<8;i++){
        dh = ph;
        dw = pw;
        
        dh = dh+direct[i][0];
        dw = dw+direct[i][1];
        
        if(arr[dh][dw] == 1){
            DFS(dh,dw);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int ans;
    
    while(true){
        ans=0;
        
        cin >> w >> h;
        
        if(!w && !h)
            break;
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(arr[i][j] == 1){
                    ans++;
                    DFS(i,j);
                }
            }
        }
        
        cout << ans << "\n";
    }
        
    return 0;
}
