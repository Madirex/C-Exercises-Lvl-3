char    to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    return (c);
}

int get_digit(char c, int base)
{
    c = to_lower(c);

    int num = c - '0';
    if (c >= '0' && c <= '9' && num < base)
        return (num);
    num = c - 'a' + 10;
    if (c >= 'a' && c <= 'f' && num < base)
        return (num);
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    int digit;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    while((digit = get_digit(str[i], str_base)) >= 0)
    {
        res = res * str_base + digit;
        i++;
    }
    return (res * sign);
}