//
//  main.cpp
//  boj1193
//
//  Created by 김병수 on 2020/07/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int X,sum=0;
    int num=0;
    int up,down;
    
    cin >> X;
    
    while(true){
        num++;
        sum = sum + num;
        
        if(sum >= X){
            break;
        }
    }
    
    if(num%2 == 1){
        up=sum-X+1;
        down=num-(sum-X);
    }else{
        up=num-(sum-X);
        down=sum-X+1;
    }
    
    cout << up << "/"<<down;
    
    return 0;
}
