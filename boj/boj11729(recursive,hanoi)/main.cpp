//
//  main.cpp
//  boj11729
//
//  Created by 김병수 on 2020/07/16.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

void move(int from, int to)
{
    printf("%d %d\n", from, to);
}

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
        move(from, to);
    else
    {
        hanoi(n - 1, from, to, by);
        move(from, to);
        hanoi(n - 1, by, from, to);
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    cout << ((1<<N)-1) << "\n";
    
    hanoi(N, 1, 2, 3);
    
    return 0;
}
