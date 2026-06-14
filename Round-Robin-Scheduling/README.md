# 📌 Round Robin Scheduling

## 📖 Introduction

Round Robin Scheduling allocates CPU time equally among all processes.

Each process receives a fixed Time Quantum.

---

## 🎯 Objective

To implement fair CPU scheduling using Time Quantum.

---

## 📂 Source File

Round-Robin.c

---

## ▶️ How to Run

```bash
gcc Round-Robin.c -o rr
./rr
```

## 🧪 Sample Input

```text
Enter number of processes: 3
Enter arrival time and burst time for process P1:
Arrival Time: 0
Burst Time: 5
Enter arrival time and burst time for process P2:
Arrival Time: 1
Burst Time: 3
Enter arrival time and burst time for process P3:
Arrival Time: 2
Burst Time: 7
Enter time quantum: 2
```

## 📤 Sample Output

```text
Process AT BT CT WT TAT

P1      0 5 12 7 12
P2      1 3  9 5  8
P3      2 7 15 6 13
```

## ✅ Advantages

* Fair scheduling
* No starvation

## ❌ Disadvantages

* Context switching overhead
* Performance depends on Time Quantum

## 📚 Applications

* Time Sharing Systems
* Multi-user Operating Systems
