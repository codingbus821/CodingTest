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
    
    int n;
    
    cin >> n;
    
    for(int i = 1;i<=n;i++){
        if(i%3 == 0){
            printf("X ");
        }else{
            cout << i << " ";
        }
    }
    
    return 0;
}
