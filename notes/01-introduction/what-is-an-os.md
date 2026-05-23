### why do we call os is a virtual machine?

the work of os is to make sure that the system works properly and efficiently , to make sure the os does something called virtualizing the resources like we have physical devices involded (eg: ram ,cpu, memory,disks and all) .so the os takes the physical resource and transform it into something that is more general and easy to use virtual form of itself. thus sometime we mention os as virtual machine

the user need to tell the os when to start a program when to stop when there is a read ops and other tasks the os provides some apis for that

a typical os exports a few hundred system calls to control i/o run program and all we can say that the os provides some standrad library to the application

### why do we call os as a resource manager?

so we know that the os provides virtualization like we can run multiple programs at a time (sharing of cpu) many program to access their instruction and data cuncurrently(sharing of memory) and many program to access devices (sharing of disk). so all these are resources and the os has the job to manage them fairly and efficiently and keeping other goals to the mind

#### the relivant question is that if we some program when which one should run and what is the rules , to answer these questions we have polices in os we have different policies to answer these kind of scenarios.
