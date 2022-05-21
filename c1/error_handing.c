/*
    learn to using error.h
    errno

    Attemp to open an not exist file and output the errno and it's error-description.
*/

#include <stdio.h>
// #include <errno.h> // It's thread safety.

// int main(int args, char **argv){}
int main()
{
    FILE *fp = fopen("error_handing.cc", "r");
    // FILE *fp = fopen("error_handing.c", "r");
    if (fp == NULL){
        perror("fopen open file failed"); // see also strerror and strerror_s definit in <string.h>
        return 1;
    } else {
        printf("%s\n", "open file success!");
        fclose(fp);
    }
    return 0;
}
