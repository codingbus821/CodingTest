//
//  main.cpp
//  boj2263
//
//  Created by 김병수 on 2020/09/21.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> in;
vector<int> post;
int position[100001];

void solve(int is, int ie, int ps, int pe){
    
    if(is > ie or ps > pe) return;
    
    int root = post[pe];
    cout << root << " ";
    int ir = position[root];
    
    int left = ir-is;
    solve(is,ir-1,ps,ps+left-1);
    solve(ir+1,ie,ps+left,pe-1);
    
}

int main(int argc, const char * argv[]) {
    
    int num;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> num;
        in.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        cin >> num;
        post.push_back(num);
    }
    
    for(int i=0;i<n;i++){
        position[in[i]] = i;
    }
    
    solve(0, n-1, 0, n-1);
    
    
    return 0;
}
