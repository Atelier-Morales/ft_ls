//
// Created by Fernan MORALES on 10/8/16.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // test single ls
    printf("[TEST] : single ls");
    system("ls > test/org");
    system("./ft_ls > test/dest");
    return (0);
}
