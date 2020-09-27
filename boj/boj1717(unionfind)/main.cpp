//
//  main.cpp
//  boj1717
//
//  Created by 김병수 on 2020/09/26.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

// 모든 함수는 call by reference로 arr의 값은 함수 밖에서도 바뀜.
int getParent(int arr[], int x){ // 여기서 재귀적으로 호출하며 Parent를 갱신함.
    if(arr[x] == x) return x;
    return arr[x] = getParent(arr, arr[x]);
}

void unionParent(int arr[],int a,int b){
    int aParent = getParent(arr, a);
    int bParent = getParent(arr, b);
    if(aParent < bParent)
        arr[bParent] = aParent;
    else
        arr[aParent] = bParent;
}

void findParent(int arr[], int a, int b){
    int aParent = getParent(arr, a);
    int bParent = getParent(arr, b);
    if(aParent == bParent)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    int n, m; cin >> n >> m;
    int arr[n+1];
    
    for(int i=0;i<=n;i++){
        arr[i] = i;
    }
    
    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        
        if(a == 0){
            unionParent(arr,b,c);
        }else{
            findParent(arr, b, c);
        }
    }
    
    return 0;
}
