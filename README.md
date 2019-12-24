# Hashing_Implementation_And_Analysis
CSCI 2270 - CU Boulder Data Structures Final Project

This project takes a handful of collision implementations for hash tables and evaluates their insertion, look up, and deletion times for different load factors. The following are the collision methods that were used and how they work.

##Chaining by Linked List##
<p> For this collision method implementation, collisions will be handled by chaining data with a linked list at full indices. 
Every time a key is inserted, it is stored in a node. If the selected hash function for this key returns an index with a node present, this node will point to the new node. New nodes will always be added to the end of whatever Linked List is present at a specific index. </p>
<p> Deletion and look up methods may also have to traverse down a Linked List at a certain index until a match is found. If a node is to be deleted, standard Linked List deletion rules still hold.</p>

<b>Chaining by Binary Search Tree</b>
<p> Each index in a hash table that resolves collisions with a Binary Search Tree will be the root node of a tree (provided that a key exists at that index). If a collision occurs standard Binary Search Tree insertion will take place at the index given by the selected hash function.</p>
<p> For tree deletion and look up, regular Binary Search Tree algorithms for these procedures will be implemented.</p>

<b>Linear Probing</b>
<p> A dynamically allocated array will be the primary data structure for implementing this type of collision method. When inserting a value at an index specified by the selected hash function, any time that index is full, the next index is then used for attempting an insert. This process continues until an empty space is found or a full rotation around the table has occurred.</p>
<p> If a full rotation has occurred, the table is full, and the table size must be increased. The new key is then inserted at the end of the hash table.</p>
<p> For look up and deleted, we start at the given index by the hash function for the key. We then search each index following for the matching key. If it is found, it is returned or deleted.</p>

<b>Cuckoo Hashing</b>
<p> This type of collision method takes advantage of two dynamically allocated arrays and two hash functions. Each array has its own hash function. The first array will be the primary array and the second array will be the alternative array. When a value is inserted, the algorithm will first try the specified index of the primary array by the first hash function. If it is full, this value is displaced into a new position in the alternative array given by the second hash function. The new value is then place into the primary array.</p>
<p> It is possible that the values will go into an infinite loop of re-hashing and therefore two new hash functions will be needed. In my implementation, the table size is increased by one since both hash functions rely on table size. Doing this gives two new hash functions. Then every value is stored into a vector and deleted from both the primary and alternative arrays. All values stored in the vector are then re-inserted using the new hash functions.</p>
<p> Look up and delete simply just pass the key through the corresponding hash function for either table. Either one table or both are checked, but it is instant.</p>

<b>What I learned</b>
<ul>
<li>Implementing Linked List Chaining for Hash Tables</li>
<li>Implementing Binary Search Tree Chaining for Hash Tables</li>
<li>Implementing Linear Probing for Hash Tables</li>
<li>Implementing Cuckoo Hashing for Hash Tables</li>
<li>Deeper understanding of data structurea</li>
</ul



