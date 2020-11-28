/*
在一个二维数组中，每一行按从左到右递增，每一列按从上到下递增。
完成一个函数，输入一个二维数组和一个数字，判断数组中是否有该数字
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//for the question
bool findIn2DArray(int *matrix, int rows, int columns, int number)
{
    bool found = false;
    if(matrix == NULL)
    {
        perror("error:pointer in null\n");
        return false;
    }
    if(rows < 0 || columns < 0)
    {
        perror("error:invalid row number or colunm number\n");
        return false;
    }

    int row = 0, col = columns-1;
    while(row < rows && col >= 0)
    {
        if (number == matrix[row * columns + col])
        {
            //find the number
            found = true;
            break;
        }
        else if (number > matrix[row * columns + col])
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return found;
}

//for test
int main()
{
    int array[4][4] = {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15
    };

    int *arrayp = (int *)malloc(sizeof(int) * 16);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            arrayp[i * 4 + j] = array[i][j];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ",arrayp[i * 4 + j] );
        }
        printf("\n");
    }

    bool ret = findIn2DArray(arrayp, 4, 4, 6);
    printf("%s\n", ret?"yes":"no");

    ret = findIn2DArray(arrayp, 4, 4, -1);
    printf("%s\n", ret?"yes":"no");

    ret = findIn2DArray(arrayp, 4, 4, 33);
    printf("%s\n", ret?"yes":"no");

    free(arrayp);

    return 0;
}