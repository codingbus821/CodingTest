//
//  main.cpp
//  boj11728
//
//  Created by 김병수 on 2024/06/27.
//  Copyright © 2024 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M;

int a[1000001]={1000000001,}, b[1000001]={1000000001,};

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    
    for(int i=0;i<M;i++){
        cin >> b[i];
    }
    
    int j=0,k=0;
    
    while(j<N && k < M){
        if(a[j] < b[k])
            cout << a[j++] << " ";
        else
            cout << b[k++] << " ";
    }
    
    while (j<N) cout << a[j++]<< " ";
    while (k<M) cout << b[k++]<< " ";
    
    return 0;
}
