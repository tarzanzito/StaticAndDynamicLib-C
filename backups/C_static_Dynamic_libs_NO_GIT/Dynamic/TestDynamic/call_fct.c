// Example calling functions of fct.c. (fct.h not created for compactness)
# include <stdio.h>

extern FILE *FileOpen(char *filename, int *name_len);
extern int   FileSize(FILE *fd);

int main(int argc, char *argv[])
{
    char *filename = "file.txt";
    int  name_len = 0;

    // We show that void *fd (instead of FILE *) compiles and works
    // We'll use this trick in Python (FILE not needed and too long to create)
    void *fd = FileOpen(filename, &name_len);
    printf("File '%s': name length = %d", filename, name_len);

    int  size = FileSize(fd);
	
    printf("File size = %d", size);
}