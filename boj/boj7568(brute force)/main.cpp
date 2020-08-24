//
//  main.cpp
//  boj7568
//
//  Created by 김병수 on 2020/07/20.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main(int argc, const char * argv[]) {
    
    int N;
    int a,b;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }
    
    for(int i=0;i<N;i++){
        int num = 1;
        
        for(int j=0;j<N;j++){
            if(i==j)
                continue;
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                num++;
            }
        }
        
        cout << num << " ";
    }
    
    return 0;
}
