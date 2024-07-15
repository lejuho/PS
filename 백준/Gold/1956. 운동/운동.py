import sys

def floyd_warshall(V, edges):
    dist = [[float('inf')] * V for _ in range(V)]
    
    for i in range(V):
        dist[i][i] = 0
    
    for u, v, w in edges:
        dist[u-1][v-1] = w
    
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    
    return dist

def find_min_cycle(V, edges, dist):
    min_cycle = float('inf')
    
    for u, v, w in edges:
        if dist[v-1][u-1] < float('inf'):
            min_cycle = min(min_cycle, dist[v-1][u-1] + w)
    
    return min_cycle if min_cycle != float('inf') else -1

def main():
    input = sys.stdin.read
    data = input().strip().split()
    V = int(data[0])
    E = int(data[1])
    edges = []
    
    index = 2
    for _ in range(E):
        a = int(data[index])
        b = int(data[index+1])
        c = int(data[index+2])
        edges.append((a, b, c))
        index += 3
    
    dist = floyd_warshall(V, edges)
    result = find_min_cycle(V, edges, dist)
    
    print(result)

if __name__ == "__main__":
    main()
