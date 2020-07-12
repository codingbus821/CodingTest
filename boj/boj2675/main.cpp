//
//  main.cpp
//  boj11654
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    
    cin >> T;
    
    vector<pair<int, string>> v;
    
    int R;
    string S;
    
    for(int i = 0;i<T;i++){
        cin >> R >> S;
        v.push_back(make_pair(R, S));
    }
    
    for(int j = 0;j<v.size();j++){
        for(int k=0;k<v[j].second.size();k++){
            for(int z=0;z<v[j].first;z++){
                cout << v[j].second[k];
            }
        }
        cout << "\n";
    }
    
    return 0;
}
