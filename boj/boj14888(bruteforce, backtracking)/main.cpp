//
//  main.cpp
//  boj14888
//
//  Created by 김병수 on 2020/08/29.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int numarr[11];
int oparr[4];
int minn=1000000000,maxx=-1000000000;

void solve(int cnt, int num){
    
    if(cnt == N-1){
        minn = min(minn,num);
        maxx = max(maxx,num);
        return;
    }
    
    for(int i=0;i<4;i++){
        if(oparr[i] != 0){
            oparr[i]--;
            if(i == 0){
                solve(cnt+1,num+numarr[cnt+1]);
            }else if(i == 1){
                solve(cnt+1,num-numarr[cnt+1]);
            }else if(i == 2){
                solve(cnt+1,num*numarr[cnt+1]);
            }else if(i == 3){
                solve(cnt+1,num/numarr[cnt+1]);
            }
            oparr[i]++;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> numarr[i];
    }
    
    for(int i=0;i<4;i++){
        cin >> oparr[i];
    }
    
    solve(0, numarr[0]);
    
    cout << maxx << " " << minn;
    
    return 0;
}
