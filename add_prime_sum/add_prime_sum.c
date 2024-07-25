#include <unistd.h>

void ft_putnbr(int n)
{
    if (n / 10 > 0)
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int	ft_atoi(const char *str)
{
    int i = 0;
    int num = 0;

    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    if (str[i] == '+')
        i++;
    while(str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num);
}

int     is_prime(int num)
{
        int i = 2;
        if (num <= 1)
                return (0);
        if (num == 2)
                return (1);
        if (num % 2 == 0)
                return (0);
        while(i * i <= num)
        {
                if (num % i == 0)
                        return (0);
                i+=2;
        }
        return (1);
}

int     main(int argc, char **argv)
{
        int     num;
        int     q = 0;

        if (argc == 2)
        {
                if (argv[1][0] == '-')
                {
                        write(1, "0\n", 2);
                        return (0);
                }
                num = ft_atoi(argv[1]);

                while (num > 0)
                {
                        if (is_prime(num))
                                q += num; 
                        num--;
                }
                ft_putnbr(q);
        }
        else
                write(1, "0", 1);
        write(1, "\n", 1);
        return (0);
}