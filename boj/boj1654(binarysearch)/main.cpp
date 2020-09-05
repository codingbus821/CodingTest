//
//  main.cpp
//  boj1654
//
//  Created by 김병수 on 2020/09/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int main(int argc, const char * argv[]) {
    
    int K, N;
    long long arr[MAX];
    long long left=1, right=0,mid;
    
    cin >> K >> N;
    
    for(int i=0;i<K;i++){
        cin >> arr[i];
        right = max(arr[i],right);
    }
    
    while(left <= right){
        long long result=0;
        mid=(left+right)/2;
        
        for(int i=0;i<K;i++){
            result = result + arr[i]/mid;
        }
        
        if(result < N)
            right = mid-1;
        else
            left = mid+1;
    }
    
    cout << right;
    
    return 0;
}
