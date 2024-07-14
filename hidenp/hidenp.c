#include <unistd.h>

char str_hidden(char *str1, char *str2)
{
    int i = 0;
    int c = 0;

    while(str2[i])
    {
        if (!str1[c])
            return ('1');
        if (str1[c] == str2[i])
            c++;
        i++;
    }
    if (!str1[c])
        return ('1');
    return ('0');
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char c = str_hidden(argv[1], argv[2]);
        write(1, &c, 1);
    }
    write(1, "\n", 1);
    return (0); 
}