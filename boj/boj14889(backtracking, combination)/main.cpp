//
//  main.cpp
//  boj14889
//
//  Created by 김병수 on 2020/08/29.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#define MAX 20

using namespace std;

int N;
int arr[MAX][MAX];
int team[MAX]={0,};
int minn = 10000;

void solve(int cur,int cnt){
    
    if(cnt == N/2){
        int s=0,l=0;
        
        for(int i=0;i<N;i++){
            cout << team[i] << " ";
        }
        cout << "\n";
        
        for(int i=0;i<N;i++){
            if(team[i] == 1){
                for(int j=i+1;j<N;j++){
                    if(team[j] == 1){
                        s = s + arr[i][j];
                        s = s + arr[j][i];
                    }
                }
            }else{
                for(int j=i+1;j<N;j++){
                    if(team[j] == 0){
                        l = l + arr[i][j];
                        l = l + arr[j][i];
                    }
                }
            }
        }
        
        if(s-l<0){
            minn = min(minn,l-s);
        }else{
            minn = min(minn,s-l);
        }
        
        return;
    }
    
    for(int i=0;i<N;i++){
        if(team[i] == 0 && i>cur){
            team[i] = 1;
            solve(i,cnt+1);
            team[i] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    solve(-1,0);
    
    cout << minn;
    
    return 0;
}
