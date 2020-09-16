//
//  main.cpp
//  boj1193
//
//  Created by 김병수 on 2020/07/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[26][26]={0,};
int danji_num=0;
int danji_max[314]={0,};
int direct[4][2]={
    {0,-1},
    {1,0},
    {0,1},
    {-1,0}
};

void DFS(int h, int w, int danji_num){
    
    // 방문한곳은 -1으로 처리.
    arr[h][w] = -1;
    
    danji_max[danji_num]++;
    
    int dh;
    int dw;
    int cur_house;
    
    // 상하좌우 확인.
    for(int i=0;i<4;i++){
        dh = h+direct[i][0];
        dw = w+direct[i][1];
        cur_house = arr[dh][dw];
        if(0 <= dh && dh < N && 0 <= dw && dw < N && cur_house==1){
            DFS(dh,dw,danji_num);
        }
    }
}

int search(int N){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == 1){
                // 1이 발견되면 단지를 발견해서 단지수 + 1 해줌.
                danji_num++;
                // 1이 발견되면 그 1부터 DFS를 실행
                DFS(i,j,danji_num);
            }
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    string str;
    
    cin >> N;
    
    // 배열에 입력 넣기.
    for(int i=0;i<N;i++){
        cin >> str;
        for(int j=0;j<N;j++){
            arr[i][j] = str[j]-'0';
        }
    }
    
    // 배열에서 1 찾기.
    search(N);
    
    // 단지내 집의 수 오름차순 정렬
    sort(danji_max+1,danji_max+danji_num+1);
    
    cout << danji_num << "\n";
    
    if(danji_num != 0){
        for(int i=1;i<=danji_num;i++){
            cout << danji_max[i] << "\n";
        }
    }
    
    return 0;
}
