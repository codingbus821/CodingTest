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
    
    long long int a,b,c,d;
    
    cin >> a >> b >> c;
    
    printf("%.2f MB",(float)(a*b*c)/8/1024/1024);
    
    return 0;
}
