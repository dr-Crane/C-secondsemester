#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Выделяю память и зануляю все разряды.
 * К примеру:
 * Необходимо 100 разрядов. (100/8)+1 = 13, поэтому будет выделено 13 ячеек (элементов массива где каждая имеет 8 бит),
 * которые в свою очередь сбрасываются до нуля.
 */
unsigned char *give_memory(int num)
{
    unsigned char *arr = (unsigned char*) malloc(sizeof(unsigned char)*((num/8)+1));
    for(int i=0; i<((num/8)+1); i++)    // Идём по массиву
    {
        for(int j=0; j<8; j++)          // Выполняем действия над ячейкой
        {
            arr[j] = arr[j]^arr[j]; // May be some errors. Try to check it by debugger. Clang says, that it will equall to 0.
        }
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
    for(int i=0; i<string_len; i++)
    {
        unsigned char mask = 1;
        for (int j=0; j<8; j++)
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

void showvec(unsigned char *arr)
{
    for(int i=0; i<strlen(arr); i++)
    {
        unsigned char mask = 1;
        for (int j = 0; j < 8; j++)
        {
            if(arr[i] == (arr[i]|mask)) printf("1");
            else printf("0");
            mask = mask<<1;
        }
    }
}

int main()
{
    char arr[] = "1001001010";
    unsigned char *filled_vec = fill_vec_by_arr(arr);
    showvec(filled_vec);

    return 0;
}
