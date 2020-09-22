//
//  main.cpp
//  boj5639
//
//  Created by 김병수 on 2020/09/22.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1000001]; // 노드에 들어갈 수 있는 키값은 10의 6제곱 보다 작음.
vector<int> arr;

void post(int s){ // 후위 순환 출력
    
    if(v[s].size() != 0 && v[s][0] != 0)
        post(v[s][0]);
    
    if(v[s].size() != 0 && v[s][1] != 0)
        post(v[s][1]);
    
    cout << s << '\n';
}

void solve(int s, int e){
    
    if(s==e)
        return;
    
    for(int i=s;i<=e;i++){
        if(arr[i] > arr[s]){
            if(i-s == 1){ // 바로 다음 조건이 충족되면 왼쪽자식은 없음.
                v[arr[s]].push_back(0);
                v[arr[s]].push_back(arr[s+1]);
            }else{ // 조건이 충족되었을때 왼쪽자식과 오른쪽자식 push.
                v[arr[s]].push_back(arr[s+1]);
                v[arr[s]].push_back(arr[i]);
            }
            solve(s+1, i-1);
            solve(i, e);
            break;
        }
        
        if(i==e){ // 마지막까지 왔으면 왼쪽자식만 있음.
            v[arr[s]].push_back(arr[s+1]);
            v[arr[s]].push_back(0);
            solve(s+1, e);
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int num=0;
    
    while(cin >> num){
        if(num == EOF)
            break;
        arr.push_back(num);
    }
    
    solve(0, arr.size()-1);
    
    post(arr[0]);
    
    return 0;
}
