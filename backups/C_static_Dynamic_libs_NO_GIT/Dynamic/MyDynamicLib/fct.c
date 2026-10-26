
// An example of functions for a dynamic library

#include <string.h>
#include <stdio.h>

// Open file 'filename'. Return file descriptor. Return name length by arg
FILE *FileOpen(char *filename, int *name_len)
{
    FILE *fd = fopen(filename, "rt");
    if (fd == NULL) { printf("Bad open '%s'
", filename); return(NULL); }
    *name_len = strlen(filename);
    return(fd);
}

// Give size of file specified by fd (file descriptor)
int FileSize(FILE *fd)
{
    fseek(fd, 0, SEEK_END); // Position file pointer at end of file
    return( ftell(fd) );    // return position in file (last char)
}
