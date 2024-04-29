# Get Next Line

## Summary
This project involves programming a function called `get_next_line` that returns a line read from a file descriptor. The goal is to read the text file pointed to by the file descriptor one line at a time.

## Project Repository
The project is included in my libft repository.
[get_next_line](https://github.com/ele-sage/42/blob/master/Core/libft/srcs/projects/get_next_line.c)

## Mandatory Part
### Function Name
`get_next_line`

### Prototype
```c
char *get_next_line(int fd);
```

### Parameters
`fd` is the file descriptor for reading.

### Return Value
`get_next_line` returns the line that has just been read. If there is nothing else to read or an error occurs, the function returns `NULL`.

### External Functions
`read`, `malloc`, `free`

### Description
Write a function that returns a line read from a file descriptor.

Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
Ensure that your function works as expected both when reading a file and when reading from the standard input.
The returned line should include the terminating \n character, except if the end of the file was reached and does not end with a \n character.

### Forbidden Functions
`lseek`