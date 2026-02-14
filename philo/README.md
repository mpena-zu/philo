*This project has been created as part of the 42 curriculum by mpena-zu.*

# Philosophers - The Dining Philosophers Problem

## Description
**Philosophers** is a project that explores the basics of process threading and synchronization. Based on the classic computer science problem—The Dining Philosophers—this project simulates a scenario where philosophers sit at a round table with a large bowl of spaghetti.

The challenge lies in managing limited resources (forks) among several competitors (philosophers). To eat, a philosopher must pick up two forks (one in each hand). The project requires implementing:
* **Multithreading**: Each philosopher is represented by a thread.
* **Mutexes**: Used to protect the state of each fork and prevent data races.
* **Synchronization**: Ensuring no philosopher dies of starvation while avoiding deadlocks.

## Instructions

### Compilation
The project includes a `Makefile` that compiles the source files into the `philo` executable. To compile, run:

make

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

./philo 5 800 200 200

