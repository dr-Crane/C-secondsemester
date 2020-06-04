#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Функция конвертирует строку в булев вектор. Запись ведём справа налево.
 */
unsigned char *str_to_vec(char *str)
{
    if(!str) return NULL;
    unsigned int len_str = strlen(str);
    int current = 0;
    unsigned int cells = ((len_str-1)/8)+1;
    unsigned char *arr = (unsigned char*)malloc(sizeof(unsigned char)*cells);
    if(!arr) return NULL;
    for(int i=0; i<cells; i++)
    {
        arr[i]=0;
    }
    for(int i=0; i<cells; i++)
    {
        unsigned char mask = 1;
        for(int j=0; j<8&&(current<len_str); j++) // Составное условие, current<len_str на случай елси len_str%8!=0
        {
            if(str[current]!='0') arr[i] = arr[i]|mask;
            mask = mask<<1;
            current++;
        }
    }
    return arr;
}

/*
 * Функция конвертация вектора в строку. В параметры передаём сам вектор и его длину.
 */
char *vec_to_str(unsigned char *vec, int len_vec)
{
    if(!vec||len_vec==0) return NULL;
    int current = 0;
    char *arr = (char*) malloc(len_vec+1);
    if(!arr) return NULL;
    arr[len_vec] = '\0';
    for(int i=0; i<((len_vec-1)/8)+1; i++)
    {
        unsigned char mask =1;
        for(int j=0; j<8&&(current<len_vec); j++)
        {
            if(vec[i]==(vec[i]|mask)) arr[current]='1'; // Используем маску и в зависимости о трезультата заполняем
            else arr[current] = '0';                    // arr. Алгоритм тот же, что использовался в str_to_vec()
            mask = mask<<1;
            current++;
        }
    }
    return arr;
}

void show_vec(unsigned char *vec, int len_vec)
{
    if(!vec||len_vec==0) return;
    char *arr = vec_to_str(vec, len_vec);
    for(int i=0; i<45; i++) printf("%c", arr[i]);
    printf("\n");
}

/*
 * Функция инвертирует вектор. Сначала инвертируем все заполненные ячейки (cells-1), а после последнюю
 * используя свойство vec[i]^1=~vec[i].
 */
unsigned char *invert_vec(unsigned char *vec, int len_vec)
{
    if(!vec||len_vec==0) return NULL;
    int cells = ((len_vec-1)/8)+1;
    for(int i=0; i<cells-1; i++)
    {
        vec[i] = ~vec[i];
    }
    unsigned char mask = 1;
    for(int i=0; i<8; i++)
    {
        vec[cells-1] = vec[cells-1]^mask;
        mask = mask<<1;
    }
    return vec;
}

/*
 * Функция выполняет логическое сложение.
 */
unsigned char *logic_summ(unsigned char *vec_1, unsigned char *vec_2, int len_1, int len_2)
{
    if(!vec_2||!vec_1) return NULL;
    int cells_1 = ((len_1-1)/8)+1;
    int cells_2 = ((len_2-1)/8)+1;
    int max=0, min=0, current=0;
    if(cells_1>cells_2)
    {
         max = cells_1;
         min = cells_2;
    } else
    {
         max = cells_2;
         min = cells_1;
    }
    unsigned char *arr = (unsigned char *) malloc(sizeof(unsigned char)*max);
    for(int i=0; i<max; i++)
    {
        arr[i] = 0;
    }
    if(!arr) return NULL;
    for(int i=0; i<min; i++) // Складываю до тех пор пока не закончатся ячейки у меньшего вектора
    {
        arr[i] = vec_1[i]|vec_2[i];
        current++;
    }
    if(min == max) return arr;
    if(cells_1>cells_2)
    {
        for(;current<max; current++)
        {
            arr[current] = vec_1[current];
        }
    } else
    {
        for(;current<max; current++)
        {
            arr[current] = vec_2[current];
        }
    }
    return arr;
}

int main()
{               // Тестовый пример, длина строки 45
    char str_1[] = "111111111111111111111111111111111111111111111";
    char str_2[] = "000000000000000000000000000000000000000000000";

    //Пример использования str_to_vec()
    unsigned char *vec_1 = str_to_vec(str_1);
    unsigned char *vec_2 = str_to_vec(str_2);
    printf("Vector_1:");
    show_vec(vec_1, 45);
    printf("Vector_2:");
    show_vec(vec_2, 45);

    //Пример для invert_vec()
//    printf("Inverted:");
//    unsigned char *inverted = invert_vec(vec, 45);
//    show_vec(inverted, 45);

    //Пример для logic_summ()
//    printf("Log summ:");
//    unsigned char *l_summ = logic_summ(vec_1, vec_2, 45, 45);
//    show_vec(l_summ, 45);

}
