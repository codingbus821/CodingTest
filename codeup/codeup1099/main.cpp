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
    
    int board[10][10];
    int x=1,y=1;
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> board[i][j];
        }
    }
    
    while(true){
        if(board[x][y] == 2){
            board[x][y] = 9;
            break;
        }else if(board[x][y+1] == 1){
            if(board[x+1][y] == 1){
                board[x][y] = 9;
                break;
            }else{
                board[x][y] = 9;
                x++;
            }
        }else{
            board[x][y] = 9;
            y++;
        }
    }
    
    for (int i=0; i<10; i++) {
        for(int j=0;j<10;j++){
            cout << board[i][j] << " ";
        }
        printf("\n");
    }
    
    
    
    
}
