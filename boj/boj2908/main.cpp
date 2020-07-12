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
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string n1,n2;
    
    cin >> n1 >> n2;
    
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    
    if(stoi(n1) > stoi(n2)){
        cout << n1;
    }else{
        cout << n2;
    }
    
    return 0;
}
