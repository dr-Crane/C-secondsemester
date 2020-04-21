#include <stdio.h>
#include <stdbool.h>

bool chek (FILE *first, FILE *second){
    char a,b;
    if ((first) && (second)) {
        while ((a = fgetc(first)) == (b = fgetc(second))) {
            if (((a = fgetc(first)) != EOF) && ((b = fgetc(second)) != EOF))
                return true;
        }
        return false;
    }
}

void crypt(FILE *input, FILE *output, int key ){
    char n;
    while(0==feof(input))
    {
        int k = fscanf(input,"%c",&n);
        if (k == EOF) break;
        n = n ^ key;
        fprintf(output, "%c", n );
    }
    fclose(output);

}



void printFile(FILE *input){
    char n;
    while(0==feof(input))
    {
        int t = fscanf(input,"%c",&n);
        if (t == EOF) break;
        printf("%c",n);
    }
    printf("\n");
}

int main()
{
    int key;
    printf("Enter a key (it must be num):");
    scanf("%d", &key );

    FILE *sent=fopen("input.txt","r");
    FILE *out_w=fopen("output.txt","w");
    FILE *dcrypt_w = fopen("decrypt.txt", "w");

    printFile(sent);
    rewind(sent);

    crypt(sent, out_w, key);
    rewind(sent);

    FILE *out_r=fopen("output.txt","r");
    printFile(out_r);
    rewind(out_r);

    crypt(out_r, dcrypt_w, key);
    FILE *dcrypt_r = fopen("decrypt.txt", "r");
    printFile(dcrypt_r);
    rewind(dcrypt_r);

    int j = chek(dcrypt_r, sent);

    if (j) printf("True");
    else printf("False");

    return 0;
}
