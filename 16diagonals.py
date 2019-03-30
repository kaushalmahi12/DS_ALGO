g = [[-1]*5 for i in range(5)]
def poss(c, i, j):
    if c == '\\':
        if i>0 and g[i-1][j] == '/':
            return False
        if j>0 and g[i][j-1] == '/':
            return False
        if i > 0  and j > 0 and g[i-1][j-1] == '\\':
            return False
        if i < 4 and j < 4 and g[i+1][j+1] == '\\':
            return False
    else:
        if i>0 and g[i-1][j] == '\\':
            return False
        if j>0 and g[i][j-1] == '\\':
            return False
        if i > 0  and j > 0 and g[i-1][j-1] == '/':
            return False
        if i < 4 and j < 4 and g[i+1][j+1] == '/':
            return False
    return True
mx = 0

def printG():
    for row in g:
        print(row)

def kill(i, j, sol, size):
    global mx, g
    # mx = max(mx, len(sol))
    if len(sol) == size:
        print(g)
        return
    if i >= 5 or j >= 5 or (i, j) in sol:
        return
    print (i, j)
    # printG()
    c = g[i][j]
    if poss('/', i, j):
        sol.append((i, j))
        g[i][j] = '/'
        kill(i+1, j, sol, size)
        kill(i, j+1, sol, size)
        # g[i][j] = c
        sol.pop(-1)
    if poss('\\', i, j):
        sol.append((i, j))
        g[i][j] = '\\'
        kill(i+1, j, sol, size)
        kill(i, j+1, sol, size)
        # g[i][j] = c
        sol.pop(-1)
    
    kill(i+1, j, sol, size)
    kill(i, j+1, sol, size)
    g[i][j] = c
kill(0, 0, [], 16)
# print(mx)