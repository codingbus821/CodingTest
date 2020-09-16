#include <string>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> map;
    
    for(int i=0;i<record.size();i++){
        
        char *sArr[10] = { NULL, };
        int j = 0;
        
        char *buffer = new char[1000];
        strcpy(buffer, record[i].c_str());
        
        char* tok1 = strtok(buffer, " ");
        while(tok1!=NULL){
            sArr[j] = tok1;
            j++;
            tok1 = strtok(NULL, " ");
        }
        
        // Enter과 Change인 경우 map의 value값을 교체
        if(!strcmp(sArr[0],"Enter")){
            map[sArr[1]] = sArr[2];
        }else if(!strcmp(sArr[0],"Change")){
            map[sArr[1]] = sArr[2];
        }
    }
    
    for(int i=0;i<record.size();i++){
        
        char *sArr[10] = { NULL, };
        int j = 0;
        
        char *buffer = new char[1000];
        strcpy(buffer, record[i].c_str());
        
        char* tok1 = strtok(buffer, " ");
        while(tok1!=NULL){
            sArr[j] = tok1;
            j++;
            tok1 = strtok(NULL, " ");
        }
        
        string tmp;
        
        // Enter과 Leave일 경우 key값으로 value를 찾아 answer에 push_back
        if(!strcmp(sArr[0], "Enter")){
            tmp.append(map[sArr[1]]+"님이 들어왔습니다.");
            answer.push_back(tmp);
        }else if(!strcmp(sArr[0], "Leave")){
            tmp.append(map[sArr[1]]+"님이 나갔습니다.");
            answer.push_back(tmp);
        }
    }
    
    return answer;
}
