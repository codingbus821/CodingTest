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

    int a,b,c;
    
    long long day = 1;
    
    cin >> a >> b >> c;
    
    
    while((day%a != 0)||(day%b != 0)||(day%c != 0))
        day++;
    
    
    
    cout << day;
}
