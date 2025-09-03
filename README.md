# get_next_line

This project is all about creating a function that reads a **line from a file descriptor** — no matter how long it is.  
The function returns one line at a time, making it perfect for handling files, standard input, or even pipes.  

---

## ✨ Features 

- Reads from file descriptor

- Handles arbitrarily long lines (not limited by buffer size)

- Manages multiple file descriptors at the same time (bonus)

- Uses static variables to remember the "leftover" data

- Returns lines including the newline character for clarity

---

## ✨ How it Works

- Read from the file in chunks (BUFFER_SIZE)

- Store what’s left if the line isn’t finished yet

- Return one full line per call

- Keep reading until EOF

---

## ✨ Bonus Part

- Support for multiple file descriptors at once

- No data mixing — each fd keeps its own buffer

- Works seamlessly with stdin & files in parallel

---

## ✨ Key Learnings

While coding this project, I learned:

- How file descriptors and the read() syscall really work

- Managing dynamic memory and preventing leaks

- Using static variables for persistent state across function calls

- Handling edge cases like empty files, EOF, and newline positioning

---
