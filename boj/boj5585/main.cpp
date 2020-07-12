//
//  main.cpp
//  boj5585
//
//  Created by 김병수 on 2020/07/11.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <array>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    int arr[6]={500,100,50,10,5,1};
    int result=0;
    
    cin >> N;
    
    N=1000-N;
    
    for(int i = 0;i<6;i++){
        if(N==0)
            break;
        
        if(N/arr[i] != 0){
            result=result+(N/arr[i]);
            N = N-(arr[i]* (N/arr[i]));
        }
        
    }
    
    cout << result;
    
    return 0;
}
