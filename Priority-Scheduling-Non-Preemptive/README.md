# 📌 Priority Scheduling (Non-Preemptive)

## 📖 Introduction

Priority Scheduling selects the process with the highest priority.

Lower priority number generally represents higher priority.

Once a process starts execution, it cannot be interrupted.

---

## 🎯 Objective

To schedule processes according to priority values.

---

## 📂 Source File

Priority-Non-Preemptive.c

---

## ▶️ How to Run

```bash
gcc Priority-Non-Preemptive.c -o priority
./priority
```

## 🧪 Sample Input

```text
Enter number of processes: 3
Enter Arrival Time, Burst Time, and Priority for Process P1: 
Arrival Time: 0
Burst Time: 5
Priority: 2
Enter Arrival Time, Burst Time, and Priority for Process P2: 
Arrival Time: 1
Burst Time: 4
Priority: 1
Enter Arrival Time, Burst Time, and Priority for Process P3: 
Arrival Time: 2
Burst Time: 3
Priority: 3
```

## 📤 Sample Output

```text
Process AT      BT      PR      CT      WT      TAT
P1      0       5       2       5       0       5
P2      1       4       1       9       4       8
P3      2       3       3       12      7       10

Average Waiting Time = 3.67
Average Turnaround Time = 7.67
```

## ✅ Advantages

* Important tasks execute first
* Flexible scheduling

## ❌ Disadvantages

* Starvation problem
* Priority inversion

## 📚 Applications

* Embedded Systems
* Critical Task Management
