# C++ Data Structures from Scratch

This repository contains a small collection of **handwritten C++ implementations** of core data structures and algorithms.  
I built these to deepen my understanding of how things work under the hood, beyond using the STL containers.

All implementations are **for learning purposes**

---

## Contents

All source files are under [`src/`](./src).

### 1. Hash Table with Separate Chaining

**File:** `01_string_hash_table_chaining.cpp`  
**Concepts:**

- Hash table of `std::string`
- Separate chaining using a singly linked list
- Manual hash function on characters
- Operations: `insert`, `search`, `remove`

This implementation uses a fixed-size array of buckets (`arr[1000]`), where each bucket is a small linked list of strings that hash to the same index.

---

### 2. Doubly Linked List

**File:** `02_doubly_linked_list.cpp`  
**Concepts:**

- Doubly linked list node: `prev` and `next` pointers
- `head` / `tail` maintenance
- Insertion at head and tail
- Insertion after a given node
- Deletion of an arbitrary node while updating neighbors

The `main` function demonstrates building a list, inserting in the middle, and deleting a node, then printing the updated structure.

---

### 3. Singly Linked List

**File:** `03_singly_linked_list.cpp`  
**Concepts:**

- Singly linked list node with `next` pointer
- `head` / `tail` tracking
- Insertion at head
- Insertion after a node with a specific value
- Removal by value

Includes simple I/O in `main` to:

1. Read values until `-1`
2. Remove a chosen value
3. Insert a new value after a chosen node
4. Print the resulting list

---

### 4. Max Heap and Heapsort

**File:** `04_max_heap_and_heapsort.cpp`  
**Concepts:**

- Array-based max heap
- `heapifyDown` and `heapifyUp`
- Building a max heap from an array
- Heapsort using the max heap
- Dynamic growth of the underlying array

This shows how to represent a heap in an array and how the index relationships (`2*i+1`, `2*i+2`, `(i-1)/2`) drive the heap operations.

---

### 5. Graph Algorithms (BFS, DFS, Dijkstra, Prim’s)

**File:** `05_graph_algorithms_dijkstra_prims.cpp`  
**Concepts:**

- Adjacency list representation using custom `Node` and `LL` structures
- `unordered_map<std::string, LL>` as a graph dictionary
- Custom `minHeap` for priority-queue behavior
- Graph algorithms:
  - **BFS** (breadth-first search)
  - **DFS** (using an explicit stack)
  - **Dijkstra’s algorithm** for single-source shortest paths
  - **Prim’s algorithm** for minimum spanning tree

The `main` function builds a small labeled graph (`n1`–`n5`), adds weighted edges, runs Dijkstra’s from `n1`, performs BFS, and constructs an MST with Prim’s.

---

### 6. Counting Non-Adjacent Pairs

**File:** `06_count_non_adjacent_pairs.cpp`  
**Concepts:**

- 2D array manipulation
- `unordered_map<int, std::vector<int>>` for adjacency tracking
- Basic combinatorics on pairs

Given an `M x N` grid of integers `1..N`, this program:

1. For each value `i` in `1..N`, collects all values that ever appear directly to the left or right of `i` in any row.
2. Counts how many unordered pairs `(i, j)` **never** appear adjacent in any row.

---