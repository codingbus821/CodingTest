//
//  main.cpp
//  boj4949
//
//  Created by 김병수 on 2023/09/25.
//  Copyright © 2023 coconut. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true)
    {
        string str;
        stack<char> s;
        
        getline(cin, str);
        
        if (str == ".")
            break;
        
        bool flag = true;
        
        for (int i = 0; i < str.length(); i++){
            if (str[i] == '[' || str[i] == '(')
                s.push(str[i]);
            
            else if (str[i] == ']'){
                if (s.empty() || s.top() == '('){
                    flag = false;
                    break;
                }
                else if (s.top() == '[')
                    s.pop();
            }
            
            else if (str[i] == ')'){
                if (s.empty() || s.top() == '['){
                    flag = false;
                    break;
                }
                else if (s.top() == '(')
                    s.pop();
            }
        }
        
        if(s.empty() && flag == true)
            cout << "yes\n";
        else
            cout << "no\n";
            
    }
    
    return 0;
}
