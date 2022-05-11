# Overview
Practicing MPI and other paradigms. In this file, you can find notes from my class in parallel programming.

# Sequential Consistency
During the running of these programs, you will find that you may get results in a different order each time. This is becuase modern machines do not satisfy sequential consistency. Sequential consistency is a conservative memory model that does not allow any instruction reordering on each core. Because not all programs need to run in sequential ordering, this can constrain the performance of a program if the memory model enforces sequential consistency. Ensuring correctness of a program that runs on moderns machines, which are not sequentially consistent, is a principle concept in parallel programming. 


