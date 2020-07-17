//
//  main.cpp
//  boj7562
//
//  Created by 김병수 on 2020/07/17.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,I;
int fromto[2][2];
int dist[301][301]={0,};
int visited[301][301]={0,};
int direct[8][2]={
    {1,2},
    {-1,2},
    {2,1},
    {-2,1},
    {2,-1},
    {-2,-1},
    {1,-2},
    {-1,-2}
};

void BFS(){
    
    queue<pair<int, int>> q;
    q.push(make_pair(fromto[0][0],fromto[0][1]));
    dist[fromto[0][0]][fromto[0][1]] = 0;
    visited[fromto[0][0]][fromto[0][1]] = 1;
    
    while(!q.empty()){
        
        int h=q.front().first;
        int w=q.front().second;
        q.pop();
        
        if(h==fromto[1][0] && w == fromto[1][1]){
            cout << dist[h][w] << "\n";
            return;
        }
        
        for(int i=0;i<8;i++){
            int dh,dw;
            
            dh = h + direct[i][0];
            dw = w + direct[i][1];
            
            if(dh >= 0 && dh < I && dw >= 0 && dw < I && visited[dh][dw] == 0){
                q.push(make_pair(dh, dw));
                dist[dh][dw] = dist[h][w] + 1;
                visited[dh][dw] = 1;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> I;
        
        memset(dist,-1,sizeof(dist));
        memset(visited,0,sizeof(visited));
        
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                cin >> fromto[j][k];
            }
        }
        
        BFS();
    }
    
    
    return 0;
}
