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
    
    int a,b,c;
    
    cin >> a >> b >> c;
    
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    
    printf("%d",a*b*c);
    
    return 0;
}
