# Programming Assignment 4: Sets, Multiway Tries (MWTs), and Ternary Search Trees (TSTs)
In this Programming Assignment, you will be assessing your understanding of Sets, Multiway Tries (MWTs), and Ternary Search Trees (TSTs).

## Part 0: Weekly Reflection Survey (5 points)
Complete this weekly reflection survey: https://forms.gle/bvFS7BPP6brGXn8B9

Also, if you haven't already completed the degree planning assignment, please do so as soon as possible.

## Part 1: Implementing the Set ADT (40 points)
The [Set Abstract Data Type (ADT)](https://en.wikipedia.org/wiki/Set_(abstract_data_type)) is an ADT that can store unique elements. Generally, the Set ADT is defined by the following operations:
* ``size``: Return the number of elements stored in the set
* ``insert(x)``: Insert element ``x`` into this set (don't allowing duplicates)
* ``remove(x)``: Remove element ``x`` from this set (if it exists)
* ``find(x)``: Determine whether or not ``x`` exists in this set

We can implement the Set ADT using various data structures we have already learned about, and we can even simply wrap around existing C++ classes:
* We can use an [Array List](https://en.wikipedia.org/wiki/Dynamic_array), which is implemented in the C++ [``vector``](http://www.cplusplus.com/reference/vector/vector/) class
* We can use a [Linked List](https://en.wikipedia.org/wiki/Linked_list), which is implemented in the C++ [``list``](http://www.cplusplus.com/reference/list/list/) class
* We can use a [Red-Black Tree (RBT)](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree), which is implemented in the C++ [``set``](http://www.cplusplus.com/reference/set/set/) class
* We can use a [Hash Table](https://en.wikipedia.org/wiki/Hash_table), which is implemented in the C++ [``unordered_set``](http://www.cplusplus.com/reference/unordered_set/unordered_set/) class
* We can use a [Multiway Trie (MWT)](https://stepik.org/lesson/30819/step/1), which is not natively implemented in C++
* We can use a [Ternary Search Tree (TST)](https://stepik.org/lesson/30820/step/1), which is not natively implemented in C++

### Task 1a: Edit [``ArrayListSet.cpp``](ArrayListSet.cpp) (10 points)
In this repository, there is a file called [``ArrayListSet.cpp``](ArrayListSet.cpp) that contains initial steps towards implementing the Set ADT using an Array List via the C++ [``vector``](http://www.cplusplus.com/reference/vector/vector/) class. Function headers (with usage details) are included in [``Set.h``](Set.h). Your task is to fill in the missing code.

### Task 1b: Edit [``LinkedListSet.cpp``](LinkedListSet.cpp) (10 points)
In this repository, there is a file called [``LinkedListSet.cpp``](LinkedListSet.cpp) that contains initial steps towards implementing the Set ADT using a Linked List via the C++ [``list``](http://www.cplusplus.com/reference/list/list/) class. Function headers (with usage details) are included in [``Set.h``](Set.h). Your task is to fill in the missing code.

### Task 1c: Edit [``RedBlackTreeSet.cpp``](RedBlackTreeSet.cpp) (10 points)
In this repository, there is a file called [``RedBlackTreeSet.cpp``](RedBlackTreeSet.cpp) that contains initial steps towards implementing the Set ADT using a Red-Black Tree via the C++ [``set``](http://www.cplusplus.com/reference/set/set/) class. Function headers (with usage details) are included in [``Set.h``](Set.h). Your task is to fill in the missing code.

### Task 1d: Edit [``HashTableSet.cpp``](HashTableSet.cpp) (10 points)
In this repository, there is a file called [``HashTableSet.cpp``](HashTableSet.cpp) that contains initial steps towards implementing the Set ADT using a Hash Table via the C++ [``unordered_set``](http://www.cplusplus.com/reference/unordered_set/unordered_set/) class. Function headers (with usage details) are included in [``Set.h``](Set.h). Your task is to fill in the missing code.

## Part 2: Implementing a Multiway Trie (MWT) (30 points)
Imagine we want to insert *n* elements of length *k* into our set. Array Lists, Linked Lists, and Red-Black Trees all scale as a function of *n* in the average and worst cases, and although Hash Tables are O(*k*) in the average case, they scale as a function of *n* in the worst case, and they have no inherent order. Instead, if we implement the Set ADT using a Multiway Trie, our find, insert, and remove operations will all be O(*k*) in the worst case, meaning our data structure's runtime will not worsen as *n* increases, and we can iterate over are elements in sorted order.

### Task: Edit [``MultiwayTrieSet.cpp``](MultiwayTrieSet.cpp) (30 points)
In this repository, there is a file called [``MultiwayTrieSet.cpp``](MultiwayTrieSet.cpp) that contains initial steps towards implementing the Set ADT using a Multiway Trie. Function headers (with usage details) are included in [``Set.h``](Set.h). Your task is to fill in the missing code.

## Testing Parts 1 and 2
We have provided a tester program, [``SetTest``](SetTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o SetTest SetTest.cpp ArrayListSet.cpp HashTableSet.cpp LinkedListSet.cpp MultiwayTrieSet.cpp RedBlackTreeSet.cpp
```

We have also provided a [``Makefile``](Makefile) to make compilation easier. Here's an example of how it should look like when it's compiled and run from the command line:

```
$ make clean
rm -f SetTest *.o
$ make
g++ -Wall -pedantic -g -O0 -std=c++11 -o SetTest SetTest.cpp ArrayListSet.cpp HashTableSet.cpp LinkedListSet.cpp MultiwayTrieSet.cpp RedBlackTreeSet.cpp
$ ./SetTest
```

If nothing is printed by ``SetTest``, then your functions in Parts 1 and 2 are correct. Otherwise, ``SetTest`` will print out which classes are incorrect, such as the following:

```
$ ./SetTest
ArrayListSet failed
HashTableSet failed
LinkedListSet failed
MultiwayTrieSet failed
RedBlackTreeSet failed
```

## Parts 1-2: Checking for Memory Leaks (10 points)
To receive these 10 points, your implementations for both Part 1 and Part 2 must not have any memory leaks. You can use ``valgrind`` to check for memory leaks. For example, you can run it as follows:

```bash
valgrind --tool=memcheck --leak-check=yes ./SetTest
```

If it gives you a report like the following, you do not have memory leaks and are good to go (the important part is ``All heap blocks were freed -- no leaks are possible``):

```
==1482== Memcheck, a memory error detector
==1482== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1482== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1482== Command: ./SetTest
==1482==
==1482== error calling PR_SET_PTRACER, vgdb might block
==1482==
==1482== HEAP SUMMARY:
==1482==     in use at exit: 0 bytes in 0 blocks
==1482==   total heap usage: 29,796 allocs, 29,796 frees, 1,455,627 bytes allocated
==1482==
==1482== All heap blocks were freed -- no leaks are possible
==1482==
==1482== For counts of detected and suppressed errors, rerun with: -v
==1482== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

If you *do* have memory leaks, the report will look something like the following:
```
==1516== Memcheck, a memory error detector
==1516== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1516== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1516== Command: ./SetTest
==1516==
==1516== error calling PR_SET_PTRACER, vgdb might block
==1516==
==1516== HEAP SUMMARY:
==1516==     in use at exit: 941,480 bytes in 24,559 blocks
==1516==   total heap usage: 29,822 allocs, 5,263 frees, 1,457,307 bytes allocated
==1516==
==1516== 941,480 (64 direct, 941,416 indirect) bytes in 1 blocks are definitely lost in loss record 4 of 4
==1516==    at 0x4C3017F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==1516==    by 0x112912: MultiwayTrieSet::MultiwayTrieSet() (MultiwayTrieSet.cpp:7)
==1516==    by 0x10A134: main (SetTest.cpp:22)
==1516==
==1516== LEAK SUMMARY:
==1516==    definitely lost: 64 bytes in 1 blocks
==1516==    indirectly lost: 941,416 bytes in 24,558 blocks
==1516==      possibly lost: 0 bytes in 0 blocks
==1516==    still reachable: 0 bytes in 0 blocks
==1516==         suppressed: 0 bytes in 0 blocks
==1516==
==1516== For counts of detected and suppressed errors, rerun with: -v
==1516== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Part 3: Ternary Search Trees (TSTs) (20 points)
Unfortunately, when a MWT is sparse, it can waste a ***lot*** of space. The Ternary Search Tree (TST) is essentially the combination of a MWT and a BST, and it can be useful for contexts in which we would want to use a MWT (e.g. spell-checking and autocompletion) but don't have enough memory.

### Task 3a: Create ``3a.txt`` (5 points)
Imagine we have the following TST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0Acleft%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ac%20%5Blabel%3D%22c%22%5D%0Aa%20%5Blabel%3D%22a%22%5D%0Al1%20%5Blabel%3D%22l%22%5D%0Al2%20%5Blabel%3D%22l%22%20fontcolor%3D%22red%22%20color%3D%22red%22%5D%0Am%20%5Blabel%3D%22m%22%5D%0Ae%20%5Blabel%3D%22e%22%20fontcolor%3D%22red%22%20color%3D%22red%22%5D%0Aemid%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ai%20%5Blabel%3D%22i%22%5D%0An%20%5Blabel%3D%22n%22%5D%0Ad1%20%5Blabel%3D%22d%22%20fontcolor%3D%22red%22%20color%3D%22red%22%5D%0Ad2%20%5Blabel%3D%22d%22%20fontcolor%3D%22red%22%20color%3D%22red%22%5D%0Anright%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ac%20-%3E%20cleft%20%5Bcolor%3D%22transparent%22%5D%0Ac%20-%3E%20a%0Aa%20-%3E%20l1%0Al1%20-%3E%20l2%0Ac%20-%3E%20m%0Am%20-%3E%20e%0Ae%20-%3E%20emid%20%5Bcolor%3D%22transparent%22%5D%0Ae%20-%3E%20i%0Ai%20-%3E%20n%0An%20-%3E%20d1%0An%20-%3E%20d2%0An%20-%3E%20nright%20%5Bcolor%3D%22transparent%22%5D%0A%7D">

Create a file called ``3a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the list of strings (1 per line) that are contained in this TST (the order of the lines doesn't matter). For example, if it contained the strings ``niema`` and ``moshiri``, your file would contain the following:

```
niema
moshiri
```

The following would also be equally correct:

```
moshiri
niema
```

### Task 3b: Create ``3b.txt`` (5 points)
Imagine we have the following TST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0Ao1%20%5Blabel%3D%22o%22%5D%0Aa1%20%5Blabel%3D%22a%22%5D%0Ao1second%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao1third%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ah1%20%5Blabel%3D%22h%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ao1fifth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao1sixth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ar%20%5Blabel%3D%22r%22%5D%0Aa1left%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ah2%20%5Blabel%3D%22h%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Am1%20%5Blabel%3D%22m%22%5D%0Ag1%20%5Blabel%3D%22g%22%5D%0Aa2%20%5Blabel%3D%22a%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Am1right%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ag1left%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Aa3%20%5Blabel%3D%22a%22%5D%0Al%20%5Blabel%3D%22l%22%5D%0Ag2%20%5Blabel%3D%22g%22%5D%0Aa4%20%5Blabel%3D%22a%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Aa5%20%5Blabel%3D%22a%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ah1left%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ah1mid%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao2%20%5Blabel%3D%22o%22%5D%0Ah3%20%5Blabel%3D%22h%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Aa6%20%5Blabel%3D%22a%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Aa6left%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Aa6mid%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao3%20%5Blabel%3D%22o%22%5D%0Am2%20%5Blabel%3D%22m%22%5D%0Aa7%20%5Blabel%3D%22a%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ao1%20-%3E%20a1%0Ao1%20-%3E%20o1second%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20o1third%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20h1%0Ao1%20-%3E%20o1fifth%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20o1sixth%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20r%0Aa1%20-%3E%20a1left%20%5Bcolor%3D%22transparent%22%5D%0Aa1%20-%3E%20h2%0Aa1%20-%3E%20m1%0Am1%20-%3E%20g1%0Am1%20-%3E%20a2%0Am1%20-%3E%20m1right%20%5Bcolor%3D%22transparent%22%5D%0Ag1%20-%3E%20g1left%20%5Bcolor%3D%22transparent%22%5D%0Ag1%20-%3E%20a3%0Ag1%20-%3E%20l%0Aa3%20-%3E%20g2%0Ag2%20-%3E%20a4%0Al%20-%3E%20a5%0Ah1%20-%3E%20h1left%20%5Bcolor%3D%22transparent%22%5D%0Ah1%20-%3E%20h1mid%20%5Bcolor%3D%22transparent%22%5D%0Ah1%20-%3E%20o2%0Ao2%20-%3E%20h3%0Ar%20-%3E%20a6%0Aa6%20-%3E%20a6left%20%5Bcolor%3D%22transparent%22%5D%0Aa6%20-%3E%20a6mid%20%5Bcolor%3D%22transparent%22%5D%0Aa6%20-%3E%20o3%0Ao3%20-%3E%20m2%0Am2%20-%3E%20a7%0A%7D">

Create a file called ``3b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the list of strings (1 per line) that are contained in this TST (the order of the lines doesn't matter). For example, if it contained the strings ``niema`` and ``moshiri``, your file would contain the following:

```
niema
moshiri
```

The following would also be equally correct:

```
moshiri
niema
```

### Task 3c: Create ``3c.txt`` (5 points)
Imagine we have the following TST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0Ao1%20%5Blabel%3D%22o%22%5D%0Ad%0Ao1second%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao1third%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao1fourth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Au1%20%5Blabel%3D%22u%22%5D%0Ao1sixth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao1seventh%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao1eighth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0At1%20%5Blabel%3D%22t%22%5D%0Ao2%20%5Blabel%3D%22o%22%5D%0Aa%0Ao2second%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Au2%20%5Blabel%3D%22u%22%5D%0Ao2fourth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao2fifth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0At2%20%5Blabel%3D%22t%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ar1%20%5Blabel%3D%22r%22%5D%0Ar1left%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ak%20%5Bcolor%3D%22red%22%20fontcolor%3D%22red%22%5D%0As1%20%5Blabel%3D%22s%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Af%20%5Bcolor%3D%22red%22%20fontcolor%3D%22red%22%5D%0At3%20%5Blabel%3D%22t%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Au1right%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ar2%20%5Blabel%3D%22r%22%5D%0At1second%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao3%20%5Blabel%3D%22o%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0At1fourth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0At1fifth%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ai1%20%5Blabel%3D%22i%22%5D%0As2%20%5Blabel%3D%22s%22%5D%0Ai2%20%5Blabel%3D%22i%22%5D%0An%0Ag%20%5Bcolor%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ah%0Ao3mid%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ao3right%20%5Blabel%3D%22%22%20color%3D%22transparent%22%5D%0Ae%20%5Bcolor%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ao1%20-%3E%20d%0Ao1%20-%3E%20o1second%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20o1third%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20o1fourth%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20u1%0Ao1%20-%3E%20o1sixth%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20o1seventh%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20o1eighth%20%5Bcolor%3D%22transparent%22%5D%0Ao1%20-%3E%20t1%0Ad%20-%3E%20o2%0Ao2%20-%3E%20a%0Ao2%20-%3E%20o2second%20%5Bcolor%3D%22transparent%22%5D%0Ao2%20-%3E%20u2%0Ao2%20-%3E%20o2fourth%20%5Bcolor%3D%22transparent%22%5D%0Ao2%20-%3E%20o2fifth%20%5Bcolor%3D%22transparent%22%5D%0Au2%20-%3E%20b%0Ab%20-%3E%20t2%0Aa%20-%3E%20r1%0Ar1%20-%3E%20r1left%20%5Bcolor%3D%22transparent%22%5D%0Ar1%20-%3E%20k%0Ar1%20-%3E%20y%0Ay%20-%3E%20s1%0Au1%20-%3E%20f%0Au1%20-%3E%20t3%0Au1%20-%3E%20u1right%20%5Bcolor%3D%22transparent%22%5D%0At1%20-%3E%20r2%0At1%20-%3E%20t1second%20%5Bcolor%3D%22transparent%22%5D%0At1%20-%3E%20o3%0At1%20-%3E%20t1fourth%20%5Bcolor%3D%22transparent%22%5D%0At1%20-%3E%20t1fifth%20%5Bcolor%3D%22transparent%22%5D%0Ar2%20-%3E%20i1%0Ai1%20-%3E%20s2%0As2%20-%3E%20i2%0Ai2%20-%3E%20n%0An%20-%3E%20g%0Ao3%20-%3E%20h%0Ao3%20-%3E%20o3mid%20%5Bcolor%3D%22transparent%22%5D%0Ao3%20-%3E%20o3right%20%5Bcolor%3D%22transparent%22%5D%0Ah%20-%3E%20e%0A%7D">

Create a file called ``3c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the list of strings (1 per line) that are contained in this TST (the order of the lines doesn't matter). For example, if it contained the strings ``niema`` and ``moshiri``, your file would contain the following:

```
niema
moshiri
```

The following would also be equally correct:

```
moshiri
niema
```

### Task 3d: Create ``3d.txt`` (5 points)
Imagine we have the following TST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0Af1%20%5Blabel%3D%22f%22%5D%0Ae1%20%5Blabel%3D%22e%22%5D%0Aa1%20%5Blabel%3D%22a%22%5D%0Al1%20%5Blabel%3D%22l%22%5D%0Al2%20%5Blabel%3D%22l%22%5D%0Al3%20%5Blabel%3D%22l%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0As%0At%20%5Bcolor%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ae2%20%5Blabel%3D%22e%22%5D%0Aa2%20%5Blabel%3D%22a%22%5D%0Ae3%20%5Blabel%3D%22e%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Au%20%5Bcolor%3D%22red%22%20fontcolor%3D%22red%22%5D%0Aa3%20%5Blabel%3D%22a%22%5D%0Af2%20%5Blabel%3D%22f%22%5D%0Af3%20%5Blabel%3D%22f%22%5D%0Ay1%20%5Blabel%3D%22y%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Ac%0Ae4%20%5Blabel%3D%22e%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Af4%20%5Blabel%3D%22f%22%5D%0Af5%20%5Blabel%3D%22f%22%5D%0Ay2%20%5Blabel%3D%22y%22%20color%3D%22red%22%20fontcolor%3D%22red%22%5D%0Af1%20-%3E%20e1%0Ae1%20-%3E%20a1%0Aa1%20-%3E%20s%0As%20-%3E%20t%0Ae1%20-%3E%20l1%0Ae1%20-%3E%20l2%0Al1%20-%3E%20l3%0Al2%20-%3E%20e2%0Ae2%20-%3E%20a2%0Aa2%20-%3E%20a3%0Aa3%20-%3E%20f2%0Af2%20-%3E%20f3%0Af3%20-%3E%20y1%0Ae2%20-%3E%20e3%0Ae3%20-%3E%20c%0Ac%20-%3E%20e4%0Ae2%20-%3E%20u%0Au%20-%3E%20f4%0Af4%20-%3E%20f5%0Af5%20-%3E%20y2%0A%7D">

Create a file called ``3d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the list of strings (1 per line) that are contained in this TST (the order of the lines doesn't matter). For example, if it contained the strings ``niema`` and ``moshiri``, your file would contain the following:

```
niema
moshiri
```

The following would also be equally correct:

```
moshiri
niema
```

## Academic Integrity
This Programming Assignment (PA) must be completed 100% independently! You may only discuss the PA with the Tutors, TAs, and Instructors. You are free to use resources from the internet, but you are not allowed to blatantly copy-and-paste code. If you ever find yourself highlighting a code snippet, copying, and pasting into your PA, you are likely violating the Academic Integrity Policy. If you have any concerns or doubts regarding what you are about to do, *please* be sure to post on Piazza first to ask us if it is okay.

## Grading (100 points total)
* **Part 0: Weekly Reflection Survey**
    * 5 points for submitting the weekly reflection survey (extra credit)
    * 0 points for not submitting the weekly reflection survey
* **Part 1: Implementing the Set ADT**
    * 10 points for a correct ``ArrayListSet`` implementation (0 points for incorrect)
    * 10 points for a correct ``LinkedListSet`` implementation (0 points for incorrect)
    * 10 points for a correct ``RedBlackTreeSet`` implementation (0 points for incorrect)
    * 10 points for a correct ``HashTableSet`` implementation (0 points for incorrect)
* **Part 2: Implementing a Multiway Trie (MWT)**
    * 30 points for a correct ``MultiwayTrieSet`` implementation (0 points for incorrect)
* **Parts 1-2: Checking for Memory Leaks**
    * 10 points if Parts 1 and 2 have no memory leaks
    * 0 points if either Part 1 or Part 2 has any memory leaks
* **Part 3: Ternary Search Trees (TSTs)**
    * 5 points for a correct ``3a.txt`` (0 points for incorrect)
    * 5 points for a correct ``3b.txt`` (0 points for incorrect)
    * 5 points for a correct ``3c.txt`` (0 points for incorrect)
    * 5 points for a correct ``3d.txt`` (0 points for incorrect)
