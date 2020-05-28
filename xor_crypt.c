#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void CryptXOR(char *input_file, char *key, char *out_file)
{
    FILE *first_file = fopen(input_file, "r");
    FILE *second_file = fopen(out_file, "w");
    if(second_file&&first_file==NULL) return;

    char n;

    while(0==feof(first_file))
    {
        int k = fscanf(first_file,"%c",&n);
        if (k == EOF) break;
        printf("%c", n);
        for(int i=0; i<strlen(key); i++)
        {
            n = n ^ key[i];
        }
        fprintf(second_file, "%c", n );
    }
    printf("\n");
    fclose(second_file);
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
    char key[] = "12ad32";

// Шифрование
    CryptXOR("inpt_test.txt", key, "test_output.txt");
// Дешифровка
    CryptXOR("test_output.txt", key, "scnd_out.txt");
// Проверка на эквивалентность

/*
 * В качестве аргументов передаём адреса файлов. Т.к. в моём примере файлы расположены там же, где находится исполняемый
 * файл мне достаточно указать их имена. Для того, чтобы проверить случай, когда один из файлов не существует, достаточно
 * указать не существующее имя файла.
 */

//    int for_c = CompareFILES("input.txt", "output.txt");
//    if(for_c==-1) printf("There are no file");
//    if(for_c==1) printf("They are equal");
//    if(for_c==0) printf("They are not equal");


    return 0;
}
