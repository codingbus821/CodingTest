//
//  main.cpp
//  boj1932
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 500

using namespace std;

int arr[MAX][MAX];

int main(int argc, const char * argv[]) {
    
    int n;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            arr[i][j] = max(arr[i-1][j-1],arr[i-1][j]) + arr[i][j];
        }
    }

    sort(arr[n-1],arr[n-1]+n);
    
    cout << arr[n-1][n-1];
    
    return 0;
}
