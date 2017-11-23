/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <earteshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:24:40 by earteshc          #+#    #+#             */
/*   Updated: 2017/11/23 11:44:32 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Part 1  input from file */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFF_SIZE 545

/*=========================MAP CHECKER============================*/
void    var_init(size_t *arr, int flag)
{
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    if (flag == 1)
    {
        arr[3] = 0;
        arr[4] = 1;
    }
}

size_t block_checker(char const *s, ssize_t read)
{
    size_t elem[5];

    var_init(elem, 1);
    while ((*s == '.' || *s == '#' || *s == '\n') && (elem[4] + elem[3] - 1) < read)
    {
        printf("read %zu  cnt %zu\n", read, (elem[4] + elem[3]) );
        if (*s == '.')
            elem[0]++;
        if (*s == '#')
            elem[1]++;
        if (*s == '\n')
            elem[2]++;
        if (*s == '\n' && elem[4] % 5 != 0)
            return (0);
        if ((elem[0] == 12 && elem[1] == 4 && elem[2] == 4))
        {
            if (*s == '\n' && (*(s + 1) == '\n' || *(s + 1) == '\0'))
                elem[3]++;
            else if (*(s + 1) == '\0')
                return (elem[3]);
            var_init(elem, 0);
            s++;
        }
        elem[4]++;
        s++;
    }
    return (0);
}

char *map_reader(char **map, size_t *tetriminos)
{
	int fd;
    char buff[BUFF_SIZE + 1];
    ssize_t read_res;
    char *res;

    if (!(fd = open(*map, O_RDONLY)))
		return (0);
        if((read_res = read(fd, buff, BUFF_SIZE)))
        {
            buff[read_res] = '\0';
            close(fd);
            if((*tetriminos = block_checker(buff, read_res)))
            {
               res = (char *)malloc(sizeof(char) * read_res);
                ft_memcpy(res,buff, (size_t)read_res);
                res[read_res] = '\0';
                return (res);
            }
        }
    return (NULL);
}
/*=========================MAP CHECKER============================*/

/*========================TETRIMINO CHECKER=======================*/
/*char ***block_spliter(char *buff, size_t tetriminos)
{
    char ***res;
    char ***start;

    res = NULL;
    if (!(res = (char ***)malloc(sizeof(char **) * (tetriminos + 1))))
        return (NULL);
    res[tetriminos] = NULL;
    start = res;
    while (*res != NULL)
    {
        if(!(*res = (char **)malloc(sizeof(char *) * 5)))
            return (NULL);
        *res[4] = NULL;
        while (**res != NULL)
        {
            if(!(**res = (char *)malloc(sizeof(char) * 5)))
                return (NULL);
            res[4] = '\0';
            while (***res != '\0')
                *(**res++) = *(buff++);
            buff++;
        }
        buff++;
        res++;
    }
    return (start);
}*/
/*========================TETRIMINO CHECKER=======================*/


int main(int argc, char **argv)
{
    size_t tetrimino;
    /*char ***tetrimino_check =  block_spliter(map_reader((argv + 1), &tetrimino), tetrimino);
*/
    tetrimino = 0;
	if (argc != 2)
		return (0);


    printf("%s", map_reader((argv + 1), &tetrimino));
    printf("Map : %zu\n", tetrimino);

    /*int i = 0;
    int j = 0;
    int k = 0;

    while(*tetrimino_check != NULL)
    {
        while(**tetrimino_check != NULL)
        {
            printf("%s\n", tetrimino_check[i][j]);
            (*tetrimino_check)++;
        }
        tetrimino_check++;
    }
    //printf("%s", tetrimino_check[1][0]);*/
	return (0);
}

/*
 * char ***block_spliter(char *buff, size_t tetriminos)
{
    char ***res;
    size_t i;
    size_t j;
    size_t k;

    res = NULL;
    i = 0;
    j = 0;
    k = 0;
    if (!(res = (char ***)malloc(sizeof(char **) * (tetriminos + 1))))
        return (NULL);
    res[tetriminos] = NULL;
    while (j < tetriminos)
    {
        if(!(res[j] = (char **) malloc(sizeof(char *) * 5)))
            return (NULL);
        res[j][4] = NULL;
        while (i < 4)
        {
            if(!(res[j][i] = (char *)malloc(sizeof(char) * 5)))
                return (NULL);
            res[j][i][4] = '\0';
            while (k < 4)
            {
                res[j][i][k] = *buff;
                k++;
                buff++;
            }
            buff++;
            i++;
            k = 0;
        }
        buff++;
        j++;
        i = 0;
    }
    return (res);
}
 */










