#include <iostream>
#include <string>

#define MAX_TABLE 1000003

using namespace std;

typedef unsigned long long int ull;

int N;

typedef struct st {
	char name[6];
	int in;
}DB;

DB dbList[1001000]
DB enterList[1001000];

typedef struct st2 {
	DB* db;
	struct st2* next;
}HASH;

HASH Hash[MAX_TABLE];
HASH POOL[MAX_TABLE];
int pcnt;

ull hash(const char* str) {
	ull hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}

	return hash % MAX_TABLE;
}

DB b[1001000];

int main() {
	int count, inCnt;
	string name, cmd;

	cin >> N;

	count = 0;
	for (int i = 0; i < N; i++) {
		cin >> name >> cmd;
		if(cmd == "enter")
	}
}