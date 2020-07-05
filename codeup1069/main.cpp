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
    char a;
    
    cin >> a ;
    
    switch (a) {
        case 'A':
            cout << "best!!!";
            break;
            case 'B':
                cout << "good!!";
                break;
            case 'C':
                cout << "run!";
                break;
            case 'D':
                cout << "slowly~";
                break;
            
        default:
            cout << "what?";
            break;
    }
    
    return 0;
}
