# 📌 First Come First Serve (FCFS)

## 📖 Introduction

First Come First Serve (FCFS) is the simplest CPU Scheduling Algorithm.

In this scheduling technique, the process that arrives first in the ready queue gets executed first.

FCFS follows the FIFO (First In First Out) principle.

---

## 🎯 Objective

To simulate the FCFS Scheduling Algorithm and calculate:

* Completion Time (CT)
* Turnaround Time (TAT)
* Waiting Time (WT)

---

## ⚙️ Algorithm

1. Input Arrival Time and Burst Time.
2. Sort processes according to Arrival Time.
3. Execute processes one by one.
4. Calculate Completion Time.
5. Calculate Turnaround Time.
6. Calculate Waiting Time.
7. Display results.

---

## 📐 Formula

Turnaround Time (TAT)

```text
TAT = Completion Time - Arrival Time
```

Waiting Time (WT)

```text
WT = Turnaround Time - Burst Time
```

---

## 📂 Source File

```text
FCFS.c
```

---

## ▶️ How to Run

```bash
gcc FCFS.c -o FCFS
./FCFS
```

---

## 🧪 Sample Input

```text
Enter the number of processes: 3
Enter Arrival Time and Burst Time for each process:
Process 1:- 
Arrival Time: 0
Burst Time: 5
Process 2:- 
Arrival Time: 1
Burst Time: 3
Process 3:- 
Arrival Time: 2
Burst Time: 8
```

---

## 📤 Sample Output

```text
Process AT BT CT TAT WT

1       0  5  5   5   0
2       1  3  8   7   4
3       2  8 16  14   6
```

---

## ✅ Advantages

* Easy to implement
* Low overhead
* Simple logic

---

## ❌ Disadvantages

* Convoy Effect
* Poor response time
* Not suitable for time-sharing systems

---

## 📚 Applications

* Batch Processing Systems
* Simple Queue Management
* Educational Demonstrations

---

## 👨‍💻 Author

Amit Kumar Maity
