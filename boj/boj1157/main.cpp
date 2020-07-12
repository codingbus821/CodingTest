//
//  main.cpp
//  boj11654
//
//  Created by 김병수 on 2020/07/12.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str;
    
    cin >> str;
    
    int arr[26]={0,};
    int maxx = 0;
    
    for(int i=0;i<str.size();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            arr[str[i]-'A']++;
        }else{
            arr[str[i]-'a']++;
        }
    }
    
    for(int i = 0;i<26;i++){
        if(arr[maxx] < arr[i]){
            maxx = i;
        }
    }
    
    for(int i = 0;i<26;i++){
        if(arr[maxx] == arr[i] && maxx != i){
            maxx = -1;
            break;
        }
    }
    
    if(maxx == -1){
        cout << "?";
    }else{
        cout << char(maxx+'A') ;
    }
    
    return 0;
}
