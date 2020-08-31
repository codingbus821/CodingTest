//
//  main.cpp
//  boj1149
//
//  Created by 김병수 on 2020/08/31.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int cost[1001][3];
int memo[1001][3];

int main(int argc, const char * argv[]) {
    
    int N;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    for(int i=0;i<N-1;i++){
        cost[i+1][0] = min(cost[i][1],cost[i][2]) + cost[i+1][0];
        cost[i+1][1] = min(cost[i][0],cost[i][2]) + cost[i+1][1];
        cost[i+1][2] = min(cost[i][0],cost[i][1]) + cost[i+1][2];
    }
    
    cout << min(min(cost[N-1][0],cost[N-1][1]),cost[N-1][2]);
    
    return 0;
}
