_This project has been created as part of the 42 curriculum by apinho-a_

---
## Ft_printf
### **Description**

**ft_printf** is a custom C function that mimics the behavior of the standard `printf` function from `libc`. The primary goal is to learn how to handle **variadic functions** using a variable number of arguments.

### **Functionalities**

The library handles the following conversions:

- **%c**: Prints a single character.
    
- **%s**: Prints a string.
    
- **%p**: Prints a void pointer in hexadecimal format.
    
- **%d / %i**: Prints a base 10 decimal/integer.
    
- **%u**: Prints an unsigned decimal number.
    
- **%x / %X**: Prints a number in hexadecimal (base 16) lowercase or uppercase.
    
- **%%**: Prints a percent sign.
    

### **Instructions**

**Compilation** To create the `libftprintf.a` library, run the following at the root of the repository:

```
make
```

**File Management**

- `make clean`: Removes object files.
    
- `make fclean`: Removes object files and the `libftprintf.a` library and any leftover `.out`.
    
- `make re`: Recompiles the entire project.

- `make test`: To compile a test program.

>[!NOTE]
>All code adheres to **42 Norm V4**

### **Variadic arguments**

The project utilizes the `stdarg.h` macros (`va_start`, `va_arg`, `va_copy`, `va_end`) to iterate through the variable argument list. The core logic involves parsing a format string and dispatching the corresponding argument to specific helper functions based on the conversion character detected after each `%` symbol.

## **Resources**

### **References**

- **C Variadic Functions**: [GeekForGeek Variadic Function](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

### **LLM Usage Disclosure**

The learning process was assisted by Google Gemini for:
- **Conceptual Breakdown**: Explaining the initialization and cleanup of variadic lists.
- **Logic Verification**: Identifying edge cases for hexadecimal and pointer conversions.
- **Debugging**: Analyzing return values to ensure they match the original `printf` byte count.