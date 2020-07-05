//
//  main.cpp
//  codeup1049
//
//  Created by 김병수 on 2020/07/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int x;
    int a = 1;
    int sum = 0;
    
    cin >> x;
    
    while(true){
        
        sum = sum + (a++);
        
        if(x <= sum){
            cout << --a;
            break;
        }
    }
    
    return 0;
}
