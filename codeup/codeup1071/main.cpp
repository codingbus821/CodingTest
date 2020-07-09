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
    
    int n;
reload: //레이블은 콜론(:)으로 끝내고, 일반적으로 들여쓰기를 하지 않는다.
    scanf("%d", &n);
    
    if(n!=0) {
        printf("%d\n", n);
        goto reload; //reload라고 적혀있는 레이블로 실행 이동
    }
    
    return 0;
}
