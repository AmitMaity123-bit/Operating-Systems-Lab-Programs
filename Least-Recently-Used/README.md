# 📌 Least Recently Used (LRU)

## 📖 Introduction

Least Recently Used (LRU) is a Page Replacement Algorithm used in Operating Systems.

When a page fault occurs, the page that has not been used for the longest period is replaced.

---

## 🎯 Objective

To simulate page replacement using the LRU strategy and calculate total page faults.

---

## 📂 Source File

LRU.c

---

## ▶️ How to Run

```bash
gcc LRU.c -o lru
./lru
```

## 🧪 Sample Input


 Enter total number of pages: 7 Enter the page reference string:1 2 3 4 1 2 5

## 📤 Sample Output

```text
Frame Status

1 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
1 2 - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
1 2 3 - - - - - - - - - - - - - - - - - - - - - - - - - - - 
1 2 3 4 - - - - - - - - - - - - - - - - - - - - - - - - - - 
1 2 3 4 - - - - - - - - - - - - - - - - - - - - - - - - - - 
1 2 3 4 - - - - - - - - - - - - - - - - - - - - - - - - - - 
1 2 3 4 5 - - - - - - - - - - - - - - - - - - - - - - - - - 

Total Page Faults = 5
```

## ✅ Advantages

* Good performance
* Practical implementation

## ❌ Disadvantages

* Additional memory overhead
* Complex tracking mechanism

## 📚 Applications

* Virtual Memory Management
* CPU Cache Management
* Database Buffer Management
