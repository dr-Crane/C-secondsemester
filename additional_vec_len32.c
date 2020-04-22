#include <stdio.h>

unsigned long Changer(unsigned long num, unsigned long k, unsigned long n){
    unsigned long mask = 1;
    mask = mask << k;

    for(int i =0 ; i<n; i++){
        num = num ^ mask;
        mask = mask<<1;
    }
    return num;
}

unsigned long Mirror(unsigned long vec){

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

int main(){

    // Сбросить ровно N - разрядов, начиная с K - ого
    unsigned long num , n, k;
    printf("Enter a num:");
    scanf("%lu", &num);
    PrintVec(num);
    printf("Enter a N:");
    scanf("%lu", &n);
    printf("Enter a K:");
    scanf("%lu", &k);
    num = Changer(num, k, n);
    PrintVec(num);


    printf("\n\n\n");

    //Зеркально отразить левую часть вектора относительно центра.
    //Необходимо брать достаточно большие числа чтобы в левой части вектора были единицы

    unsigned long vec;
    printf("Enter a num:");
    scanf("%lu", &vec);
    if(vec>2147483648) return -1;
    vec = Mirror(vec);
    PrintVec(vec);

}
