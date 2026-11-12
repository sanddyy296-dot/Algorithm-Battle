
# Algorithm Battle – Which Data Structure Wins?

## Application
Student Record Search System

## Objective
To compare Binary Search Tree (BST), AVL Tree and Hashing using Linear Probing for efficient student record storage and searching.

## Data Structures Used

### 1. Binary Search Tree (BST)
Stores student IDs in sorted order and supports insertion, searching and inorder traversal.

### 2. AVL Tree
A self-balancing binary search tree that maintains balanced height for efficient searching.

### 3. Hashing
Uses a hash function and Linear Probing to handle collisions while storing student IDs.

## Dataset
40 unique student IDs are used for all three implementations.

## Operations
- Insertion
- Searching
- Inorder traversal
- Tree height calculation
- Collision handling using Linear Probing

## Programming Language
C

## Files
- bst.c – Binary Search Tree
- avl.c – AVL Tree
- hashing.c – Hashing with Linear Probing
- dataset.txt – Student dataset

## Conclusion
The three data structures are implemented and tested using the same student dataset. Their performance is compared based on searching, insertion, tree height and collisions.
## Algorithm Battle – Final Analysis

### BST
BST supports insertion and searching. Its performance depends on the structure and height of the tree.

### AVL Tree
AVL maintains a balanced tree using rotations. It provides efficient searching and insertion.

### Hashing
Hashing uses Linear Probing to resolve collisions. It provides fast searching when collisions are low.

## Final Recommendation

AVL Tree is a suitable choice when predictable searching performance is required because it maintains a balanced tree.

Hashing can also provide faster average searching when a good hash function is used and collisions are minimized.

## Conclusion

This project compares BST, AVL Tree and Hashing using the same student dataset. The experiment demonstrates how different data structures handle insertion, searching and storage.

