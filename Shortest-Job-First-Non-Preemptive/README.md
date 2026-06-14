# 📌 Shortest Job First (Non-Preemptive)

## 📖 Introduction

Shortest Job First (SJF) Non-Preemptive Scheduling Algorithm selects the process with the shortest burst time among the available processes.

Once a process starts execution, it runs until completion without interruption.

---

## 🎯 Objective

To implement SJF Non-Preemptive Scheduling and calculate:

* Completion Time (CT)
* Turnaround Time (TAT)
* Waiting Time (WT)

---

## ⚙️ Algorithm

1. Input Arrival Time and Burst Time.
2. Select the shortest available job.
3. Execute the selected process completely.
4. Calculate CT, TAT and WT.
5. Display the scheduling table.

---

## 📂 Source File

SJF-Non-Preemptive.c

---

## ▶️ How to Run

```bash
gcc SJF-Non-Preemptive.c -o sjf
./sjf
```

## 🧪 Sample Input

```text
Enter number of processes: 3
Enter Arrival Time and Burst Time for Process P1: 
Arrival Time: 0
Burst Time: 6
Enter Arrival Time and Burst Time for Process P2: 
Arrival Time: 1
Burst Time: 4
Enter Arrival Time and Burst Time for Process P3: 
Arrival Time: 2
Burst Time: 2
```

## 📤 Sample Output

```text
Process AT      BT      CT      TAT     WT
P1      0       6       6       6       0
P2      1       4       12      11      7
P3      2       2       8       6       4

Average Turnaround Time = 7.67
Average Waiting Time = 3.67
```

## ✅ Advantages

* Minimum average waiting time
* Better CPU utilization

## ❌ Disadvantages

* Starvation may occur
* Difficult to predict burst time

## 📚 Applications

* Batch Processing Systems
* Academic Scheduling Simulations
