//
//  main.cpp
//  boj1795
//
//  Created by 김병수 on 2020/07/15.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
int dist[51][51];
bool visited[51][51];
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
vector<tuple<int,int,int>> v;
int ans = 0;

void BFS(){
    
    //    cout << "size = " << v.size();
    
    for(int i=(v.size()-1);i>0;i--){
        
        queue<pair<int, int>> q;
        
        memset(dist,-1,sizeof(dist));
        memset(visited,false,sizeof(visited));
        
        q.push(make_pair(get<1>(v[i]), get<2>(v[i])));
        dist[get<1>(v[i])][get<2>(v[i])] = 0;
        visited[get<1>(v[i])][get<2>(v[i])] = true;
        
        while(!q.empty()){
            int h=q.front().first;
            int w=q.front().second;
            q.pop();
            
//            cout << "h=" << h << " w=" << w << "\n";
            
            if(h==get<1>(v[0]) && w == get<2>(v[0])){
                if(i==1){
                    if(dist[h][w]%get<0>(v[i]) != 0){
                        ans = ans + (dist[h][w]/get<0>(v[i])) + 1;
                    }else{
                        ans = ans + (dist[h][w]/get<0>(v[i]));
                    }
//                    cout << dist[h][w] << "\n";
                    break;
                }
                else if(dist[h][w] % get<0>(v[i]) == 0){
                    
                    ans = ans + (dist[h][w]/get<0>(v[i]));
//                    cout << dist[h][w] << "\n";
                    break;
                }else{
                    memset(visited,false,sizeof(visited));
                }
            }
            
            for(int i=0;i<8;i++){
                int dh,dw;
                
                dh = h + direct[i][0];
                dw = w + direct[i][1];
                
                if(dh >= 0 && dh < N && dw >= 0 && dw < M && visited[dh][dw] == false){
                    q.push(make_pair(dh, dw));
                    dist[dh][dw] = dist[h][w] + 1;
                    visited[dh][dw] = true;
                }
            }
        }
        
        
    }
}

int main(int argc, const char * argv[]) {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string str;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> str;
        for(int j=0;j<str.size();j++){
            if(str[j] == '.')
                continue;
            else{
                v.push_back(make_tuple(str[j] - '0',i,j));
            }
        }
    }
    
    sort(v.begin(),v.end());
    
    //    for(int i=0;i<v.size();i++){
    //        cout << get<0>(v[i]) << get<1>(v[i]) << get<2>(v[i]) << "\n";
    //    }
    
    BFS();
    
    cout << ans;
    
    return 0;
}
