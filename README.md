# 📖 Get Next Line

**Read a line from a file descriptor with ease**

![GitHub code size](https://img.shields.io/github/languages/code-size/husaltam/get_next_line)
![GitHub last commit](https://img.shields.io/github/last-commit/yourusername/get_next_line)
![Lines of code](https://img.shields.io/tokei/lines/github/yourusername/get_next_line)

## 🌟 About

Get Next Line is a 42 school project that teaches you about static variables, file descriptors, and reading files in C. This function reads a file line by line, making it perfect for parsing files or reading standard input.

## 🚀 Features

- Reads from any file descriptor (files, stdin, etc.)
- Handles multiple file descriptors simultaneously
- Configurable buffer size via compile-time flag
- Efficient single static variable implementation
- Properly manages memory (no leaks)
- Compliant with 42 school norms

## 📦 Installation

1. Clone the repository:
```bash
git clone https://github.com/husaltam/get_next_line.git
cd get_next_line
```

## Compile with your desired buffer size:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
---
## 🛠 Usage
Creat your own test.c file like this one, or just uncomment the main function in `get_next_line.c`
```
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
## 🧪 Testing
The project includes a comprehensive test suite. Run tests with:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c test.c -o test && ./test
```

---
## 📜 Documentation
Function Prototype
```
char *get_next_line(int fd);
```
### Parameters
`fd`: The file descriptor to read from

### Return Value
- On success: Returns the read line (including '\n' if present)
- On EOF or error: Returns NULL

### 🏆 Bonus / To be added later...
The bonus part implements:

- Multiple file descriptor management
- Single static variable approach
- Ultra-fast performance even with tiny buffer sizes

## 📚 Resources
- 42 Docs
- File Descriptors Explained
- Understanding Static Variables
