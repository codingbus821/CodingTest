//
//  main.cpp
//  boj1003
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int arr[41][2];

int main(int argc, const char * argv[]) {
    
    int T;
    
    cin >> T;
    
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
    
    for(int i=2;i<41;i++){
        arr[i][0] = arr[i-2][0] + arr[i-1][0];
        arr[i][1] = arr[i-2][1] + arr[i-1][1];
    }
    
    for(int i=0;i<T;i++){
        int num;
        
        cin >> num;
        
        cout << arr[num][0] << " " << arr[num][1] << "\n";
    }
    
    return 0;
}
