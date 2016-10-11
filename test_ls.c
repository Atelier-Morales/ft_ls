//
// Created by Fernan MORALES on 10/8/16.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int countlines(char *filename)
{
    // count the number of lines in the file called filename
    FILE *fp = fopen(filename,"r");
    int ch=0;
    int lines=0;

    if (fp == NULL)
        return 0;
    lines++;
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }
    fclose(fp);
    return lines;
}

int main(void)
{
    printf("\nTests with single option : \n");
    // test single ls
    printf("[TEST] : single ls\n");
    system("ls > test/org.txt");
    system("./ft_ls > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -r in . folder
    printf("[TEST] : ls -r in . folder\n");
    system("ls -r > test/org.txt");
    system("./ft_ls -r > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -a in . folder
    printf("[TEST] : ls -a in . folder\n");
    system("ls -a > test/org.txt");
    system("./ft_ls -a > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    printf("\nTests with multiple options : \n");

    // test ls -ar in . folder
    printf("[TEST] : ls -ar in . folder\n");
    system("ls -ar > test/org.txt");
    system("./ft_ls -ar > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -ra in . folder
    printf("[TEST] : ls -ra in . folder\n");
    system("ls -ra > test/org.txt");
    system("./ft_ls -ra > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -r -a in . folder
    printf("[TEST] : ls -r -a in . folder\n");
    system("ls -r -a > test/org.txt");
    system("./ft_ls -r -a > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -a -r in . folder
    printf("[TEST] : ls -a -r in . folder\n");
    system("ls -a -r > test/org.txt");
    system("./ft_ls -a -r > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test single ls with multiple folders
    printf("[TEST] : single ls with multiple folders\n");
    system("ls test includes srcs libft > test/org.txt");
    system("./ft_ls test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -a with multiple folders
    printf("[TEST] : ls -a with multiple folders\n");
    system("ls -a test includes srcs libft > test/org.txt");
    system("./ft_ls -a test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -r with multiple folders
    printf("[TEST] : ls -r with multiple folders\n");
    system("ls -r test includes srcs libft > test/org.txt");
    system("./ft_ls -r test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -ar with multiple folders
    printf("[TEST] : ls -ar with multiple folders\n");
    system("ls -ar test includes srcs libft > test/org.txt");
    system("./ft_ls -ar test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -ra with multiple folders
    printf("[TEST] : ls -ra with multiple folders\n");
    system("ls -ra test includes srcs libft > test/org.txt");
    system("./ft_ls -ra test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -a -r with multiple folders
    printf("[TEST] : ls -a -r with multiple folders\n");
    system("ls -a -r test includes srcs libft > test/org.txt");
    system("./ft_ls -a -r test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

    // test ls -r -a with multiple folders
    printf("[TEST] : ls -r -a with multiple folders\n");
    system("ls -r -a test includes srcs libft > test/org.txt");
    system("./ft_ls -r -a test includes srcs libft > test/dest.txt");
    system("diff test/org.txt test/dest.txt > test/diff");
    assert(countlines("test/diff") <= 1);

//  printf("LINES: %d\n", countlines("test/diff"));
    printf("all tests passed.\n");
    return (0);
}
