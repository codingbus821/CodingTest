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
    
    int A,B,V;
    
    cin >> A >> B >> V;
    
    if(((V-A)%(A-B)) == 0){
        cout << ((V-A)/(A-B))+1;
    }else{
        cout << ((V-A)/(A-B))+2;
    }
    
    return 0;
}
