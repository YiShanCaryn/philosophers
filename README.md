# philosophers

Implementation of the classic **Dining Philosophers** concurrency problem using **POSIX threads (pthreads)** and **mutexes**.

This project focuses on:
- Creating and synchronizing multiple threads
- Preventing data races with mutexes
- Coordinating shared resources (forks) safely
- Detecting philosopher death and stopping the simulation

## Program

The binary name is:

- `philo`

Built with `-pthread` (see `Makefile`).

## Rules / Simulation

- Each philosopher is a thread.
- Forks are shared resources protected by mutexes.
- Philosophers repeat the cycle: **think → take forks → eat → sleep**.
- A philosopher **dies** if they do not eat within `time_to_die` milliseconds.
- The simulation stops when:
  - a philosopher dies, or
  - all philosophers have eaten `number_of_times_each_philosopher_must_eat` times (if provided).

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All times are in **milliseconds**.

### Arguments

1. `number_of_philosophers`  
   Number of philosophers (and forks).  
   The project caps philosophers with `MAX_PHILOS` (defined in `philo.h`).

2. `time_to_die`  
   Time (ms) after last meal before a philosopher dies.

3. `time_to_eat`  
   Eating duration (ms).

4. `time_to_sleep`  
   Sleeping duration (ms).

5. *(optional)* `number_of_times_each_philosopher_must_eat`  
   If provided, the program ends once everyone has eaten at least this many times.

### Example

```bash
./philo 5 800 200 100
```

```bash
./philo 5 800 200 100 7
```

## How the code works (overview)

### Core data structures (`philo.h`)

- **`t_table`**: global simulation state shared by all threads  
  Stores input parameters, start time, stop flag, global mutexes, fork array, and philosopher array.

- **`t_philo`**: per-philosopher state  
  Stores the thread id, philosopher id, pointers to its two forks, meal counters, last meal time, and a `meal_lock` mutex.

- **`t_fork`**: one fork = one mutex  
  Each fork has a `pthread_mutex_t` used to ensure only one philosopher can hold that fork at a time.

### Program flow

1. **Argument checks** (`philo.c`)  
   Validates the number of arguments and that values are positive / within limits.

2. **Input parsing** (`init_input`)  
   Fills `t_table` fields from `argv` (`num_of_philos`, `time_to_die`, `time_to_eat`, `time_to_sleep`, and the optional meal limit).

3. **Initialization** (`init_program`)  
   - Allocates `table->forks` and initializes each fork mutex  
   - Allocates `table->philo` and sets up each philosopher (id, fork pointers, counters)  
   - Initializes global mutexes (`dead_lock`, `table_mutex`) and per-philosopher `meal_lock`  
   - Sets `table->start_time`

4. **Thread creation** (`thread_create`)  
   - Starts one thread per philosopher running `dinner_routine`  
   - Starts a dedicated `monitor_routine` thread to detect death / completion

### Philosopher routine (what each philosopher thread does)

Each philosopher loops until the simulation ends:

1. **Eat** (`philo_eat`)  
   - Locks two fork mutexes (picks up forks)  
   - Updates `last_meal_time` and `num_meals_eaten` under `meal_lock` (prevents races with monitor)  
   - Sleeps for `time_to_eat` to simulate eating  
   - Unlocks forks (puts them down)

2. **Sleep** (`philo_sleep`)  
   Sleeps for `time_to_sleep`.

3. **Think** (`philo_think`)  
   Prints/thinks, then tries to eat again.

### Monitor thread (death + optional completion)

The monitor checks in a loop:

- **Death detection**:  
  For each philosopher, reads `last_meal_time` under `meal_lock`.  
  If `now - last_meal_time > time_to_die`, it ends the simulation.

- **Meal limit completion** (if optional argument is provided):  
  Ends the simulation once all philosophers have eaten at least `num_times_to_eat`.

When stopping, the monitor sets `table->end_flag` under `dead_lock`.  
Philosopher threads regularly check this flag (often via `dead_loop`) and exit cleanly.

### Printing / synchronization

- Forks are protected by fork mutexes (`t_fork.fork`)
- Shared stop state (`end_flag`) is protected by `dead_lock`
- Meal-related values (`last_meal_time`, `num_meals_eaten`) are protected by `meal_lock`
- Output is typically protected by a global mutex (`table_mutex`) so messages don’t interleave

## Build

```bash
make
```

Other rules:

```bash
make clean
make fclean
make re
```

## Output

The program prints timestamped status messages for philosophers (e.g. taking forks, eating, sleeping, thinking, dying).  
Timestamps are relative to the simulation start time.

## Project Structure (high level)

- `philo.c` — argument validation + program entry point
- `init.c` — parses input and initializes table/philosophers/forks
- `thread_create.c` — starts philosopher threads + monitor thread
- `philos_routine.c` — philosopher routine (eat/sleep/think loop)
- `monitor_routine.c` — checks death / completion conditions
- `utils.c` — helpers (`ft_atoi`, timing, sleep, printing, cleanup)
- `philo.h` — structs, constants, and function prototypes
- `Makefile` — build rules

## Notes

- Uses `pthread_mutex_t` to protect forks and shared state.
- Includes a monitor thread to detect death and stop conditions cleanly.
- Designed for the 42-school “philosophers” project constraints.

## Author

- YiShan
