//
//  main.cpp
//  boj1018
//
//  Created by 김병수 on 2020/08/14.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[51][51] = {0,};

int main(int argc, const char * argv[]) {
    
    int N,M;
    string str;
    int ans=64;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> str;
        
        for(int j=0;j<str.size();j++){
            if(str[j] == 'B'){
                arr[i][j] = 1;
            }else{
                arr[i][j] = 0;
            }
        }
    }
    
    for(int i=0;i<N-7;i++){
        int wb;
        for(int j=0;j<M-7;j++){
            
            int num = 0;
            int num2 = 0;
            wb = arr[i][j];
            
            for(int x=0;x<8;x++){
                for(int y=0;y<8;y++){
                    if(arr[i+x][j+y] != wb){
                        num++;
                    }else{
                        num2++;
                    }
                    
                    if(wb == 0){
                        wb = 1;
                    }else{
                        wb = 0;
                    }
                }
                if(wb == 0){
                    wb = 1;
                }else{
                    wb = 0;
                }
            }
            
            ans = min(ans,num);
            ans = min(ans,num2);
        }
    }
    
    cout << ans;
    
    return 0;
}
