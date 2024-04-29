# ft_printf

## Summary
The goal of this project is to recode the `printf()` function, a popular and versatile C function. This exercise offers an opportunity to improve programming skills, especially in handling variable numbers of arguments. The successful completion of this assignment allows the addition of your `ft_printf()` to the `libft` library for use in future school C projects.

## Project Repository
The project is included in my libft repository.
[ft_printf](https://github.com/ele-sage/42/blob/master/Core/libft/srcs/projects/ft_printf.c)

### External Functions
`malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`

### Libft Authorized
Yes

### Description
Write a library that contains `ft_printf()`, a function that will mimic the original `printf()`.

You have to recode the `printf()` function from libc. The prototype of `ft_printf()` is:
```c
int ft_printf(const char *, ...);
```

### Conversions to Implement

| Conversion | Description |
| --- | --- |
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal integer (lowercase) |
| `%X` | Unsigned hexadecimal integer (uppercase) |
| `%%` | A `%` followed by another `%` will write a single `%` to the stream. |
