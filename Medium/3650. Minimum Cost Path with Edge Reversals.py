import heapq
class Solution(object):
    def minCost(self, n, edges):
        graph=[[] for _ in range(n)]
        for i,f,w in edges:
            graph[i].append((f,w))
            graph[f].append((i,2*w))
        dist=[float('inf')]*n
        dist[0]=0
        visited=[False]*n
        heap=[(0,0)]
        while heap:
            d,u = heapq.heappop(heap)
            if u == n-1 :
                return d
            if visited[u] :
                continue
            visited[u] = True        

            for v,weight in graph[u] :
                if dist[u] + weight < dist [v] :
                    dist[v] = dist[u] + weight
                    heapq.heappush(heap,(dist[v],v))
        return -1