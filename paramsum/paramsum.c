#include <unistd.h>

void print_num(int num)
{
    char c;

    if (num > 9)
        print_num(num / 10);
    c = (num % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    (void)argv;
    print_num(argc - 1);
    write(1, "\n", 1);
    return (0);
}