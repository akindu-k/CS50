#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("what's your name? ");
    printf("hello, %s", name);
    printf("\n");
    return 0;
}