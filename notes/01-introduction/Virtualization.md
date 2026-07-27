## Abstraction: The Process

Normally, a process is a running program.

### How to Provide the Illusion of Many CPUs?

Although there are only a few physical CPUs available, how can the OS provide the illusion of a nearly-endless supply of said CPUs?

The OS creates this illusion by **virtualizing the CPU**. By running one process, then stopping it and running another, and so forth, the OS can promote the illusion that many virtual CPUs exist when in fact there is only one physical CPU (or a few). This basic technique, known as **time sharing** of the CPU, allows users to run as many concurrent processes as they would like; the potential cost is performance, as each will run more slowly if the CPU(s) must be shared.

---

### 💡 Tip: Use Time Sharing (and Space Sharing)

Time sharing is one of the most basic techniques used by an OS to share a resource. By allowing the resource to be used for a little while by one entity, and then a little while by another, and so forth, the resource in question (e.g., the CPU, or a network link) can be shared by many.

The natural counterpart of time sharing is **space sharing**, where a resource is divided (in space) among those who wish to use it. For example, disk space is naturally a space-shared resource, as once a block is assigned to a file, it is not likely to be assigned to another file until the user deletes it.

---

### Policies: The OS Decision-Making

On top of these mechanisms resides some of the intelligence in the OS, in the form of **policies**. Policies are algorithms for making some kind of decision within the OS.

**Example:** Given a number of possible programs to run on a CPU, which program should the OS run?

A scheduling policy in the OS will make this decision, likely using:

| Information Type    | Example                                                              |
| ------------------- | -------------------------------------------------------------------- |
| Historical data     | Which program has run more over the last minute?                     |
| Workload knowledge  | What types of programs are run?                                      |
| Performance metrics | Is the system optimizing for interactive performance, or throughput? |

These inputs help the OS make intelligent scheduling decisions.
