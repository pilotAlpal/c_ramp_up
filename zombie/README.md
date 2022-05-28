# my_zombie

Make zombie process

## Usage

- Run program to make zombie process

```bash
./my_zombie
```

- From another shell, while my_zombie is running search for parent and child (zombie) processes

```bash
ps -e -o pid,ppid,stat,cmd | grep my_zombie
```

- When parent finishes, both processes will be terminated. Can be checked with previous command


