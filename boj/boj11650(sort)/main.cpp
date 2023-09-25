//
//  main.cpp
//  boj11650
//
//  Created by 김병수 on 2021/01/02.
//  Copyright © 2021 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;cin >> N;
    int a,b;
    vector<pair<int, int>> v;
    
    while(N--){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
    
    return 0;
}
