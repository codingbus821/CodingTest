//
//  main.cpp
//  boj15651
//
//  Created by 김병수 on 2020/08/24.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#define MAX 8

using namespace std;

int N,M;
int arr[MAX]={0,};

void func(int cnt){
    
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=1;i<=N;i++){
        arr[cnt] = i;
        func(cnt+1);
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    func(0);
    
    return 0;
}
