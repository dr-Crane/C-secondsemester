#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Выделяю память и зануляю все разряды.
 * К примеру:
 * Необходимо 100 разрядов. (99/8)+1 = 13 (берём целочисленно),
 * поэтому будет выделено 13 ячеек (элементов массива где каждая имеет 8 бит).
 */
unsigned char *give_memory(int num)
{
    unsigned char *arr = (unsigned char*) malloc(sizeof(unsigned char)*(((num-1)/8)+1));
    if(!arr) return NULL;
    arr[(((num-1)/8)+1)] = '\0';
    for(int i=0; i<(((num-1)/8)+1); i++)
    {
        arr[i] = 0;
    }
    return arr;
}
/*
 * Заполняем массив нужным нам образом. В каждой ячейки отсчёт ведём справа налево.
 */
unsigned char *fill_vec_by_arr(char *str)
{
    int string_len = strlen(str);
    unsigned char *arr = give_memory(string_len);
    if(!arr) return NULL;
    int current = 0;
    for(int i=0;(string_len-i-1)>=0; i++)
    {
        unsigned char mask = 1;
        for (int j=0; (j<8)&&(current<string_len); j++)
        {
            if(str[string_len-i-1]!='0')
            {
                arr[(((string_len-1)/8)+1)-1-i] = arr[(((string_len-1)/8)+1)-i-1]|mask;
            }
            mask = mask<<1;
            current++;
        }
    }
    return arr;
}

//void showvec(unsigned char *arr)
//{
//    int arr_len = strlen(arr);
//    for(int i=0; i<arr_len; i++)
//    {
//        for(int j=0; j)
//    }
//}

int main()
{
    char arr[] = "111111111111111111111111111111111111";

    return 0;
}
