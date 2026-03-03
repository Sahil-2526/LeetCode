class Solution(object):
    
    def champagneTower(self, poured, query_row, query_glass):
        a = [[0.0]*(query_row+2) for _ in range(2)]
        a[0][0] = poured

        if query_row == 0:
            return min(1, poured)
        i = 0
        k = 0 

        while i < query_row:
            m = 1 if k == 0 else 0 
            for x in range(query_row+2):
                a[m][x] = 0.0
            l = 0
            while l <= i:
                if a[k][l] > 1:
                    val = (a[k][l] - 1) / 2.0
                    a[m][l] += val
                    a[m][l+1] += val
                l += 1
            k = m
            i += 1
        return min(1, a[k][query_glass])