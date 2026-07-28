# Persistence

Persistence is very important in terms of the overall goal of the system. We use data and we want that data to be persistently stored in memory or disks. In most cases, it should be **non-volatile** — if power goes or the system crashes, the data should survive.

## Abstraction

Abstraction is a layer that hides the complexity of the underlying task. It provides an interface or a high-level tool with the help of which you can easily achieve your goal.

For example, to perform certain tasks we write a program in C — we do not need to know Assembly, so the C layer is adding an abstraction. Similarly, we do not need to know about binary, so Assembly is another abstraction layer. Then again, we do not need to know about transistors, and again the logic gates, and so on.

So we have to understand the importance of abstraction.

## Protection

We have to keep in mind that we also have to provide protection to our OS and also to the applications. **Isolation** is the way we can protect a program.

## Reliability

We cannot afford the system to crash. The OS should always run. If the OS fails, then all the applications running on the OS will also fail. So the OS has to be reliable.

## Other Factors

Some other important factors include **energy efficiency**, **security**, and **mobility**.

We have small devices that run an OS, so mobility is also important.

### Change in the workflow from 6/12/2026
