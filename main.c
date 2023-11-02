#include "libft.h"
#include <stdio.h>

void    writer(void *s)
{
    int    *cast = (int *)s;
    ft_putnbr_fd(*cast, 1);
    write(1, "\n", 1);
}

void *square(void *content)
{
    int *value = (int *)content;
    int *squared_value = malloc(sizeof(int));
    if (squared_value)
    {
        *squared_value = (*value) * (*value);
    }
    return squared_value;
}

void    specific_case(void *content)
{
    char    *tmp = (char *)content;
    ft_putendl_fd(tmp, 1);
    free(tmp);
}

int    main(void)
{
    t_list    *list;

    list = NULL;
    // Liste olusturma eylemi.
    for (int i = 0; i < 10; i++)
    {
        int    *tmp = malloc(sizeof(int));
        *tmp = i;
        if (i % 2)
            ft_lstadd_back(&list, ft_lstnew(tmp));
        else
            ft_lstadd_front(&list, ft_lstnew(tmp));
    }
    // Liste boyutu ve icerigini gorme eylemi
    printf("size of linked list: %d\n", ft_lstsize(list));
    ft_lstiter(list, writer);

    // Mevcut listenin elemanlarina islem yapip yeni listeye kopyalama eylemi
    t_list    *second = ft_lstmap(list, square, free);
    printf("size of second linked list: %d\n", ft_lstsize(second));
    ft_lstiter(second, writer);

    // listeleri temizleme eylemi
    ft_lstclear(&list, free);
    ft_lstclear(&second, free);

    printf("Case specific test\n");
    t_list    *third = ft_lstnew(ft_strdup("TEST"));
    // ft_lstiter(third, writer);
    //you can replace free with any function that does sth to the content
    //but must free the element after it.
    ft_lstdelone(third, specific_case);
    // ft_lstdelone(third, free);
    return (0);
}

//gcc main.c -L. -lft -o run && ./run