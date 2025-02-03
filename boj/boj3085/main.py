N = int(input())

board = []
maxx = 0

for _ in range(N):
    s = input()
    tmp = []
    for i in s:
        tmp.append(i)
    board.append(tmp)

def find_max():
    global board, maxx
    for i in range(len(board)):
        tmp_max = 1
        c = board[i][0]
        for j in range(1, len(board[i])):
            if c == board[i][j]:
                tmp_max += 1
            else:
                tmp_max = 1
                c = board[i][j]
            if maxx < tmp_max:
                maxx = tmp_max
    
    for i in range(len(board)):
        tmp_max = 1
        c = board[0][i]
        for j in range(1, len(board[i])):
            if c == board[j][i]:
                tmp_max += 1
            else:
                tmp_max = 1
                c = board[j][i]
            if maxx < tmp_max:
                maxx = tmp_max
    

for i in range(len(board)):
    for j in range(len(board[i])):
        find_max()
        # if j <= len(board)-2:
        #     tmp = board[i][j]
        #     board[i][j] = board[i][j+1]
        #     board[i][j+1] = tmp
        #     find_max()
        #     tmp = board[i][j+1]
        #     board[i][j+1] = board[i][j]
        #     board[i][j] = tmp
        if j >= 1:
            tmp = board[i][j]
            board[i][j] = board[i][j-1]
            board[i][j-1] = tmp
            find_max()
            tmp = board[i][j-1]
            board[i][j-1] = board[i][j]
            board[i][j] = tmp
        if i >= 1:
            tmp = board[i][j]
            board[i][j] = board[i-1][j]
            board[i-1][j] = tmp
            find_max()
            tmp = board[i-1][j]
            board[i-1][j] = board[i][j]
            board[i][j] = tmp
        # if i <= len(board)-2:
        #     tmp = board[i][j]
        #     board[i][j] = board[i+1][j]
        #     board[i+1][j] = tmp
        #     find_max()
        #     tmp = board[i+1][j]
        #     board[i+1][j] = board[i][j]
        #     board[i][j] = tmp

print(maxx)