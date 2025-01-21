
# Job Scheduling with Deadlines

This project implements a Job Scheduling with Deadlines problem using DP to maximize profit. The goal is to schedule jobs with deadlines in such a way that the total profit is maximized while respecting the constraints of job deadlines.

It Features: DP approach for maximizing profit.
Queue to manage job execution order.
Stack for handling job dependencies.

## Problem Description:
You are given a set of jobs where each job has:
- A deadline by which it must be completed.
- A profit earned after completing the job.

The task is to select jobs that can be completed before their deadlines and maximize the total profit.

## Key Concepts:
DP: Used to find the optimal solution for job scheduling.
Greedy Approach: Helps in selecting jobs that yield the maximum profit within their deadlines.

## How to Run:
1. Clone the repository:
   ```bash
   git clone https://github.com/Atharva-099/JobScheduling.git
   ```

2. Compile the code:
   ```bash
   g++ main.cpp -o JobScheduling.exe
   ```

3. Run the executable:
   ```bash
   ./JobScheduling.exe
   ```

## Example Input:
```plaintext
Job 1: Deadline = 4, Profit = 20
Job 2: Deadline = 1, Profit = 10
Job 3: Deadline = 2, Profit = 40
Job 4: Deadline = 3, Profit = 30
```

## Example Output:
The optimal job schedule would be:
- Job 3 (Deadline 2, Profit 40)
- Job 1 (Deadline 4, Profit 20)

Total Profit = 60
