# Virtualizing Memory

Memory virtualization gives each process the illusion that it has its own large, private address space. A program uses **virtual addresses**, while the hardware and operating system translate them to **physical addresses** in RAM.

## Why virtualize memory?

- **Isolation:** One process cannot ordinarily read or overwrite another process's memory.
- **Simplicity:** Programs can use a consistent address space without knowing where their data is located in physical memory.
- **Flexibility:** The operating system can move, share, or temporarily store memory without changing a program's virtual addresses.

## Address translation

The operating system manages mappings from virtual pages to physical **frames**. The Memory Management Unit (MMU) performs translations during execution. A **page table** stores mappings and permissions, and a **Translation Lookaside Buffer (TLB)** caches recent translations to speed them up.

Virtual memory is commonly divided into pages, with physical memory divided into equally sized frames. If a process accesses a page that is not currently in RAM, a **page fault** occurs. The operating system can load the page from storage, allocate a frame, or reject the access if it is invalid.

## Protection and sharing

Page-table entries can specify permissions such as readable, writable, and executable. These checks help enforce process isolation. At the same time, multiple processes may intentionally map the same physical page—for example, to share read-only program code or shared-memory data.

In short, virtual memory is an abstraction implemented jointly by hardware and the operating system. It provides convenient address spaces while enabling protection, controlled sharing, and efficient use of physical memory.
