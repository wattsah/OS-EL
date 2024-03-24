# OS SYSTEM MODULES
This repository consists of some of the important operating system. They are:
1. Kernel (performs Arithmetic and String Operations)
2. File Manager (Performs various file operations such as Create, Display, Modify and Delete)
3. Memory Manger (Stimulates the memory allocation of processes using first fit best fit and worst fit)
## Kernel
Consists of 6 files. They are:
- boot.s
- grub.cfg
- linker.ld
- kernel.c
- kernel.h
- run.sh
To run this folder, open the terminal in folder and use the following command:
```
{
  sh run.sh
}
```
(Make sure that   GRUB, QEMU, Xorriso and other required tools are installed in ubuntu).
## File Manager
Use the following Commands for executing File Management.c file:
```
{
 gcc File Management.c
./a.out
}
```
## Memory Manager
Use the following Commands for executing Memory Management.c file:
```
{
 gcc Memory Management.c
./a.out
}
```

