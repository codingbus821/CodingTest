//
//  main.cpp
//  boj1436
//
//  Created by 김병수 on 2020/08/14.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    int s=0;
    int ch=0;
    
    cin >> N;
    
    while(true){
        string str = to_string(s);
        if(str.find("666") != string::npos){
            ch++;
        }
        if(ch == N){
            cout << str;
            break;
        }
        s++;
    }
    
    return 0;
}
