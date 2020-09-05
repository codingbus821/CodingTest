//
//  main.cpp
//  boj10816
//
//  Created by 김병수 on 2020/09/01.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

int lower(int target, int size){
    
    int start , end , mid;
    start = 0;
    end = size;
    
    while(end > start){
        mid = (start+end)/2;
        if(arr[mid] >= target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int upper(int target, int size){
    
    int start , end , mid;
    start = 0;
    end = size;
    
    while(end > start){
        mid = (start+end)/2;
        if(arr[mid] > target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    int M;
    int num;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    
    cin >> M;
    
    for(int i=0;i<M;i++){
        cin >> num;
        
        int low, high;
        
        low = lower(num, N);
        high = upper(num , N);
        
        cout << high-low << " " ;
    }
    
    return 0;
}
