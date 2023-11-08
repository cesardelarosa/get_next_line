# get_next_line

A function designed to read a file and retrieve its lines sequentially. It starts by returning the first line, then progresses to the next line with each subsequent call.

## Description

`char *get_next_line(int fd)` returns the n-th line from a file descriptor (fd) when it is called for the n-th time.

`char *read_line(char *line, int fd)` returns the concatenation of line string and the buffers read from fd until a '\n' character is found, therefore, the return does not neccesary ends with a '\n' char.

`char *save_tail(char *line)` makes line end with the first '\n' char and returns the rest of the line that is not returned.

The rest of the functions are contained in [libft](https://www.github.com/cesardelarosa/Libft), except a small change in `ft_strjoin` that frees the first input strring.

Bonus part requires using only one static variable and saving tails for each fd value used.
## Usage

### Download

```bash
git clone https://github.com/cesardelarosa/get_next_line.git get_next_line
```

### Compile and Run get_next_line

### Compile and Run get_next_line_bonus

## Personal
