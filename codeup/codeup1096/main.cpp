//
//  main.cpp
//  codeup1049
//
//  Created by 김병수 on 2020/07/04.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {

    int n, i, j, x, y;
    int a[20][20]={};
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
      scanf("%d %d", &x, &y);
      a[x][y]=1;
    }
    for(i=1; i<=19; i++) //한 줄(위에서 아래로) 씩
    {
      for(j=1; j<=19; j++) //한 열(왼쪽에서 오른쪽으로) 씩
      {
        printf("%d ", a[i][j]); //값 출력
      }
      printf("\n"); //줄 바꾸기
    }

}
