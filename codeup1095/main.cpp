//
//  main.cpp
//  codeup1049
//
//  Created by 김병수 on 2020/07/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {

    int a,b,c;
    int x = 0;
    
    cin >> a;
    
    for(int i=0;i<a;i++){
        cin >> b;
        c = 1;
        c = c << (b-1);
        x = x|c;
    }
    int result = 1;
    while(true){
        if(x%2 != 0){
            cout << result;
            break;
        }
        x = x>>1;
        result++;
    }
}
