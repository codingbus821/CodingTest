//
//  main.cpp
//  boj1976
//
//  Created by 김병수 on 2020/09/27.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int getParent(int arr[], int x){
    if(arr[x] == x) return x;
    return arr[x] = getParent(arr, arr[x]);
}

void unionParent(int arr[], int a, int b){
    a = getParent(arr, a);
    b = getParent(arr, b);
    
    if(a<b){
        arr[b] = a;
    }else{
        arr[a] = b;
    }
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상
    
    int N, M; cin >> N >> M;
    int arr[N];
    int tmp, firstparent;
    
    for(int i=0;i<N;i++){
        arr[i] = i;
    }
    
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            cin >> tmp;
            if(tmp == 1){
                unionParent(arr, i, j);
            }
        }
    }
    
    cin >> tmp;
    
    firstparent = getParent(arr, tmp-1);
    
    for(int i=1;i<M;i++){
        cin >> tmp;
        tmp = getParent(arr, tmp-1);
        if(firstparent != tmp) {
            cout <<"NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    
    return 0;
}
