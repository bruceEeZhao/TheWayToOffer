/*
将字符串中的空格替换为 %20
约束：在同一个字符串中操作
最优解：时间复杂度为O(n)
方法：先遍历字符串，然后从后往前进行替换
*/

#include <stdio.h>
#include <stdlib.h>

//length 为字符数组的长度
void replaceBlank(char *str, int length)
{
    if(str == NULL || length <= 0)
    {
        perror("pointer is null or length <= 0");
        return;
    }

    int blankSum = 0;
    int str_len = 0; //字符串实际长度
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ') 
        {
            blankSum ++;
        }
        str_len++;
    }
    
    if(str_len == 0 || blankSum == 0)
    {
        //字符串长度为0 或 空格数为0，不需处理
        return;
    }

    int new_len = str_len + blankSum*2;
    if(new_len >= length)
    {
        perror("str length not enough\n");
        return;
    }

    int j;
    for(i = new_len, j = str_len;j >= 0; j--)
    {
        if(str[j] != ' ')
        {
            str[i--] = str[j];
        } 
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }

}

//for test
int main()
{
    char a[40] = " hello  world ";
    char b[20] = "sdfsfsdfdsf";
    char c[20] = "  ";
    char d[10] = "sfsfsd  d";

    replaceBlank(a, 40);
    replaceBlank(b, 20);
    replaceBlank(c, 20);
    replaceBlank(d, 10);

    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);
    printf("%s\n", d);


    return 0;
}