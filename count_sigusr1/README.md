# count_signals

Count number of SIGUSR1 signals received while process is running

# Usage

- Run count_signals, pid should be printed to stdout

```bash
./count_signals
```

- While process is running, from another shell send (1 or more) SIGUSR1 signals to printed pid

```bash
kill -SIGUSR1 <pid>
```

- Wait for count_signals process to finish and print amount of received signals

