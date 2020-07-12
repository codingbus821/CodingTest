//
//  main.cpp
//  boj11399
//
//  Created by 김병수 on 2020/07/09.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(int argc, const char * argv[]) {
    
    int N, n1, n2;
    
    cin >> N;
    
    vector <pair<int,int>> v;
    
    int result = 0;
    
    for(int i=0;i<N;i++){
        cin >> n1 >> n2;
        v.push_back(make_pair(n1, n2));
    }
    
    sort(v.begin(),v.end(),cmp);
    
    int last = v[0].second;
    
    for(int i = 1;i<N;i++){
        if(last <= v[i].first){
            last = v[i].second;
            result++;
        }
    }
    
    cout << ++result;
    
    return 0;
}
