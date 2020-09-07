//
//  main.cpp
//  q1
//
//  Created by 김병수 on 2020/09/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //ababcdcdababcdcd
    //aabbaccc
    string s = "aabbaccc";
    
    int answer=1000;
    
    string tmp;
    
    for(int i=1; i <= s.size()/2; i++){
        string full;
        int count=1;
        tmp = s.substr(0,i);
        
        for(int j=i;j<s.size();j=j+i){
            string tmp2 = s.substr(j,i);
            
            if(!tmp2.compare(tmp)){
                count++;
            }else{
                if(count ==1){
                    full = full + tmp;
                    tmp = tmp2;
                }else{
                    full = full + to_string(count) + tmp;
                    tmp = tmp2;
                    count = 1;
                }
            }
            
            if(i+j >= s.length()){
                if(count == 1){
                    full = full + tmp;
                }else{
                    full = full + to_string(count) + tmp;
                }
                break;
            }

        }
        answer = (full.size() > answer) ? answer : full.length();
        cout << full << "\n";
    }
    
    cout << answer;
    
    return 0;
}
