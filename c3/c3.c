#define _GNU_SOURCE
#include <stdio.h>

int main()
{
    FILE *fp = fopen("a.out", "r"); //To evaluate the standard I/O can read binary file without 'b' in the second parameter.
    if (fp == NULL){
        perror("fopen a.out");
        return 1;
    }

    FILE *fp_out = fopen("tempout.txt", "w");
    if (fp_out == NULL){
        perror("fopen tempout.txt");
        fclose(fp); // should close fp;
        return 1;
    }

    // printf("all file open success!!!\n");

    int ch;
    while ((ch = fgetc(fp)) != EOF){
        fputc(ch, fp_out);
    }

    // fclose(fp);
    // fclose(fp_out);

    fcloseall();// using flcoseall instead. It's only implement in linux operating system.
    return 0;
}
