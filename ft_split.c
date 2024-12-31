#include "push_swap.h"
int ft_count_words(const char *s,char c);
char **ft_split_words(const char *s,char c,char **s1,int num_words);
void ft_putword(char *s1, char const *s, int i, int word_len);
char **free_arry(char **s1,int word);

char	**ft_split(char const *s, char c)
{
    char    **s1;
    unsigned int    num_words;

    if (!s)
        return(0);
    num_words = ft_count_words(s, c);
    s1 = (char **)malloc(sizeof(char *) * (num_words + 1));
    if (!s1)
        return (0);
    s1 = ft_split_words(s, c, s1, num_words);
    return (s1);
}

int ft_count_words(const char *s,char c)
{
    int i;
    int count;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

char **ft_split_words(const char *s,char c,char **s1,int num_words)
{
    int i;
    int word;
    int len_word;

    i = 0;
    word = 0;
    len_word = 0;
    while (word < num_words)
    {
        while (s[i] && s[i] == c)
            i++;
        while (s[i] && s[i] != c)
        {
            i++;
            len_word++;
        }
        s1[word] = (char *)malloc(sizeof(char) * (len_word + 1));
        if (!s1[word])
            return (free_arry(s1, word));
		ft_putword (s1[word], s, i, len_word);
        len_word = 0;
        word++;
    }
    s1[word] = 0;
    return (s1);
}

void ft_putword(char *s1, char const *s, int i, int word_len)
{
    int j;

    j = 0;
    while (word_len > 0)
    {
        s1[j] = s[i - word_len];
        j++;
        word_len--;
    }
    s1[j] = '\0';   
}

char **free_arry(char **s1,int word)
{
    while (word > 0)
    {
        word--;
        free(s1[word]);
    }
    free(s1);
}
