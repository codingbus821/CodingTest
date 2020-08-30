//
//  main.cpp
//  boj2580
//
//  Created by 김병수 on 2020/08/27.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#define MAX 9

using namespace std;

int MAP[MAX][MAX];
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];

void Input(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> MAP[i][j];
            if(MAP[i][j] != 0){
                Row[i][MAP[i][j]] = true;
                Col[j][MAP[i][j]] = true;
                Square[(i/3)*3 + (j/3)][MAP[i][j]] = true;
            }
        }
    }
}

void Print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void DFS(int cnt){
    int x = cnt / MAX;
    int y = cnt % MAX;
    
    if(cnt == 81){
        Print();
        exit(0);
    }
    
    if(MAP[x][y] == 0){
        for(int i = 1;i<=9;i++){
            if(Row[x][i] == false && Col[y][i] == false && Square[(x/3)*3+(y/3)][i] == false){
                Row[x][i] = true;
                Col[y][i] = true;
                Square[(x/3)*3+(y/3)][i] = true;
                MAP[x][y] = i;
                DFS(cnt+1);
                MAP[x][y] = 0;
                Row[x][i] = false;
                Col[y][i] = false;
                Square[(x/3)*3+(y/3)][i] = false;
            }
        }
    }
    else DFS(cnt + 1);
}

void Solution(){
    DFS(0);
}

void Solve(){
    Input();
    Solution();
}

int main(int argc, const char * argv[]) {
    
    Solve();
    
    return 0;
}
