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
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c tests/main.c
```

### Compile and Run get_next_line_bonus
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c tests/main_bonus.c
```
## Personal

I spent more time trying to make the functions simple than making a code that passed testers, since i read the proyect, I thought code had to be very easy but at first it didn't. Most codes I read on github seemed to me very complicated. In [simple_idea.c](https://www.github.com/cesardelarosa/get_next_line/simple_idea.c) I write in one function with less than 25 lines a perfect functional and clear function that works. The only inconviniet is that it does two assignments in an if control struct. However, I think it is very pedagogic to read that code.
