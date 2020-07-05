//
//  main.cpp
//  codeup1049
//
//  Created by 김병수 on 2020/07/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int h,w,n;
    
    cin >> h >> w;
    cin >> n;
    
    int board[h][w];
    
    for (int i=0; i<h; i++) {
        for(int j=0;j<w;j++){
            board[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++){
        int l,d,x,y;
        cin >> l >> d >> x >> y;
        
        for(int j=0;j<l;j++){
            if(d==0){
                board[x-1][y-1] = 1;
                y++;
            }else{
                board[x-1][y-1] = 1;
                x++;
            }
        }
    }
    
    for (int i=0; i<h; i++) {
        for(int j=0;j<w;j++){
            cout << board[i][j] << " ";
        }
        printf("\n");
    }
    
    
    
    
}
