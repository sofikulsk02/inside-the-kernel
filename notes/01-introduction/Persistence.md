# Persistence

> Persistence is one of the core goals of an operating system — keeping data alive even when power does not.

Persistence is very important in terms of the overall goal of the system. We use data and we want that data to be persistently stored in memory or disks. In most cases, it should be **non-volatile** — if power goes or the system crashes, the data should survive.

## Table of Contents

1. [Abstraction](#abstraction)
2. [Protection](#protection)
3. [Reliability](#reliability)
4. [Other Factors](#other-factors)

## Abstraction

Abstraction is a layer that hides the complexity of the underlying task. It provides an interface or a high-level tool with the help of which you can easily achieve your goal.

**Example — a stack of abstraction layers:**

| Layer       | Hides the complexity of |
| ----------- | ----------------------- |
| C           | Assembly                |
| Assembly    | Binary / machine code   |
| Logic gates | Transistors             |
| Transistors | Electrical signals      |

So we have to understand the importance of abstraction.

## Protection

We have to keep in mind that we also have to provide protection to our OS and also to the applications. **Isolation** is the way we can protect a program.

## Reliability

We cannot afford the system to crash. The OS should always run. If the OS fails, then all the applications running on the OS will also fail. So the OS has to be reliable.

## Other Factors

Some other important factors include:

- **Energy efficiency** — power-aware design is critical.
- **Security** — protect data and resources from unauthorized access.
- **Mobility** — small devices run an OS, so portability matters too.

---

_Last updated: 06/12/2026_
