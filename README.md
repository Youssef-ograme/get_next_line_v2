*This project has been created as part of the 42 curriculum by yoograme.*

# get_next_line

## Description

**get_next_line** is a 42 project whose goal is to write a function that returns one line at a time from a file descriptor:

```c
char *get_next_line(int fd);
```

It returns the line read (including `\n` when present), or `NULL` when there is nothing left to read or on error. The read buffer size is set at compile time with `-D BUFFER_SIZE=n`. Allowed functions: `read`, `malloc`, `free`.

## Instructions

Compile (with or without the flag, a default `BUFFER_SIZE` is defined in the header):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Run:

```bash
./gnl file.txt
```

Bonus (multiple file descriptors):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Algorithm

The function uses a **static variable (stash)** that keeps data already read but not yet returned. On each call:

1. Read `BUFFER_SIZE` bytes and append them to the stash until it contains a `\n`, or until end of file or error.
2. Extract the line from the stash, up to and including the first `\n`.
3. Keep only the remaining part in the stash, and free the rest.

**Why this algorithm:**
- A static variable keeps the leftover between calls (global variables are forbidden).
- It reads only until the current line is complete, instead of loading the whole file.
- It works with any `BUFFER_SIZE`: with `1` it reads byte by byte, with a huge value the extra data stays in the stash for the next calls.
- Time is linear in the file size, `O(n)`.

**Bonus:** the stash is an array indexed by fd (`static char *stash[FD_MAX]`), so each file descriptor keeps its own state with a single static variable.

## Resources

- `man 2 read`, `man 3 malloc`
- [File descriptor - Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)
- [Static variables in C - GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)

**Use of AI:** AI was used only to proofread this README and to clarify concepts (static variables, `read` behavior). All the code was written and understood by me.