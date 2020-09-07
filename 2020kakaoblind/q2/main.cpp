#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str, int* pos){
    bool ret = true; // 올바른 문자열인지 확인하기위한 변수 선언
    int left = 0, right = 0;
    stack<char> mystack;
    
    for(int i=0;i<str.length();i++){
        if(str[i] == '('){ // 열린 괄호면 left 1증가후 stack에 '(' push
            left++;
            mystack.push('(');
        }else{ // 닫힌 괄호면 right 1증가
            right++;
            if(mystack.empty()) // 스택에 아무것도 없으면 올바른 괄호 문자열이 아니므로 ret = false;
                ret = false;
            else // 스택에 '('가 있으므로 pop
                mystack.pop();
        }
        if(left == right){ // 처음으로 균형잡힌 괄호 문자열이 되었을때의 위치를 pos로 할당
            *pos = i + 1;
            return ret;
        }
    }
    return true;
}

string solution(string p) {
    
    if(p.empty()) // 1.입력이 빈 문자열인 경우, 빈 문잘을 반환합니다.
        return p;
    
    int pos;
    bool correct = isCorrect(p, &pos); // isCorrect 함수로 "균형잡힌 괄호 문자열"로 더 이상 분리될 수 없는위치 반환.
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
    string u = p.substr(0,pos);
    string v = p.substr(pos);
    
    if(correct){ // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
        return u+solution(v); // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
    }
    
    // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    string answer = "(" + solution(v) + ")"; // 4-1, 4-2, 4-3
    
    for(int i=1; i<u.length() - 1;i++){ // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        if(u[i] == '(')
            answer += ")";
        else
            answer += "(";
    }
    
    return answer; // 4-5. 생성된 문자열을 반환합니다.
}
