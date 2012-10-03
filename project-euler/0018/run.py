
tiny = [[3],
        [7,4],
        [2,4,6],
        [8,5,9,3]]
        

class Triangle:
    def __init__(self, size, data):
        self.size = size
        self.data = data
        self.memo = {}

    def get(self, row, nth):
        return self.data[row][nth]

    def find_max_at(self, row, nth):
        r = (row +1)
        return max(self.memo[(r, nth)], self.memo[(r,nth+1)])

    def find_max(self):
        row = self.size - 1
        for i, x in enumerate(self.data[row]):
            self.memo[(row, i)] = x
        for r in range(row - 1, -1, -1):
            for j in range(r+1):
                #print r,j
                self.memo[(r, j)] = self.find_max_at(r, j) + self.get(r, j)
        #print self.memo
        return self.memo[(0,0)]

t = Triangle(4, tiny)
print t.find_max()


eighteen = [[75],
[95,64],
[17,47,82],
[18,35,87,10],
[20,4,82,47,65],
[19,1,23,75,3,34],
[88,2,77,73,7,63,67],
[99,65,4,28,6,16,70,92],
[41,41,26,56,83,40,80,70,33],
[41,48,72,33,47,32,37,16,94,29],
[53,71,44,65,25,43,91,52,97,51,14],
[70,11,33,28,77,73,17,78,39,68,17,57],
[91,71,52,38,17,14,91,43,58,50,27,29,48],
[63,66,4,68,89,53,67,30,73,16,69,87,40,31],
[4,62,98,27,23,9,70,98,73,93,38,53,60,4,23]]

t = Triangle(len(eighteen), eighteen)
print t.find_max()


