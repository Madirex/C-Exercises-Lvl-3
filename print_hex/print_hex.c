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

void    print_decimal_to_hex(int num)
{
    char *hex_digits = "0123456789abcdef";
    if (num / 16 > 0)
        print_decimal_to_hex(num / 16);
    int n = num % 16;
    write(1, &hex_digits[n], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_decimal_to_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return (0);
}