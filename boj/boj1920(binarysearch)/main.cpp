//
//  main.cpp
//  boj1920
//
//  Created by 김병수 on 2020/09/01.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];

bool binarysearch(int start, int end, int target){
    
    if(start>end)
        return false;
    
    int mid = (start+end)/2;
    
    if(A[mid] == target)
        return true;
    else if(A[mid] > target)
        return binarysearch(start, mid-1, target);
    else
        return binarysearch(mid+1, end, target);
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //cin 속도 향상 위해
    
    int num;
    int N, M;
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    sort(A,A+N);
    
    cin >> M;
    
    for(int i=0;i<M;i++){
        cin >> num;
        
        cout << binarysearch(0,N-1,num) << "\n";
    }
    
    return 0;
}
