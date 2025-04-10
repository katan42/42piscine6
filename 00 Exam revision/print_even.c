#include <stdio.h>

void print_even(char *str)
{
    int i = 0;
    while (i <= 7)  // ⚠️ Off-by-one bug — might read junk!
    {
        if (i % 2 == 0)
            putchar(str[i]);
        i++;
    }
}

int main(void)
{
    print_even("for moi");
    return 0;
}
