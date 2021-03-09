#ifndef _SORT_H
#define _SORT_H

#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;


template <class T>
void Swap(T *a, T *b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}
/*
插入排序
- 直接插入排序
*/
template <class T>
void strightInsertionSort(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    int i,j;
    T tmp;
    for(i = 1; i < length; i++)
    {
        if(array[i] < array[i-1])
        {
            int tmp = array[i];
            for(j = i-1; j >= 0; j--)
            {
                array[j+1] = array[j];
                if(tmp >= array[j])
                    break;
            }
            array[j+1] = tmp;
        }
    }
}


/*
插入排序
- 折半插入排序
*/
template <class T>
void binaryInsertionSort(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    int low, high, mid;
    int i, j;
    T tmp;
    for (i = 1; i < length; i++)
    {//将数组从第二个元素开始，插入到已排序队列中
        low = 0, high = i-1;
        tmp = array[i];
        while(low <= high)
        {
            mid = (high+low)/2; 
            if(tmp < array[mid]) {
                high = mid-1;
            } 
            else if(tmp > array[mid]) {
                low = mid+1;
            }
            else {
                low = high = mid;
            }
        }

        for(j = i; j > high; j--)
        {
            array[j] = array[j-1];
        }
        array[high+1] = tmp;
    }

}

/*
插入排序
- 希尔排序
*/
template <class T>
void shellSort(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    int step;
    int i,j;
    for(step = length/2; step >= 1; step = step / 2)
    {
        for(i = 0; i+step < length; i++)
        {
            if (array[i] > array[i + step])
            {
                T tmp = array[i];
                array[i] = array[i + step];
                array[i + step] = tmp;

                for(int k = i; k-step >= 0; k = k-step)
                {
                    if(array[k] < array[k-step])
                    {
                        T tmp = array[k];
                        array[k] = array[k - step];
                        array[k - step] = tmp;
                    }
                }
            }
        }

    }
    
}

/*
交换排序
- 冒泡排序
*/
template <class T>
void bubbleSort(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    int i,j;
    int swapflag = 0;
    for(i = 0; i < length-1; i++)
    {
        swapflag = 0;
        for(j = i+1; j < length; j++)
        {
            if(array[j-1] > array[j])
            {
                Swap(&array[j], &array[j-1]);
                swapflag = 1;
            }
        }
        if(swapflag == 0)
        {
            return;
        }
    }
}

/*
交换排序
- 快速排序
*/
template <class T>
void quickSort(T *array, int low, int high)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }

    if(low >= high)
    {
        return;
    }

    int tlow = low;
    int thigh = high;

    T tmp = array[tlow];
    while(tlow < thigh)
    {
        while(tlow < thigh && array[thigh] >= tmp)
        {
            thigh--;
        }
        array[tlow] = array[thigh];
        while(tlow < thigh && array[tlow] <= tmp)
        {
            tlow++;
        }
        array[thigh] = array[tlow];
    }
    array[tlow] = tmp;
    QuickSort(array, low, tlow-1);
    QuickSort(array, tlow+1, high);

}

/*
选择排序
- 简单选择排序
*/
template <class T>
void selectSort(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    int i,j;
    for(i = 0; i < length - 1; i++)
    {
        T min = array[i];
        for(j = i+1; j < length; j++)
        { //find the min number
            if(array[j] < min)
            {   
                T tmp = min;
                min = array[j];
                array[j] = tmp;
            }
        }
        array[i] = min;
    }
}

/*
选择排序
- 堆排序
*/
template <class T>
void adjustDown(T *array, int k, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    int i;
    T tmp = array[k];
    for(i = (k+1)*2-1; i < length; i++)
    {
        if(i+1 < length && array[i] < array[i+1])
        {//选择节点较大的节点
            i++;
        }
        if(tmp >= array[i])  break;
        else {
            array[k] = array[i];
            k=i;
        }
    }
    array[k] = tmp;
}

//数组从下标从0开始，堆排序有点恶心
template <class T>
void buildMaxHeap(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    for(int i = (length-1)/2; i >= 0; i--)
    {   
        adjustDown(array, i, length);
    }
}

template <class T>
void heapSort(T *array, int length)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }

    buildMaxHeap(array, length);

    for(int i = length-1; i>1; i--)
    {
        Swap(&array[i], &array[0]);
        adjustDown(array, 0, i-1);
    }
}

/*
归并排序
todo
*/

//todo

/*
基数排序
第三个参数表示数值最大位数
*/
template <class T>
void radixSort(T *array, int length, int range)
{
    if(array == NULL)
    {
        perror("pointer is null\n");
        return;
    }
    if(length <= 0)
    {
        perror("length must larger than 0\n");
        return;
    }
    if(range <= 0)
    {
        perror("range must larger than 0\n");
        return;
    }

    queue<T> q[10];
    int i,j,k;
    int divnum = 1;

    for(i = 1; i <= range; i++)
    {
        for(j = 0; j < length; j++)
        {//按照余数将数字放入队列中
            int radix = (array[j] / divnum)% 10; 
            q[radix].push(array[j]);
        }

        int h = 0;
        for(k = 0; k < 10; k++)
        {
            while(! q[k].empty())
            {
                T tmp = q[k].front();
                q[k].pop();
                array[h] = tmp;
                h++;
            }
        }
        divnum *= 10;
    }
}

#endif