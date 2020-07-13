//
//  main.cpp
//  boj1193
//
//  Created by 김병수 on 2020/07/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T,H,W,N;
    
    cin >> T;
    
    for(int i=0;i<T;i++){
        cin >> H >> W >> N;
        if(N%H == 0){
            cout << H;
            printf("%02d\n",N/H);
        }else{
            cout << N%H;
            printf("%02d\n",N/H+1);
        }
    }
    
    return 0;
}
