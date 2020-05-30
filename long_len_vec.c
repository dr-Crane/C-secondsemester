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
 * Заполняем массив (вектор) нужным нам образом. В каждой ячейки отсчёт ведём справа налево. Во втором цикле составное условие,
 * поэтому цикл выполняется либо до тех пор пока j<8 или пока не закончится строка.
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


/*
 * Конвертируем вектор (массив) в строку . Алгоритм обработки тот же самый, что был показан выше. Рассматриваем
 * бинарную составляющую каждой ячейки и в заисимости от состояния бита записываем всё в массив.
 */
char *vec_to_arr(unsigned char *arr, int len_of_string)
{
    char *string = (char*) malloc(len_of_string+1);
    if(!string) return NULL;
    int current=0;
    string[len_of_string] = '\0';
    for(int i=0; i<strlen(arr); i++)
    {
        unsigned char mask = 1;
        for(int j=0; j<8&&(current<len_of_string); j++)
        {
            if(arr[i]==(arr[i]|mask)) string[current]='1';
            else string[current]='0';
            current++;
            mask = mask<<1;
        }
    }
    return string;
}



int main()
{
    char arr[] = "1010010100010100101010100101011010010100101";

    unsigned char *vec = fill_vec_by_arr(arr);

    char *string = vec_to_arr(vec, strlen(arr));

    for(int i=0; i<strlen(arr); i++)
        printf("%c", string[i]);

    return 0;
}
