/*
题目要求：找出数组中重复的数字
* 1.先对数组进行排序，再从中找到重复的数字。
    排序的时间复杂度为O(nlogn)
* 2.利用哈表。遍历数组，每扫描一个数字，都可以用O(1)的时间
    来判断哈希表里是否包含这个数字。时间复杂度为O(n)
* 3.遍历数组，当扫描到下标为i的数字时，首先比较这个数字(m)
    是否与下标(i)相等,如果是则比较下一个数字；如果不是，则
    将其与第m个数字比较，如果它和第m个数字相等，则找到了重复
    数字，算法结束；若不等，将其与第m个数字交换，接下来重复比较
*/

#include <map>
#include <iostream>
#include <stdio.h>
#include "sort.h"
using namespace std;

void sort(int *numarr, int len)
{
    strightInsertionSort(numarr, len);
    //binaryInsertionSort(numarr, len);
    //shellSort(numarr, len);
    //bubbleSort(numarr, len);
    //quickSort(numarr, 0, len);
    //selectSort(numarr, len);
    //heapSort(numarr, len);
    //radixSort(numarr, len, 3);
}

//排序方法
bool sortMethod(int *numarr, int len)
{
    if (numarr == NULL)
    {
        perror("pointer is null\n");
        return false;
    }
    if(len <= 0)
    {
        perror("len must larger than 0\n");
        return false;
    }

    sort(numarr, len);

    for(int i = 1; i < len; i++)
    {
        if(numarr[i] == numarr[i-1])
        {
            return true;
        }
    }
    return false;
}

//如果数字比较连续也可以用数组
bool hashMethod(int *numarr, int len)
{
    if (numarr == NULL)
    {
        perror("pointer is null\n");
        return false;
    }
    if(len <= 0)
    {
        perror("len must larger than 0\n");
        return false;
    }

    map <int, int> num_map;
    for(int i = 0; i < len; i++)
    {
        if(num_map.find(numarr[i]) == num_map.end())
        {
            num_map[numarr[i]] = numarr[i];
        } else {
            //找到重复的数字
            return true;
        }
    }

    return false;
}

//限制条件：数组长度为n，数字范围0--n-1
bool dopolicate(int *numarr, int len)
{
    if (numarr == NULL)
    {
        perror("pointer is null\n");
        return false;
    }
    if(len <= 0)
    {
        perror("len must larger than 0\n");
        return false;
    }

    int i = 0;
    while(i < len)
    {
        if(numarr[i] == i) {
        //数字大小和下标对应
            i++;
        } else {
            int tmp = numarr[i];
            if(tmp = numarr[tmp])
            {
                return true;
            }
            else
            { //将numarr[i] 放到其数字对应的下标内
                numarr[i] = numarr[tmp];
                numarr[tmp] = numarr[i];
            }
            
        }
    }
    return false;
}

int main()
{
    int array[] = {5,2,1,3,5,4,0};
    int i = 0;
    bool ret;

    int len = sizeof(array)/sizeof(int);
    ret = sortMethod(array, len);
    for(i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n%s\n", ret?"yes":"no");

    ret = hashMethod(array, len);
    printf("%s\n", ret?"yes":"no");

    ret = dopolicate(array, len);
    printf("%s\n", ret?"yes":"no");

    return 0;
}