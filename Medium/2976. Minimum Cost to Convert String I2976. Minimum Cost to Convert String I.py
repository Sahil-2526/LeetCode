class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        graph = [[float('inf') for _ in range(26)] for _ in range(26)]
        #ord('a') = 97
        for i in range(26):
            graph[i][i]=0
        for i in range(len(original)):
            graph[ord(original[i])-97][ord(changed[i])-97]=min(cost[i], graph[ord(original[i])-97][ord(changed[i])-97])
        n = len(graph)
        dist = [row[:] for row in graph] 
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        cost=0
        for i in range(len(source)):
            cost+=dist[ord(source[i])-97][ord(target[i])-97]
        if cost == float('inf') :
            return -1
        else:
            return cost