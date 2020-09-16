//
//  main.cpp
//  deque
//
//  Created by 김병수 on 2020/09/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

bool visited[300000];

int main(int argc, const char * argv[]) {
    vector<int> ball={11, 2, 9, 13, 24};
    vector<int> order={9, 2, 13, 24, 11};
    vector<int> answer;
    
    deque<int> dq;
    
    
    for(int i=0;i<order.size();i++){
        
        if(ball.empty())
            break;
        
        if(ball[0] == order[i]){
            answer.push_back(ball[0]);
            ball.erase(ball.begin());
            i=-1;
        }
        else if(ball[ball.size()-1] == order[i]){
            answer.push_back(ball[ball.size()-1]);
            ball.erase(ball.end()-1);
            i=-1;
        }
    }

    for(int i=0;i<answer.size();i++)
        cout << answer[i] << '\n';
    
    return 0;
}
