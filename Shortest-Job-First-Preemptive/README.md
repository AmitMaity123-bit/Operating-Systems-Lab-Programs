# 📌 Shortest Job First (Preemptive)

## 📖 Introduction

Shortest Job First Preemptive Scheduling is also known as Shortest Remaining Time First (SRTF).

Whenever a new process arrives with a shorter remaining burst time, the currently running process is interrupted.

---

## 🎯 Objective

To implement SRTF Scheduling and calculate:

* Completion Time
* Turnaround Time
* Waiting Time

---

## 📂 Source File

SJF-Preemptive.c

---

## ▶️ How to Run

```bash
gcc SJF-Preemptive.c -o srtf
./srtf
```

## 🧪 Sample Input

```text
Enter number of processes: 3
Enter arrival time and burst time for process P1: 
Arrival Time: 0
Burst Time: 7
Enter arrival time and burst time for process P2: 
Arrival Time: 2
Burst Time: 4
Enter arrival time and burst time for process P3: 
Arrival Time: 4
Burst Time: 1
```

## 📤 Sample Output

```text
Process AT      BT      CT      TAT     WT
P1      0       7       12      12      5
P2      2       4       7       5       1
P3      4       1       5       1       0

Average Turnaround Time = 6.00
Average Waiting Time = 2.00
```

## ✅ Advantages

* Excellent response time
* Lower average waiting time

## ❌ Disadvantages

* Frequent context switching
* Complex implementation

## 📚 Applications

* Real-Time Systems
* Interactive Operating Systems
