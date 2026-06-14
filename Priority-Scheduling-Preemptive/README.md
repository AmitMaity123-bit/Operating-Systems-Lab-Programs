# 📌 Priority Scheduling (Preemptive)

## 📖 Introduction

The CPU always executes the highest priority process.

If a higher priority process arrives, the current process is interrupted immediately.

---

## 🎯 Objective

To simulate dynamic priority-based scheduling.

---

## 📂 Source File

Priority-Preemptive.c

---

## ▶️ How to Run

```bash
gcc Priority-Preemptive.c -o priorityp
./priorityp
```

## 🧪 Sample Input

```text
Enter number of processes: 3
Enter Arrival Time, Burst Time, and Priority for Process P1: 
Arrival Time: 0
Burst Time: 8
Priority: 2
Enter Arrival Time, Burst Time, and Priority for Process P2: 
Arrival Time: 1
Burst Time: 4
Priority: 1
Enter Arrival Time, Burst Time, and Priority for Process P3: 
Arrival Time: 2
Burst Time: 2
Priority: 3
```

## 📤 Sample Output

```text
Process AT      BT      PR      CT      WT      TAT
P1      0       8       2       12      4       12
P2      1       4       1       5       0       4
P3      2       2       3       14      10      12

Average Waiting Time = 4.67
Average Turnaround Time = 9.33
```

## ✅ Advantages

* Fast response to important processes
* Suitable for real-time systems

## ❌ Disadvantages

* Starvation
* More context switching

## 📚 Applications

* Embedded Systems
* Real-Time Operating Systems
