# ft_printf

This project aims to reproduce the BSD command printf and compile it into a library, with few options:

| handler | conversion specifiers |
| ---: | :----|
| c | unsigned char |
| C | extended char |
| d | int |
| D | long int to signed decimal |
| i | int |
| o | unsigned octal |
| O | long int to unsigned octal |
| p | void pointer adress, printed as hexadecimal |
| s | string |
| S | wide string (wchar_t *) |
| u | unsigned decimal |
| U | long int to unsigned decimal |
| x | unsigned hexadecimal |
| X | same as x, with capital letters |


#### Flags and Modifiers available

| flags | modifiers |
| :------: | :------: |
| # | h |
| 0 | hh |
| - | l |
| + | ll |
| ' ' | j |
|  | z |

#### Clone the repository and compile with
```bash
 $> make -j
 $> gcc <your_files.c> -L . -l ftprintf -I ./includes -I ./libft/includes/
```


#### Prototype and usage:
```c
  int   ft_printf(const char *format, ...);

  ft_printf("%[flag][padding][precision][modifier][conversion]", ...);
```

#### Author
Hugo Weber
huweber@student.42.fr
