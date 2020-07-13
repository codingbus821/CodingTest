//
//  main.cpp
//  boj1193
//
//  Created by 김병수 on 2020/07/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[101][101]={0,};
int virused[101]={0,};
int ans=0;

void DFS(int a,int nodenum){
    
    virused[a] = 1;
    ans++;
    
    for(int i=1;i<=nodenum;i++)
    {
        if(virused[i] == 0 && arr[a][i] == 1){
            DFS(i,nodenum);
        }
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    
    int a,b;
    int x,y;
    
    cin >> a >> b;
    
    for(int i=0;i<b;i++){
        cin >> x >> y;
        
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
    DFS(1,a);
    
    cout << --ans;
    
    return 0;
}
