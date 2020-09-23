//
//  main.cpp
//  boj1504
//
//  Created by 김병수 on 2020/09/24.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr[801];

int ans = -1;

int main(int argc, const char * argv[]) {
    
    int N,E;
    int a,b,c;
    int v,vv;
    
    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }
    
    cin >> v >> vv;
    
    return 0;
}
