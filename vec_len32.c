#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Функция вывода булева вектора.
 */
void printVec(unsigned long vec){
    unsigned long mask = 1;
    mask = mask<<31;
    for(int i =0; i<32; i++){
        if((vec|mask)==vec) printf("1");
        else printf("0");
        mask = mask >> 1;
    }
    printf("\n");
}

/*
 * Функция преобразует строку в булев вектор. Если длина строки превышает 32 (или она равна нулю) возвращает 0.
 * В качестве параметра передаётся строка для преобразования.
 * К примеру:
 * string[] = "101fdjf2"; будет преобразован в unsigned long vec = 191; (в бинарной системе "10111111").
 */
unsigned long str_to_vec(char *string)
{
    if(strlen(string)>32) return 0;
    if(strlen(string)==0) return 0;
    unsigned long mask = 1;
    unsigned long vec = 0;
    char n;
    for(int i=0; i<strlen(string); i++)
    {
        vec = vec<<1;
        n = string[i];
        if(n!='0') vec=vec|mask;
    }
    return vec;
}

/*
 * Функция перевода булева вектора в строку. Причём если число больше 2147483648‬ (то-есть 1111.....1111), то функция
 * вернёт NULL. Иначе функция вернёт указатель на массив (начало строки). В параметре передаю вектор.
 * Пример:
 * unsigned long vec = 1234; будет преобразован
 * в строку new_string[] = "00000000000000000000010011010010"; (а это, как раз булева форма 1234).
 */
char *vec_to_str(unsigned long vec)
{
    if(vec>=2147483648) return NULL;
    char *arr = (char*) malloc(33);
    if(arr==NULL) return NULL;
    arr[32]='\0';
    unsigned long mask = 1;
    mask = mask<<31;
    for(int i=0; i<32; i++){
        if((mask|vec)==vec) arr[i]='1';
        else arr[i]='0';
        mask = mask>>1;
    }
    return arr;
}

/*
 * Функция сброса n разрядов начиная с k-го. Отсчёт ведём слева направо. В качестве параметров вектор, номер разряда,
 * с которого необходимо начать сброс и количество разрядов для сброса соответсвенно.
 * Пример работы:
 * unsigned long vec = 191; (бинарно 00000000000000000000000010111111)
 * преобразуется в unsigned long vec = 16207 (бинарно 00000000000000000011111101001111). То-есть начиная с k-го
 * n элементов преобразуются по принципу 0 в 1 и наоборот.
 */
unsigned long throw_of(unsigned long num, unsigned int k, unsigned int n){
    if(k>31||n>31) return 0;
    unsigned long mask = 1;
    mask = mask << k;
    for(int i =0 ; i<n; i++){
        num = num ^ mask;
        mask = mask<<1;
    }
    return num;
}

/*
 * Фуyкция зеркалит левую часть вектора относительно правой.
 * К примеру:
 * 00000000000000000011111101001111 преобразуется в 00000000000000000000000000000000.
 */
unsigned long mirror(unsigned long vec){

    unsigned long mask_l =1, mask_r=1;
    mask_l = mask_l<<31;
    for(int i=0; i<16; i++){
        if((vec|mask_l)==vec) vec = vec|mask_r;
        else  vec = vec & (~mask_r);
        mask_l = mask_l>>1;
        mask_r = mask_r<<1;
    }
    return vec;
}

int main()
{
    char string[] = "101fdjf2";        // Строка, для проверки функции unsigned long str_to_vec()
    unsigned long test_vec = 1234;     // Булев вектор, для проверки функции char *vec_to_str()

    unsigned long vec = str_to_vec(string);
    printVec(vec);

    char *new_string = vec_to_str(test_vec);
    for(int i=0; i<32; i++) printf("%c", new_string[i]);
    printf("\n");

    vec = throw_of(vec, 4, 10);
    printVec(vec);

    vec = mirror(vec);
    printVec(vec);

    return 0;

}
