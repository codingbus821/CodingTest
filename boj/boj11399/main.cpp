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
    
    int N;
    int arr[1001];
    int tmp=0;
    int result=0;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    
    for(int i=0;i<N;i++){
        tmp = tmp + arr[i];
        result = result+tmp;
    }
    
    cout << result;
    
    return 0;
}
