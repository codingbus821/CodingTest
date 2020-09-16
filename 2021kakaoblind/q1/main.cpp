//
//  main.cpp
//  q1
//
//  Created by 김병수 on 2020/09/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

bool rulecheck(string str){
    
    if(str.length() > 15 || str.length() < 3)
        return false;
    
    if(str[0] == '.' || str[str.length()-1] == '.')
        return false;
    
    int dot = 0;
    
    for(int i=0;i<str.length();i++){
        
        if(dot == 1 && str[i] == '.')
            return false;
        
        dot=0;
        
        if((str[i] < 'a' || str[i] > 'z') && (str[i] > '9' || str[i] < '0')){
            if(str[i] == '.'){
                dot++;
            }
            
            if(str[i] != '-' && str[i] != '_' && str[i] != '.')
                return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    string answer = "";
    string tmp;
    
    string new_id = "123_.def";
    
//    if(rulecheck(new_id)==true)
//        cout << "true";
//    else{
        
        for(int i=0;i<new_id.length();i++){ // 1,2
            if(isalpha(new_id[i]))
                answer += char(tolower(new_id[i]));
            else if((new_id[i] < 'a' || new_id[i] > 'z') && (new_id[i] > '9' || new_id[i] < '0') && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.'){
                    continue;
            }
            else
                answer += new_id[i];
        }
        
        int dotnum = 0;
        
        for(int i=0;i<answer.length();i++){ //
            
            if(answer[i] == '.'){
                dotnum++;
                continue;
            }else{
                if(dotnum != 0){
                    tmp += '.';
                    dotnum = 0;
                }
                tmp += answer[i];
            }
        }
        
        if(tmp[0] == '.')
            tmp.erase(0,1);
        if(tmp[tmp.length()-1] == '.')
            tmp.erase(tmp.length()-1,1);
        
        if(tmp.empty())
            tmp = "a";
        
        if(tmp.length() >= 16)
            tmp.erase(15);
        
        if(tmp[tmp.length()-1] == '.')
            tmp.erase(tmp.length()-1,1);
            
        if(tmp.length() <= 2){
            
            while(tmp.length() < 3){
                tmp += tmp[tmp.length()-1];
            }
        }
        
//    }
    
    cout << tmp << '\n';
        
    
    return 0;
}
