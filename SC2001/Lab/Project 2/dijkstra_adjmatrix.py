class PriorityQueue:
    def __init__(self):
        self.queue = []
        self.length = 0

    def insert(self, dest, totalWeight):
        self.queue.append({'dest': dest, 'weight': totalWeight})
        self.length += 1

    def extractMin(self):
        minimum = self.queue[0]['weight']
        mIndex = 0
        for i in range(self.length):
            if self.queue[i]['weight'] < minimum:
                minimum = self.queue[i]['weight']
                mIndex = i
        returnNode = self.queue[mIndex]
        for i in range(mIndex, self.length - 1):
            self.queue[i] = self.queue[i + 1]
        self.queue.pop()
        self.length -= 1
        return returnNode


class Graph:
    def __init__(self, numVertices):
        self.aMatrix = []
        self.dist = []
        self.visited = []
        self.numVertices = numVertices
        self.PQ = PriorityQueue()
        for i in range(numVertices):
            self.aMatrix.append([])
            self.visited.append(0)
            self.dist.append(999999999)
            for _ in range(numVertices):
                self.aMatrix[i].append(-1)

    # Unidirectional
    def addEdge(self, fr, to, weight):
        self.aMatrix[fr][to] = weight

    def printGraphMatrix(self):
        for i in range(self.numVertices):
            print(self.aMatrix[i])

    def dijkstra(self):
        self.dist[0] = 0
        self.PQ.insert(0, 0)
        while(self.PQ.length > 0):
            pqMin = self.PQ.extractMin()
            index = pqMin['dest']
            self.visited[index] = 1
            for vertice in range(self.numVertices):
                if self.aMatrix[index][vertice] != -1:
                    if self.visited[vertice] != 1:
                        newDist = self.dist[index] + \
                            self.aMatrix[index][vertice]
                        if newDist < self.dist[vertice]:
                            self.dist[vertice] = newDist
                            self.PQ.insert(vertice, newDist)
        print(self.dist)


if __name__ == '__main__':
    g = Graph(10)
    g.addEdge(0, 1, 4)
    g.addEdge(0, 7, 8)
    g.addEdge(1, 2, 8)
    g.addEdge(1, 7, 11)
    g.addEdge(2, 3, 7)
    g.addEdge(2, 8, 2)
    g.addEdge(2, 5, 4)
    g.addEdge(3, 4, 9)
    g.addEdge(3, 5, 14)
    g.addEdge(4, 5, 10)
    g.addEdge(5, 6, 2)
    g.addEdge(6, 8, 6)
    g.addEdge(6, 7, 1)
    g.addEdge(7, 8, 7)
    g.printGraphMatrix()
    g.dijkstra()
