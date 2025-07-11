# cli-C-scratch

In this repository, I will be implementing all the command-line tools of the Linux terminal from sratch in C language

## 1) touch_clone.c

the ```touch``` command line tool is a very popular tool that creates a file if it doesn’t exist or updates its modification time if it does.

## To use the clone:

Compile the C file.

```shell
gcc touch_clone.c -o touch_clone
```

Run and test the file using:

```shell
./touch_clone file_name
```

1) The program checks if the file exists using ```access()```.

2) If it exists, it updates the timestamps to the current time with ```utime()```.

3) If it doesn’t, it creates an empty file with ```fopen()``` in "w" mode.
