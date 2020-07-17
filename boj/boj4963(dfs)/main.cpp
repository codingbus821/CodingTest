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

// DFS하면서 상하좌우 대각선 중 1인것을 모두 0으로 바꿈.
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
        
        if(!w && !h) // 둘다 0이면 break
            break;
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        
        // 모두 탐색하면서 1이면 ans를 하나 늘리고 DFS 실행.
        // DFS가 진행되면서 주위에 1들을 모두 0으로 바뀜.
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
