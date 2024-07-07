def is_valid(y, x, n, m):
    return y >= 0 and y < n and x >= 0 and x < m

def bfs(vv, start_y, start_x, n, m):
    res = ""
    q = []
    visited = [[False] * m for _ in range(n)]
    
    if is_valid(start_y, start_x + 1, n, m): # right
        q.append((start_y, start_x + 1))
    if is_valid(start_y + 1, start_x, n, m): # down
        q.append((start_y + 1, start_x))
    if is_valid(start_y, start_x - 1, n, m): # left
        q.append((start_y, start_x - 1))
    if is_valid(start_y - 1, start_x, n, m): # up
        q.append((start_y - 1, start_x))
    
    while q:
        y, x = q.pop(0)
        if visited[y][x]:
            continue
        visited[y][x] = True
        
        if vv[y][x][0].isalpha():
            res += vv[y][x]
        
        if vv[y][x] == "═":
            if is_valid(y, x + 1, n, m) and not visited[y][x + 1]:
                q.append((y, x + 1))
            if is_valid(y, x - 1, n, m) and not visited[y][x - 1]:
                q.append((y, x - 1))
        elif vv[y][x] == "║":
            if is_valid(y + 1, x, n, m) and not visited[y + 1][x]:
                q.append((y + 1, x))
            if is_valid(y - 1, x, n, m) and not visited[y - 1][x]:
                q.append((y - 1, x))
        elif vv[y][x] == "╔":
            if is_valid(y, x + 1, n, m) and not visited[y][x + 1]:
                q.append((y, x + 1))
            if is_valid(y + 1, x, n, m) and not visited[y + 1][x]:
                q.append((y + 1, x))
        elif vv[y][x] == "╗":
            if is_valid(y, x - 1, n, m) and not visited[y][x - 1]:
                q.append((y, x - 1))
            if is_valid(y + 1, x, n, m) and not visited[y + 1][x]:
                q.append((y + 1, x))
        elif vv[y][x] == "╚":
            if is_valid(y, x + 1, n, m) and not visited[y][x + 1]:
                q.append((y, x + 1))
            if is_valid(y - 1, x, n, m) and not visited[y - 1][x]:
                q.append((y - 1, x))
        elif vv[y][x] == "╝":
            if is_valid(y, x - 1, n, m) and not visited[y][x - 1]:
                q.append((y, x - 1))
            if is_valid(y - 1, x, n, m) and not visited[y - 1][x]:
                q.append((y - 1, x))
        elif vv[y][x] == "╠":
            if is_valid(y, x + 1, n, m) and not visited[y][x + 1]:
                q.append((y, x + 1))
            if is_valid(y + 1, x, n, m) and not visited[y + 1][x]:
                q.append((y + 1, x))
            if is_valid(y - 1, x, n, m) and not visited[y - 1][x]:
                q.append((y - 1, x))
        elif vv[y][x] == "╣":
            if is_valid(y, x - 1, n, m) and not visited[y][x - 1]:
                q.append((y, x - 1))
            if is_valid(y + 1, x, n, m) and not visited[y + 1][x]:
                q.append((y + 1, x))
            if is_valid(y - 1, x, n, m) and not visited[y - 1][x]:
                q.append((y - 1, x))
        elif vv[y][x] == "╦":
            if is_valid(y, x + 1, n, m) and not visited[y][x + 1]:
                q.append((y, x + 1))
            if is_valid(y, x - 1, n, m) and not visited[y][x - 1]:
                q.append((y, x - 1))
            if is_valid(y + 1, x, n, m) and not visited[y + 1][x]:
                q.append((y + 1, x))
        elif vv[y][x] == "╩":
            if is_valid(y, x + 1, n, m) and not visited[y][x + 1]:
                q.append((y, x + 1))
            if is_valid(y, x - 1, n, m) and not visited[y][x - 1]:
                q.append((y, x - 1))
            if is_valid(y - 1, x, n, m) and not visited[y - 1][x]:
                q.append((y - 1, x))
    
    return res

def submit(input_file):
    with open(input_file, 'r', encoding='utf-8') as file:
        lines = file.readlines()
    
    v = []
    n, m = 0, 0
    for line in lines:
        ch, x, y = line.split()
        x, y = int(x), int(y)
        m = max(m, x)
        n = max(n, y)
        v.append((ch, (x, y)))
    
    vv = [["_"] * (m + 1) for _ in range(n + 1)]
    start_x, start_y = 0, 0
    for ch, (x, y) in v:
        index_x = x
        index_y = n - y
        vv[index_y][index_x] = ch
        if ch == "*":
            start_x = index_x
            start_y = index_y
    
    res = bfs(vv, start_y, start_x, n + 1, m + 1)
    return res

res = submit("io.txt")
print(res)