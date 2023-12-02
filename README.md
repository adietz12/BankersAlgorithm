# BankersAlgorithm
OS programming assingment #2

By Anthony Dietz

This project demonstrate the use of the Banker's algorith mto avoid deadlocks in operating systems. The project has two files, a main.cpp file and a data.txt file. The main reads off whatever values are in the data file.
## data file
data.txt has four groups;

line 1 defines the number of processes and resources

lines 4-8 define the allocation matrix

lines 11-15 define the MAX matrix

line 17 defines the available resources

These can be changed to any number but for this purpose it is set as given from the assignment on canvas.

## main
The main.cpp file implements the Banker's Algorithm, a deadlock avoidance mechanism in operating systems. It begins by reading process and resource data from a file, initializing matrices representing resource allocation, maximum resource needs, and available resources. The algorithm then iterates through processes, identifying and executing those that can safely proceed without causing a deadlock. If a safe sequence is found, it is printed to the console; otherwise, an error message indicating the absence of a safe sequence is displayed. The implementation ensures efficient resource utilization and helps prevent system-wide deadlocks.

## To run program
```bash
g++ -o main main.cpp

./main
```

## Example

![image](https://github.com/adietz12/BankersAlgorithm/assets/150217383/b7b1273d-009e-4272-95f1-53b004e5b354)
Code shows the output of the bankers algorithm



