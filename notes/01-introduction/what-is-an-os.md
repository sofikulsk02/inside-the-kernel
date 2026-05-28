### Why do we call the OS a virtual machine?

The job of the operating system (OS) is to ensure that the system works properly and efficiently. To achieve this, the OS performs something called virtualization of resources. We have physical devices involved (e.g., RAM, CPU, memory, disks, etc.), and the OS takes these physical resources and transforms them into a more general and easy-to-use virtual form. Thus, sometimes we refer to the OS as a virtual machine.

The user needs to tell the OS when to start a program, when to stop it, when to perform a read operation, and other tasks. The OS provides APIs for these actions.

A typical OS exports a few hundred system calls to control I/O, run programs, and perform other operations. In this sense, we can say that the OS provides a kind of standard library to applications.

### Why do we call the OS a resource manager?

We know that the OS provides virtualization. For example:

Multiple programs can run at the same time (sharing the CPU).

Many programs can access their instructions and data concurrently (sharing memory).

Many programs can access devices (sharing disks).

All these are resources, and the OS has the job of managing them fairly and efficiently, while keeping other goals in mind.

The relevant question is: if we have multiple programs, which one should run, and what rules decide this? To answer these questions, the OS uses policies. Different policies exist to handle such scenarios.

Virtualizing memory
The model of physical memory represented by modern machines is very simple. Nowadays, it is just an array of bytes.

To read or write from memory, we need the address.

PID: Process Identifier
A PID is a unique identifier assigned to every process.
