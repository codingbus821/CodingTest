//
//  main.cpp
//  boj11399
//
//  Created by 김병수 on 2020/07/09.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N,K;
    int arr[11];
    int result=0;
    
    cin >> N >> K;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    N--;
    
    while(true){
        result = result + K/arr[N];
        if(K/arr[N] > 0){
            K = K - (arr[N] * (K/arr[N]));
        }
        if(K==0){
            break;
        }
        N--;
    }
    
    cout << result;
    
    return 0;
}
