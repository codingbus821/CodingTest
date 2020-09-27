//
//  main.cpp
//  boj2491
//
//  Created by 김병수 on 2020/09/26.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(int argc, const char * argv[]) {
    
    int N;
    int len=1;
    int ans=1;
    
    cin >> N;
    
    v.resize(N);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    
    for(int i=0;i<N-1;i++){
        if(v[i] <= v[i+1])
            len++;
        else
            len = 1;
        ans = max(ans,len);
    }
    
    len = 1;
    
    for(int i=0;i<N-1;i++){
        if(v[i] >= v[i+1])
            len++;
        else
            len = 1;
        ans = max(ans,len);
    }
    
    cout << ans;
    
    return 0;
}
