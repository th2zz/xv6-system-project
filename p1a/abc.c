/*****************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[4096];

    fp = fopen("233.1", "r+");

    
    const size_t got = fread(buffer, 1, sizeof buffer, fp);
    fwrite(buffer, 1, got, stdout);

    return 0;
}


