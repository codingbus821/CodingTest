//
//  main.cpp
//  boj5585
//
//  Created by 김병수 on 2020/07/11.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    int tmp;
    int max=0;
    
    cin >> N;
    
    vector<int> v;
    
    for(int i=0;i<N;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end());
    
    for(int i = 0;i<v.size();i++){
        if(max < v[i]*(N-i))
            max = v[i]*(N-i);
    }
    
    cout << max;
    
    return 0;
}
