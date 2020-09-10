//
//  main.cpp
//  boj5052
//
//  Created by 김병수 on 2020/09/10.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

struct Trie{
    bool finish;
    Trie *next[10];
    
    Trie() : finish(false){ // 생성자
        memset(next,0,sizeof(next));
    }
    ~Trie(){ // 소멸자
        for(int i=0;i<10;i++)
            if(next[i])
                delete next[i];
    }
    
    void insert(char *key){ // insert
        if(*key == '\0')
            finish = true;
        else{
            int cur = *key - '0';
            if(next[cur] == NULL)
                next[cur] = new Trie();
            next[cur]->insert(key+1);
        }
    }
    
    bool find(char *key){ // find
        
        int cur = *key - '0';
        
        if(*key == '\0') // 문자열이 끝날때까지 다른 번호가 접두어인 경우가 없는 경우 true 반환
            return true;
        else if(*(key+1) != '\0' && next[cur]->finish == true) // 다음문자가 남아있는데 다른 번호의 접두어가 발견된 경우 false 반환
            return false;
        return next[cur]->find(key+1);
    }
};

string strarr[10000];

int main(int argc, const char * argv[]) {
    
    int t,n;
    string str;
    
    cin >> t;
    
    for(int i=0;i<t;i++){
        Trie *trie = new Trie();
        bool check = true;
        cin >> n;
        
        for(int j=0;j<n;j++){
            cin >> strarr[j];
            trie->insert(&strarr[j][0]);
        }
        
        for(int j=0;j<n;j++){
            if(trie->find(&strarr[j][0])==false)
                check = false;
        }
        
        if(check == true)
            cout << "YES\n";
        else
            cout << "NO\n";
        delete trie;
    }
    
    return 0;
}
