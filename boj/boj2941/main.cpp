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
    
    string n;
    int result = 0;
    
    cin >> n;
    
    for(int i=0;i<n.size();i++){
        if(n[i] == '-'){
            result = result + 1;
        }else if((n[i] == 'j' && i >=0) && (n[i-1] == 'l' || n[i-1] == 'n')){
            result = result + 1;
        }else if(n[i] == '='){
            if(n[i-2] == 'd' && n[i-1] == 'z'){
                result = result + 2;
            }else{
                result = result + 1;
            }
        }
    }
    
    cout << n.size()-result;
    
    return 0;
}
