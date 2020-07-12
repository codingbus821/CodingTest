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
    
    string str;
    cin >> str;
    
    int idx;
    for(int i = 'a';i<='z';i++){
        idx = str.find(i);
        cout << idx << " ";
    }
    
    return 0;
}
