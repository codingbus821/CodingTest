#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct Trie {
    bool finish;
    Trie *next[26];
    int count;

    Trie() :finish(false),count(1){ // 생성자 finish를 false로
        memset(next, 0, sizeof(next));
    }
    ~Trie(){ // 소멸자
        for (int i=0;i<26;i++)
            if (next[i]) delete next[i];
    }
    
    void insert(char *key){ // Trie에 insert 하는 함수
        if (*key == '\0') finish = true; // 문자가 끝나면 finish는 true
        else {
            int cur = *key - 'a';
            if (next[cur] == NULL){ // next가 비었으면 생성해줌
                next[cur] = new Trie();
            }else
                next[cur]->count++; // next가 있으면 count를 1증가.
            next[cur]->insert(key+1); // 다음 문자 insert함.
        }
    }
    int find(char *key){ // Trie에서 find 하는 함수
        int cur = *key - 'a';
        if(*key == '?'){ // 첫문자가 '?' 이면 모든 문자가 '?'이므로 reroot[size]의 모든 문자열의 개수를 다 더해줌.
            int tmp=0;
            for(int k=0;k<26;k++){
                if(next[k] != NULL)
                    tmp = tmp + next[k]->count;
            }
            return tmp;
        }
        if(next[cur]==NULL) // 첫문자의 next가 NULL 이면 그 문자로 시작하는 문자열이 없기 때문에 0리턴
            return 0;
        if(*(key+1) == '?') // 다음문자가 '?'이면 현재문자의 count를 리턴
            return next[cur]->count;
        return next[cur]->find(key+1); // 계속 다음문자를 찾음.
    }
};

Trie *root[10001];
Trie *reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    int wsize = words.size();
    int qsize = queries.size();
    vector<int> answer(qsize, 0); // queries의 사이즈 만큼 vector를 0으로 초기화
    
    for(int i=0;i<words.size();i++){ // '?'가 접두사와 접미사 모두 가능하니 2개의 root배열을 만듬
        int size = words[i].size();
        
        if(root[size] == NULL)
            root[size] = new Trie();
        root[size]->insert(&words[i][0]);
        
        reverse(words[i].begin(), words[i].end());
        
        if(reroot[size] == NULL)
            reroot[size] = new Trie();
        reroot[size]->insert(&words[i][0]);
    }
    
    int idx = 0;
    
    for(auto &q : queries){
        int size = q.size();
        if(q[size-1] == '?'){ // '?'가 접미사일때
            if(root[size] == NULL){
                idx++;
                continue;
            }else{
                answer[idx] = root[size]->find(&q[0]);
            }
        }else{ // '?'가 접두사일때
            string re = q;
            reverse(re.begin(), re.end()); // '?'를 뒤로보내고 앞쪽에 문자가 오게함
            
            if(reroot[size] == NULL){
                idx++;
                continue;
            }else
                answer[idx] = reroot[size]->find(&re[0]);
        }
        idx++;
    }
    
    return answer;
}
