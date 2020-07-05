//
//  main.cpp
//  codeup1049
//
//  Created by 김병수 on 2020/07/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int n, i, s=0;
    scanf("%d", &n);
    for(i=1; ; i++) //for 반목문에서 가운데의 조건이 빠진 경우 무한 반복된다.
    {
      s+=i;
        if(s>=n){
            
        break; //참이면, 가장 가까운 반복 코드블록의 밖으로 빠져나간다.
                 }
    } //break; 가 실행되면 반복을 중단하고 여기로 빠져 나온다.
    printf("%d", s);
}
