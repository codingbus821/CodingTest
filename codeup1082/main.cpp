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
    
    int k;
    
    scanf("%x",&k);
    
    for(int i=1;i<16;i++){
        printf("%X*%X=%X\n",k,i,k*i);
    }
    
    return 0;
}
