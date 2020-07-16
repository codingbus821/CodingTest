//
//  main.cpp
//  boj2447
//
//  Created by 김병수 on 2020/07/15.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

char arr[3000][3000];

void star(int h, int w, int n){
    if(n==1){
        arr[h][w] = '*';
        return;
    }
    
    int m = n/3;
    int cnt = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cnt++;
            if(cnt != 5)
                star(h+i*m, w+j*m, m);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j]=' ';
        }
    }

    star(0,0,N);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
