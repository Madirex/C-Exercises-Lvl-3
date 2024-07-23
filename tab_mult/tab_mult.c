#include <unistd.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int multipler = 1;
    int num = 0;

    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            multipler = -1;
        i++;
    }
    while(str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * multipler);
}

void ft_putnbr(int n)
{
    if (n / 10 > 0)
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

void print_str(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int n = 1;
    if (argc != 2)
        write(1, "\n", 1);
    else
    {
        while(n < 10)
        {
            ft_putnbr(n);
            write(1, " x ", 3);
            print_str(argv[1]);
            write(1, " = ", 3);
            ft_putnbr(n * ft_atoi(argv[1]));
            write(1, "\n", 1);
            n++;
        }
    }
    return (0);
}