//
//  main.cpp
//  boj1463
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[1000001];

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    
    for(int i=4;i<N+1;i++){
        if(i % 3 == 0){
            arr[i] = min(1 + arr[i/3],1 + arr[i-1]);
        }else if(i % 2 == 0){
            arr[i] = min(1 + arr[i/2],1 + arr[i-1]);
        }else{
            arr[i] = 1 + arr[i-1];
        }
    }
    
    cout << arr[N];
    
    return 0;
}
