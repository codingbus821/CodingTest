//
//  main.cpp
//  boj9461
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

long long arr[101]={1,1,1,2,2};

int main(int argc, const char * argv[]) {
    
    int T;
    
    cin >> T;
    
    for(int i=5;i<100;i++){
        arr[i] = arr[i-1] + arr[i-5];
    }
    
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        
        cout << arr[n-1] << "\n";
    }
    
    return 0;
}
