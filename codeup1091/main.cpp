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

    int a,b,c,d;
    
    long long result;
    
    cin >> a >> b >> c >> d;
    
    result = a;
    
    for(int i=0;i<d-1;i++){
        result = result * b + c;
    }
    
    cout << result;
}
