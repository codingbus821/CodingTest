//
//  main.cpp
//  boj9935
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str,c;
    char arr[1000001];
    int arr_cur = 0;
    
    cin >> str >> c;
    
    for(int i = 0;i<str.size();i++){
        
        arr[arr_cur] = str[i];
        
        if(arr[arr_cur] == c[c.size()-1]){
            bool ch = true;
            // 폭발 문자열 확인, 폭발 문자열이 아니면 false
            for(int j = 1;j<c.size();j++){
                if(arr[arr_cur-j] != c[c.size()-j-1]){
                    ch = false;
                    break;
                }
            }
            //
            if(ch == true){
                arr_cur = arr_cur - c.size();
            }
        }
        arr_cur++;
    }
    
    if(arr_cur == 0){
        cout << "FRULA";
    }else{
        for(int i = 0;i<arr_cur;i++){
            cout << arr[i];
        }
    }
    
    return 0;
}
