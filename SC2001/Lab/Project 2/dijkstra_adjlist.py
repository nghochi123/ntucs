class PriorityQueue:
    def __init__(self):
        self.queue = []
        self.length = 0

    def swap(self, a, b):
        temp = self.queue[a]
        self.queue[a] = self.queue[b]
        self.queue[b] = temp

    def fixHeap(self, n, i):
        left = 2 * i + 1
        right = 2 * i + 2
        if left > n:
            return
        smallest = left
        if right <= n and self.queue[right]['weight'] < self.queue[smallest]['weight']:
            smallest = right
        if self.queue[smallest]['weight'] < self.queue[i]['weight']:
            self.swap(i, smallest)
            self.fixHeap(n, smallest)

    def heapify(self, n, i):
        left = 2 * i + 1
        right = 2 * i + 2
        if left <= n:
            self.heapify(n, left)
        if right <= n:
            self.heapify(n, right)
        self.fixHeap(n, i)

    def insert(self, dest, totalWeight):
        self.queue.append({'dest': dest, 'weight': totalWeight})
        self.heapify(self.length, 0)
        self.length += 1

    def extractMin(self):
        self.swap(0, self.length - 1)
        self.length -= 1
        m = self.queue.pop()
        self.heapify(self.length - 1, 0)
        return m


class Graph:
    def __init__(self, numVertices):
        self.aList = []
        self.dist = []
        self.visited = []
        self.PQ = PriorityQueue()
        for _ in range(numVertices):
            self.aList.append([])
            self.visited.append(0)
            self.dist.append(999999999)

    # Graph is unidirectional
    def addEdge(self, fr, to, weight):
        self.aList[fr].append({'dest': to, 'weight': weight})

    def printGraphList(self):
        for i in range(len(self.aList)):
            print(f"{i}: {self.aList[i]}")

    def dijkstra(self):
        self.dist[0] = 0
        self.PQ.insert(0, 0)
        while(self.PQ.length > 0):
            pqMin = self.PQ.extractMin()
            index = pqMin['dest']
            self.visited[index] = 1
            for edge in self.aList[index]:
                if not self.visited[edge['dest']]:
                    newDist = self.dist[index] + edge['weight']
                    if newDist < self.dist[edge['dest']]:
                        self.dist[edge['dest']] = newDist
                        self.PQ.insert(edge['dest'], newDist)
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
    g.printGraphList()
    g.dijkstra()
