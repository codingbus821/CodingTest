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
        if(n[i] == 'A' || n[i] == 'B' || n[i] == 'C'){
            result = result + 3;
        }else if(n[i] == 'D' || n[i] == 'E' || n[i] == 'F'){
            result = result + 4;
        }else if(n[i] == 'G' || n[i] == 'H' || n[i] == 'I'){
            result = result + 5;
        }else if(n[i] == 'J' || n[i] == 'K' || n[i] == 'L'){
            result = result + 6;
        }else if(n[i] == 'M' || n[i] == 'N' || n[i] == 'O'){
            result = result + 7;
        }else if(n[i] == 'P' || n[i] == 'Q' || n[i] == 'R' || n[i] == 'S'){
            result = result + 8;
        }else if(n[i] == 'T' || n[i] == 'U' || n[i] == 'V'){
            result = result + 9;
        }else if(n[i] == 'W' || n[i] == 'X' || n[i] == 'Y' || n[i] == 'Z'){
            result = result + 10;
        }
    }
    
    cout << result;
    
    return 0;
}
