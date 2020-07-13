//
//  main.cpp
//  boj1193
//
//  Created by 김병수 on 2020/07/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    long long T,x,y;
    long long dist;
    long long ch=1;
    long long sum = 0;
    long long ans = 0;
    
    cin >> T;
    
    for(int i=0;i<T;i++){
        cin >> x >> y;
        
        dist = y-x;
        
        sum = 0;
        ans = 0;
        ch = 1;
        
        while(sum < dist){
            
            sum = sum + ch;
            ans++;
            if(sum >= dist){
                break;
            }
            sum = sum + ch;
            ans++;
            if(sum >= dist){
                break;
            }
            
            ch++;
        }
        cout << ans << "\n";
        
    }
    
    return 0;
}
