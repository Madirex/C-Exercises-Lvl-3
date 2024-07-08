#include <unistd.h>

int is_space_or_tab(char c)
{
    return (c == '\t' || c == ' ');
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int new_word = 0;

        while(is_space_or_tab(argv[1][i]))
            i++;

        while(argv[1][i])
        {
            if (is_space_or_tab(argv[1][i]) == 1)
                new_word = 1;
            else
            {
                if (new_word == 1)
                {
                    write(1, "   ", 3);
                    new_word = 0;
                }
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}