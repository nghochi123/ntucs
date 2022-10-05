//FOR (A)

//Time Complexity of the implementation is O(V^2). If the input graph is represented
//using adjacency list, it can be reduced to O(E log V) with the help of a binary heap.

//FOR (B)

//Time Complexity: The time complexity of the above code/algorithm looks O(V^2)
//as there are two nested while loops. If we take a closer look, we can observe that
//the statements in inner loop are executed O(V+E) times (similar to BFS). The inner
//loop has decreaseKey() operation which takes O(LogV) time. So overall time complexity
//is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)

//Note that the above code uses Binary Heap for Priority Queue implementation. Time complexity
//can be reduced to O(E + VLogV) using Fibonacci Heap. The reason is, Fibonacci Heap takes O(1)
//time for decrease-key operation while Binary Heap takes O(Logn) time.
// basic file operations


