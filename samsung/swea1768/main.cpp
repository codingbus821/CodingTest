#define N 4

typedef struct {
    int strike;
    int ball;
} Result;

typedef struct st {
    int arr[4];
    struct st* next;
}NODE;

NODE head;
NODE pool[10000];
int cnt = 0;

int tmp[4];
bool visited[10];

void DFS(int length) {
    if (length == 4) {
        NODE* nd = &pool[cnt++];
        for (int i = 0; i < 4; i++) {
            nd->arr[i] = tmp[i];
        }
        nd->next = head.next;
        head.next = nd;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (visited[i] == false) {
            tmp[length] = i;
            visited[i] = true;
            DFS(length + 1);
            visited[i] = false;
        }
    }
}

void deleteNODE(int s, int b, int guess[]) {

    NODE* p = &head;

    while (p->next) {
        int tmps=0, tmpb=0;
        bool check[10] = { 0, };

        for (int i = 0; i < N; i++) {
            check[guess[i]] = true;
        }

        for (int i = 0; i < N; i++) {
            if (guess[i] == p->next->arr[i])
                tmps++;
            else if (check[p->next->arr[i]] == true)
                tmpb++;
        }

        if (s == tmps && b == tmpb)
            p = p->next;
        else {
            NODE* temp = p->next;
            p->next = p->next->next;
            temp->next = NULL; // optional: clean up the removed node
        }
    }

}

// API
extern Result query(int guess[]);

void doUserImplementation(int guess[]) {
    
    DFS(0);

    while (head.next) {

        Result ans;

        for (int i = 0; i < 4; i++) {
            guess[i] = head.next->arr[i];
        }

        ans = query(guess);

        if (ans.strike == 4) {
            break;
        }

        deleteNODE(ans.strike, ans.ball, guess);
        head.next = head.next->next;
    }
}
