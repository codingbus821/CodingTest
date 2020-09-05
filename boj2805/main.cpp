//
//  main.cpp
//  boj2805
//
//  Created by 김병수 on 2020/09/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#define MAX 1000000

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N,M;
    long long arr[MAX];
    long long left=1,right=0,mid,ans=0;
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        cin >> arr[i];
        right = max(arr[i],right); // right값은 주어진 나무의 최대 높이를 넘을수 없음.
    }
    
    while(left < right){ // left와 right가 같아질때까지 반복.
        long long result = 0;
        mid = (left+right)/2;
        
        for(int i=0;i<N;i++){
            if((arr[i]-mid)>0) // 잘려나간 나무가 있을때만 더해줌.
                result = result + (arr[i]-mid);
        }
        
        if(result < M)
            right = mid; // mid의 값이 커지면 무조건 잘려진 나무의 양이 적어지므로 right를 mid로 설정.
        else{ // result 값이 최소 M 보다는 커야함.
            ans = mid; // 현재 설정가능한 높이의 최댓값.
            left = mid+1; // 현재 mid 보다 큰 값이 있는지 확인해야함.
        }
    }
    
    cout << ans;
    
    return 0;
}
