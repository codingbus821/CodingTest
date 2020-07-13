//
//  main.cpp
//  boj9935
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K,ans;
vector<string> v;

void howMany(int cnt, int learn, int index){
    if(index >26) return;
    if(cnt == K){
        int total=0;
        for(int i=0;i<N;i++){
            string s = v[i];
            bool ok = true;
            for(int j=0;j<s.length();j++){
                if(((1<<(s[j]-'a'))& learn) > 0)
                    continue;
                ok=false;
                break;
            }
            if(ok) ++total;
        }
        ans = max(ans,total);
        return;
    }
    if(index == 0 || index == 2 || index == 8 || index == 13 || index == 19)
        howMany(cnt, learn, index+1);
    else{
        if(cnt <= K)
            howMany(cnt+1, (learn | (1<<index)), index+1);
        howMany(cnt, learn, index+1);
    }
}

int main(int argc, const char * argv[]) {
    
    string str;
    
    cin >> N >> K;
    
    if(K<5){
        cout << 0;
        return 0;
    }else if(K == 26){
        cout << N;
        return 0;
    }
    
    K = K-5;
    
    for(int i=0;i<N;i++){
        cin >> str;
        
        v.push_back(str);
    }
    
    int temp = 0;
    temp = temp | (1<<('a'-'a'));
    temp = temp | (1<<('n'-'a'));
    temp = temp | (1<<('t'-'a'));
    temp = temp | (1<<('i'-'a'));
    temp = temp | (1<<('c'-'a'));
    
    howMany(0, temp, 0);
    
    cout << ans;
    
    return 0;
}
