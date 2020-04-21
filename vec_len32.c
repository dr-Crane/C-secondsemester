#include <stdio.h>

unsigned long cnvrt_txt_vec(FILE *input){
    unsigned long mask = 1;
    unsigned long vec = 0;
    mask = mask << 31;
    char n;
    while(0==feof(input))
    {
        int t = fscanf(input,"%c",&n);
        if (t == EOF) break;
        if(n!='0') vec = vec ^ mask;
        mask = mask>>1;
    }
    return vec;
}

void cnvrt_vec_txt(unsigned long num, FILE *ptr_txt){
    unsigned long mask = 1;
    mask = mask << 31;
    for(int i=0; i<31; i++){
        if((mask|num)==num) fprintf(ptr_txt, "%c", '1');
        else fprintf(ptr_txt, "%c", '0');
        mask = mask>>1;
    }
    fclose(ptr_txt);
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

void PrintVec(unsigned long vec){
    unsigned long mask = 1;
    mask = mask<<31;
    for(int i =0; i<32; i++){
        if((vec|mask)==vec) printf("1");
        else printf("0");
        mask = mask >> 1;
    }
    printf("\n");
}

int main() {

    FILE *text = fopen("input.txt", "r");
    if(text==NULL) return -1;

    unsigned long vec = cnvrt_txt_vec(text);
    PrintVec(vec);

    FILE *ptr_out = fopen("output.txt", "w");
    unsigned long num;
    printf("Enter a num:");
    scanf("%lu", &num);
    if(num>2147483648) return -1;
    cnvrt_vec_txt(num, ptr_out);
    FILE *ptr_r = fopen("output.txt", "r");
    printFile(ptr_r);

    return 0;
}
