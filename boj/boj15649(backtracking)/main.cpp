//
//  main.cpp
//  boj15649
//
//  Created by 김병수 on 2020/08/24.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int N,M;
int arr[9]={0,};
bool visited[9];

void func(int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++)
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            func(cnt+1);
            visited[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    
    func(0);
    return 0;
}
