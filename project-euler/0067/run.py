
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


f = open('0067/triangle.txt')

huge = []
for line in f:
    huge.append([int(x) for x in line.split()])

#print huge
t = Triangle(len(huge), huge)
print t.find_max()




