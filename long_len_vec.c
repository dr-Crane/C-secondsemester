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
    int current = 0;
    unsigned char *arr = give_memory(string_len);
    for(int i=0; i<(((string_len-1)/8)+1); i++)
    {
        unsigned char mask = 1;
        for(int j=0; (j<8)&&(current<string_len); j++)
        {
            if(str[current]!='0')
            {
                arr[i] = arr[i]|mask;
            }
            mask = mask<<1;
            current++;
        }
    }
    return arr;
}

void showvec(unsigned char *arr, int len_of_string)
{
    int arr_len = strlen(arr);
    int current =0;
    for(int i=0; i<arr_len; i++)
    {
        unsigned char mask = 1;
        for(int j=0; j<8&&(current<len_of_string); j++)
        {
            if(arr[i] == (arr[i]|mask)) printf("1");
            else printf("0");
            current++;
            mask = mask<<1;
        }

    }
}

int main()
{
    char arr[] = "1010010100010100101010100101011010010100101";

    unsigned char *vec = fill_vec_by_arr(arr);
    showvec(vec, strlen(arr));

    return 0;
}
