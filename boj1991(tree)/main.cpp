//
//  main.cpp
//  boj1991
//
//  Created by 김병수 on 2020/09/21.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<char> v[27];

void Pre(int p){
    cout << v[p][0];
    
    if(v[p][1] != '.')
        Pre(v[p][1]-'A');
    
    if(v[p][2] != '.')
        Pre(v[p][2]-'A');
}

void In(int p){
    
    if(v[p][1] != '.')
        In(v[p][1]-'A');
    
    cout << v[p][0];
    
    if(v[p][2] != '.')
        In(v[p][2]-'A');
}

void Post(int p){
    
    if(v[p][1] != '.')
        Post(v[p][1]-'A');
    
    if(v[p][2] != '.')
        Post(v[p][2]-'A');
    
    cout << v[p][0];
}

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        char p,l,r;
        
        cin >> p >> l >> r;
        
        v[p-'A'].push_back(p);
        v[p-'A'].push_back(l);
        v[p-'A'].push_back(r);
    }
    
    Pre(0);
    cout << '\n';
    In(0);
    cout << '\n';
    Post(0);
    
    return 0;
}
