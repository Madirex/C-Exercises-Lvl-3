#include <unistd.h>

char do_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char do_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

void print_str(char *str)
{
    int i = 0;
    char c;

    while(str[i])
    {
        if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')
            c = do_upper(str[i]);
        else
            c = do_lower(str[i]);
        write(1, &c, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 1)
    {
        int i = 1;
        while(i < argc)
        {
            print_str(argv[i]);
            i++;
            if (i < argc)
                write(1, "\n", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}