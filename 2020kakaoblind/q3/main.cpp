//
//  main.cpp
//  q3
//
//  Created by 김병수 on 2020/09/10.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ksize;
int lsize;

vector<vector<int>> rotatekey(vector<vector<int>> key){
    
    vector<vector<int>> tmp(ksize,vector<int>(ksize));
    
    for(int i=0;i<ksize;i++){
        for(int j=0;j<ksize;j++){
            tmp[i][j] = key[ksize-1-j][i];
        }
    }
    
    return tmp;
}

bool check(int w,int h,vector<vector<int>> arr,vector<vector<int>> key){
    
    for(int w=0;w<ksize+lsize-1;w++){
        for(int h=0;h<ksize+lsize-1;h++){
            
            bool ret = true;
            vector<vector<int>> tmparr = arr;
            
             for(int i=0;i<ksize;i++){
                 for(int j=0;j<ksize;j++){
                     tmparr[w+i][h+j] += key[i][j];
                 }
             }
            
            for(int i=0;i<lsize;i++){
                for(int j=0;j<lsize;j++){
                    if(tmparr[ksize-1+i][ksize-1+j] != 1)
                        ret = false;
                }
            }
            if(ret == true)
                return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    
    bool answer = false;
    
    ksize = key.size();
    lsize = lock.size();
    
    vector<vector<int>> arr((2*ksize)-2+lsize, vector<int>((2*ksize)-2+lsize));
    
    for(int i=0;i<lsize;i++){
        for(int j=0;j<lsize;j++){
            arr[ksize-1+i][ksize-1+j] = lock[i][j];
        }
    }
    
    vector<vector<int>> tmpkey = key;
    
    for(int i=0;i<4;i++){
        
        for(int w=0;w<lsize+ksize-1;w++){
            for(int h=0;h<lsize+ksize-1;h++){
                if(check(w,h,arr, tmpkey) == true){
                    answer = true;
                    break;
                }
            }
        }
        
        
        tmpkey = rotatekey(tmpkey);
    }
    
    
    return answer;
}
