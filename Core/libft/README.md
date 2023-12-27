# Libc functions

## Introduction
This project involves creating a C library, named libft, which will include a variety of general-purpose functions. These functions replicate the behavior of standard libc functions but are prefixed with 'ft_'.

## Program Name
`libft.a`

## Files
- `Makefile`
- `libft.h`
- `ft_*.c` (individual files for each function)
- `NAME`, `all`, `clean`, `fclean`, `re` (Makefile rules)

## External Functions
None

## Description
This library serves as a collection of functions that will be essential for future C school assignments. The functions implemented in this part replicate the behavior of standard libc functions but with a 'ft_' prefix.

## Technical Considerations
- Global variables are forbidden.
- Helper functions should be declared as static to limit their scope.
- All .c files must compile with the flags `-Wall -Wextra -Werror`.
- The library must be created using the `ar` command.

## Part 1
- `ft_toupper`
- `ft_isalpha`
- `ft_isdigit`
- `ft_tolower`
- `ft_isalnum`
- `ft_isascii`
- `ft_strchr`
- `ft_isprint`
- `ft_strrchr`
- `ft_strlen`
- `ft_strncmp`
- `ft_memset`
- `ft_bzero`
- `ft_memchr`
- `ft_memcpy`
- `ft_memcmp`
- `ft_memmove`
- `ft_strnstr`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_atoi`

## Part 2

### `ft_substr`
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```
Allocates and returns a substring from the string `s`.
The substring starts at index `start` and has a maximum size of `len`.

### `ft_strjoin`
```c
char *ft_strjoin(char const *s1, char const *s2);
```
Allocates and returns a new string, the result of concatenating 's1' and 's2'.
### `ft_strtrim`
```c
char *ft_strtrim(char const *s1, char const *set);
```
Allocates and returns a trimmed copy of 's1', removing specified characters from the beginning and end.
### `ft_split`
```c
char **ft_split(char const *s, char c);
```
Allocates and returns an array of strings obtained by splitting 's' using 'c' as a delimiter. The array ends with a NULL pointer.
### `ft_itoa`
```c
char *ft_itoa(int n);
```
Allocates and returns a string representing the integer 'n'. Handles negative numbers.

## Bonus Part

### `List Structure`
```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```
These functions should be added to the libft.a by including a make bonus rule in the Makefile.

### `ft_lstnew`
```c
t_list *ft_lstnew(void *content);
```
Allocates and returns a new node. Initializes 'content' with the provided value and sets 'next' to NULL.
### `ft_lstadd_front`
```c
void ft_lstadd_front(t_list **lst, t_list *new);
```
Adds the node 'new' at the beginning of the list.
### `ft_lstsize`
```c
int ft_lstsize(t_list *lst);
```
Counts the number of nodes in a list.
### `ft_lstlast`
```c
t_list *ft_lstlast(t_list *lst);
```
Returns the last node of the list.
### `ft_lstadd_back`
```c
void ft_lstadd_back(t_list **lst, t_list *new);
```
Adds the node 'new' at the end of the list.
### `ft_lstdelone`
```c
void ft_lstdelone(t_list *lst, void (*del)(void*));
```
Frees the memory of the node's content using the provided 'del' function and frees the node.
### `ft_lstclear`
```c
void ft_lstclear(t_list **lst, void (*del)(void*));
```
Deletes and frees the given node and every successor of that node, using the 'del' function.
### `ft_lstiter`
```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```
Iterates the list 'lst' and applies the function 'f' on the content of each node.
### `ft_lstmap`
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
Iterates the list 'lst' and applies the function 'f' to the content of each node. Creates a new list resulting of the successive applications of the function 'f'. The 'del' function is used to delete the content of an element if needed.