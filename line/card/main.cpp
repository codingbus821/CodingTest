//
//  main.cpp
//  card2
//
//  Created by 김병수 on 2020/09/13.
//  Copyright © 2020 coconut. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int answer = 0;
    vector<int> cards={10, 13, 10, 1, 2, 3, 4, 5, 6, 2};
    
    vector<int> p,d;
    
    for(int i=0;i<cards.size();i++){
        if(cards[i] == 11 || cards[i] == 12 || cards[i] == 13){
            cards[i] = 10;
        }
    }
    
    while(!cards.empty()){
        
        p.clear();
        d.clear();
        
        int psum = 0;
        int dsum = 0;
        bool cardempty = false;
        
        if(cards.empty()){
            cardempty = true;
            break;
        }
        
        p.push_back(cards[0]);
        psum += cards[0];
        cards.erase(cards.begin());
        
        if(cards.empty()){
            cardempty = true;
            break;
        }
        d.push_back(cards[0]);
        dsum += cards[0];
        cards.erase(cards.begin());
        
        if(cards.empty()){
            cardempty = true;
            break;
        }
        p.push_back(cards[0]);
        psum += cards[0];
        cards.erase(cards.begin());
        
        if(cards.empty()){
            cardempty = true;
            break;
        }
        d.push_back(cards[0]);
        dsum += cards[0];
        cards.erase(cards.begin());
        
        if(p[0] == 1 || p[1] == 1){
            if(p[0]+p[1] == 11){
                if(d[0]+d[1] !=21)
                    answer = answer+3;
                p.clear();
                d.clear();
                continue;
            }
        }
        if(p[0]+p[1] == 21){
            if(d[0]+d[1] !=21)
                answer = answer+3;
            p.clear();
            d.clear();
            continue;
        }
        if(d[1] == 1 || d[1] >= 7){
            while(psum < 17){
                if(cards.empty()){
                    cardempty = true;
                    break;
                }
                p.push_back(cards[0]);
                psum += cards[0];
                cards.erase(cards.begin());
            }
            if(psum > 21){
                answer = answer - 2;
                continue;
            }
        }else if(d[1] >= 4 && d[1] <= 6){
            
        }else if(d[1] >= 2 && d[1] <= 3){
            while(psum < 12){
                if(cards.empty()){
                    cardempty = true;
                    break;
                }
                p.push_back(cards[0]);
                psum += cards[0];
                cards.erase(cards.begin());
            }
        }
        
        if(d[0] == 1 || d[1] == 1){
            if(d[0]+d[1] == 11){
                dsum = 21;
            }
        }
        
        if(dsum == 21){
            answer = answer - 2;
            continue;
        }
        
        while(dsum < 17){
            if(cards.empty()){
                cardempty = true;
                break;
            }
            d.push_back(cards[0]);
            dsum += cards[0];
            cards.erase(cards.begin());
        }
        
        if(cardempty == true)
            break;
        
        if(dsum > 21){
            answer = answer + 2;
            continue;
        }
        
        if(psum == dsum)
            continue;
        if(psum > dsum)
            answer = answer + 2;
        if(psum < dsum)
            answer = answer - 2;
        
    }
    
    cout << answer;
    
    
    return 0;
}
