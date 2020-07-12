//
//  main.cpp
//  boj11654
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str;
    int result = 0;
    
    getline(cin, str);
    
    for(int i=0;i<str.size();i++){
        if(str[i] == ' '){
            result++;
        }
        if(i == (str.size()-1) && str[i] == ' '){
            result--;
        }
        if(i == 0 && str[i] == ' '){
            result--;
        }
    }
    
    cout << ++result;
    
    return 0;
}
