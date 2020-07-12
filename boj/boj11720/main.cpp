//
//  main.cpp
//  boj11654
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    char c;
    int result = 0;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> c;
        result = result + (c-'0');
    }
    
    cout << result;
    
    return 0;
}
