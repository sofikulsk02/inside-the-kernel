## The Crux of the Problem: How to Build Correct Concurrent Programs

When there are many concurrently executing threads within the same memory space, how can we build a correctly working program? What primitives are needed from the OS? What mechanisms should be provided by the hardware? How can we use them to solve the problems of concurrency?

### The Main Problem

The main problem of concurrency arises from **shared, mutable state** accessed by multiple threads:

- **Race conditions**: The outcome of a program depends on the non-deterministic interleaving of thread executions. Two threads accessing shared data simultaneously can produce incorrect results.
- **Atomicity violation**: Operations that should execute as a single indivisible step get interrupted by other threads (e.g., `x = x + 1` is actually a read-modify-write sequence).
- **Ordering violations**: One thread expects data to be produced by another thread in a specific order, but no such guarantee exists by default.

**Example — a race condition:**

```c
// Shared variable
int balance = 0;

// Thread A                // Thread B
balance = balance + 1;     balance = balance + 1;
```

Expected result: `balance = 2`. Actual result may be `1` because the read-modify-write sequences interleave:

```
T1 reads balance (0)
T2 reads balance (0)
T1 writes balance + 1 (1)
T2 writes balance + 1 (1)   // lost update!
```

The **problem** is: without help from the OS and hardware, we cannot reason about _when_ a thread's instructions execute relative to another's, making correctness hard to guarantee.
