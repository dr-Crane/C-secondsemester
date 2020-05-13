#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Функция записи строки в файл. В параметрах передаём адрес файла для записи (если файл не существует то создаёт файл)
 * и строку для записи.
 */
int WriteIntoFile(char *file, char *arr)
{
    FILE *output = fopen(file, "w");
    char n;
    for(int i =0 ; i<strlen(arr); i++)
    {
        n = arr[i];
        fprintf(output, "%c", n );
    }
    fclose(output);
    return 1;
}

/*
 * Функция для шифрования текста. Возвращает указатель на массив (шифротекст). В качестве параметров передаются
 * два массива типа char. В первом содержится строка, которую нужно зашифровать, во втором ключ. Шифрование производитя
 * по следующей схеме:
 * 1) Берём очередной элемент из строки
 * 2) Производим операцию XOR с каждым элементом из key
 * 3) Записываем в новый массив
 * 4) Если не достигли конца строки - переходим к пункту (1)
 * В случае если строка (или ключ) пустая (длина слова или ключа равны 0) возвращает NULL.
 */
char *CryptXOR(char *str, char *key)
{
    char elem;
    if(strlen(str)==0) return NULL;
    if(strlen(key)==0) return NULL;
    char *arr = (char*)malloc(sizeof(char)*strlen(str)+1);
    if(arr==NULL) return NULL;
    arr[strlen(str)] = '\0';
    for(int i=0; i<strlen(str); i++)
    {
        elem = str[i];
        for(int j =0; j<strlen(key); j++)
        {
            elem = elem^key[j];
        }
        arr[i] = elem;
    }
    return arr;
}

/*
 * Сравнивает два файла типа .txt на эквивалентность. В случае если оди (или оба) файла не существуют, то возвращает -1.
 * В случае если они равны 1 ,и 0 если они не равны. В качестве параметров передаю указатели на рассматриваемые файлы.
 */
int CompareFILES(char *File1, char *File2){
    FILE *first_file = fopen(File1, "r");
    FILE *second_file = fopen(File2, "r");
    char a,b;
    if ((first_file) && (second_file)) {
        while ((a = fgetc(first_file)) == (b = fgetc(second_file))) {
            if (((a = fgetc(first_file)) != EOF) && ((b = fgetc(second_file)) != EOF))
                return 1;
        }
        return 0;
    }
    else return -1;
}

int main()
{
    char key[] = "jfalsdkjdafdf";
    char string[] ="Hello world! It's me, again.";

// Процесс шифрования текста.
    char *result = CryptXOR(string, key);
    printf("Chyphertext: ");
    for(int i=0; i<strlen(result); i++) printf("%c", result[i]);

    printf("\n");

// Дешифровка шифротекста.
    result = CryptXOR(result, key);
    printf("Deshipherment: ");
    for(int i=0; i<strlen(result); i++) printf("%c", result[i]);

    printf("\n");

/*
 * Пример использования функции CompareFILES. Функция возвращает -1 в случае отсутсвия одного или обоих файлов, 1 если
 * информация в файлах одна и та же и 0 в случае если информация отличается. В качестве аргументов передаём адреса файлов.
 * Т.к. в моём примере файлы расположены там же, где находится исполняемый файл мне достаточно указать их имена.
 */
    int for_c = CompareFILES("input.txt", "output.txt");
    if(for_c==-1) printf("There are no file");
    if(for_c==1) printf("They are equal");
    if(for_c==0) printf("They are not equal");


    return 0;
}
