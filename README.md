 
# Scheduler simulator

The aim of this project is to simulate a scheduler. The program reads a list of processes from a file and simulates the scheduling process based on the given options.
We have implemented two scheduling options and two dispatching policies.


## How to compile
To compile this program use ```make```. If you want a clean build, just use ```make clean && make```.

## How to execute

To execute the program, you should specify a scheduling policy, a dispatching policy, the file to read, number of CPUs, cores, hthreads and GPUs and the quantum.

``` ./sim queue_policy execution_policy file_name cpu core hthread gpu quantum```

#### Scheduling policies 
* **fifo**: First in first out. The processes will be scheduled in order.
* **priority**: The processes will be scheduled acording to the predefined priority.

#### Dispatching policies
* **preemptive**: Each process will be executed a limited time (quantum) of cycles before is dispatched. 
* **nopreemptive**: Each process will be executed until it ends.

### Structure of the file

For each process to read, you should add a line containing the number of cycles and the priority. 
Example:
```
15 4
50 1
20 8
66 2
```

## Authors

* **Aitor Belenguer** 
* **Aritz Herrero**

