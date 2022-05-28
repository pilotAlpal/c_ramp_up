# spawn_example

Create a child process to run custom command and wait until it finishes

> If no command is provided as arg, child will run ```ls -lart /```


> If custom command is provided, it is expected as arguments list (unquoted)

## Usage examples

Default command

```bash
./spawn_example
```

Custom command with 0 exit

```bash
./spawn_example ls -lart .
```

Custom command with no 0 exit

```bash
./spawn_example ls -lart /bad_dir
```

Exit abnormally

```bash
./spawn_example not_a_command
```

