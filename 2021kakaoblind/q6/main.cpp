#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string,int> map1[11];
bool arr[30];
vector<char> boarr;

void solve(int cnt, int cur, string str,int max,vector<string> o){
    if(cnt == max){
        int charnum = 0;
        for(int i=0;i<o.size();i++){
            charnum = 0;
            for(int j=0;j<str.length();j++){
                if(o[i].find(str[j]) != string::npos){
                    charnum++;
                }
            }
            if(charnum == cnt){
                map1[cnt][str]++;
            }
        }
        return;
    }
    
    for(int i=cur;i<boarr.size();i++){
        string newstr = str;
        newstr += boarr[i];
        solve(cnt+1, i+1,newstr,max,o);
    }
}

int main() {
    vector<string> orders;
    vector<int> course;
    vector<string> answer;
    
    for(int i=0;i<orders.size();i++){
        for(int j=0;j<orders[i].length();j++){
            arr[orders[i][j]-'A'] = true;
        }
    }
    
    for(int i=0;i<26;i++){
        if(arr[i] == true)
            boarr.push_back(i+'A');
    }
    
    for(int i=0;i<course.size();i++){
        solve(0, 0, "", course[i],orders);
    }
    
    for(int i=0;i<10;i++){
        int maxnum = -1;
        for(auto it = map1[i].begin(); it != map1[i].end(); it++){
            maxnum = max(maxnum,it->second);
        }
        
        for(auto it = map1[i].begin(); it != map1[i].end(); it++){
            if(it->second == maxnum && maxnum >= 2)
                answer.push_back(it->first);
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return 0;
}
