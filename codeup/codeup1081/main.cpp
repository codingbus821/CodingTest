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
    
    int i, j;
    int n, m;
    
    cin >> n >> m;
    
    for(i=1; i<=n; i++)
    {
      for(j=1; j<=m; j++)
      {
        printf("%d %d\n", i, j);
      }
    }
    
    return 0;
}
