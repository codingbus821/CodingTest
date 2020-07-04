//
//  main.cpp
//  codeup1045
//
//  Created by 김병수 on 2020/07/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    long long n, m;
    
    cin >> n >> m;
    
    cout << n+m << "\n";
    cout << n-m << "\n";
    cout << n*m << "\n";
    cout << n/m << "\n";
    cout << n%m << "\n";
    printf("%.2f",(float)n/(float)m);
}
