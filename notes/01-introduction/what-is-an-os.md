# What is an Operating System?

An **operating system (OS)** is the layer of software that sits between the user/applications and the underlying hardware. Its job is to ensure that the system works **properly**, **efficiently**, and **fairly**. To do this, it performs **virtualization of resources** and acts as a **resource manager**.

There are two main ways to describe what an OS does: as a **virtual machine** and as a **resource manager**. Both views are complementary and true at the same time.

## Why do we call the OS a virtual machine?

The OS takes **physical resources** (e.g., RAM, CPU, disks, network cards) and transforms them into a more general, easy-to-use **virtual form**. For example:

| Physical reality                                 | Virtual view the OS provides                         |
| ------------------------------------------------ | ---------------------------------------------------- |
| One CPU running one instruction stream at a time | Many programs appear to run at the same time         |
| A fixed amount of RAM                            | Each program believes it owns its own private memory |
| One disk with sectors and tracks                 | Files and directories                                |

Because the OS hides this messy physical reality behind a clean illusion, we call it a **virtual machine**.

The user (or a program on the user's behalf) needs to tell the OS when to:

- Start a program (`fork` / `exec` on Unix, `CreateProcess` on Windows)
- Stop a program (`exit` / `TerminateProcess`)
- Perform a read or write operation (`read` / `write` system calls)
- Perform other tasks (network communication, file creation, etc.)

The OS exposes an **API** for these actions. A typical OS exports a few hundred **system calls** to control I/O, run programs, manipulate files, and perform other operations. In this sense, the OS provides a kind of _standard library_ to applications — but unlike a normal library, these calls transition from **user mode** to **kernel mode**.

## Why do we call the OS a resource manager?

Virtualization is essentially _sharing_ — and any time you share something, you need to **manage** it. The OS manages physical resources so that many programs can use them concurrently:

- **CPU**: Multiple programs run at the same time by _time-sharing_ the processor (rapid context switching gives the illusion of simultaneity on a single core, and true parallelism on multiple cores).
- **Memory**: Many programs access their instructions and data concurrently by giving each one its own _virtual address space_, backed by physical RAM pages that may be swapped to disk when needed.
- **Disks**: Many programs access storage by owning their own files, while the OS enforces permissions and queues I/O requests fairly.
- **Network**: Many programs send and receive packets by multiplexing them through a single physical interface (sockets, ports, queues, etc.).

All of these are **resources**, and the OS has the job of managing them _fairly_, _efficiently_, and _securely_, while keeping other goals in mind (predictability, responsiveness, energy usage, etc.).

### Mechanisms vs. Policies

A key distinction in OS design is between **mechanisms** and **policies**:

- A **mechanism** is _how_ something is done. Example: a priority-based CPU scheduler is a mechanism.
- A **policy** is _which_ choice is made. Example: the rule "interactive processes get higher priority" is a policy.

> If we have multiple runnable programs, which one should run next? The OS needs both a mechanism (a scheduler) and a policy (e.g., round-robin, shortest-job-first, fair-share, real-time priority). Different policies exist to handle different scenarios — desktops favor responsiveness, servers favor throughput, real-time systems favor deadlines.

## Virtualizing memory

The physical memory of modern machines is conceptually very simple: an **array of bytes**. To read or write a byte, the CPU needs its **address** (a location/index in that array). Everything the program does — loading instructions, reading a variable, allocating a string — boils down to fetching bytes from these addresses.

So why does memory need _virtualization_? Because naively letting every program use physical addresses directly causes several problems:

- **Isolation**: Program A could read or overwrite Program B's memory (no protection between users/processes — a security and stability disaster on a multi-tasking system).
- **Limited size**: A program larger than physical RAM simply cannot run, and there is no way to give the illusion of _more_ memory than is physically installed.
- **Fragmentation**: Without a clean abstraction, programs must be aware of where they are loaded in RAM, making relocatable code and dynamic allocation painful.

The OS solves these problems by giving each process its own **virtual address space**. The hardware **Memory Management Unit (MMU)** translates every virtual address into a physical address on the fly, using tables maintained by the OS. With this in place:

- Each program believes it owns a contiguous, private memory starting at address `0`.
- Programs are isolated from one another — one process cannot touch another's memory without explicit permission (e.g., `mmap` / shared memory / `shm`).
- The OS can spill rarely-used pages to disk (**paging** / **swapping**), giving programs the illusion of a memory much larger than the physical RAM installed.

## PID: Process Identifier

A **PID** (Process Identifier) is a unique integer number assigned by the OS to **every running process**. PIDs are the primary handle the OS — and other processes — use to refer to a specific process (e.g., to send it a signal, wait for it to terminate, or check its status via `/proc/<pid>` on Unix-like systems, or Task Manager on Windows).
