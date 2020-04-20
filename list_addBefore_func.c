#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point{
    int x;
    int y;
    struct point *next;
};


struct point * addBefore(struct point *list, int x,int y) {
    struct point *PtrIx = (struct point*) malloc(sizeof(struct point));
    if (PtrIx){
        PtrIx->x = x;
        PtrIx->y = y;
        PtrIx->next = NULL;

        PtrIx->next = list->next;
        list->next= PtrIx;

        return PtrIx;
    }
    return NULL;
}


int main(){

    struct point *head = NULL;

    struct point *el_a = (struct point*)malloc(sizeof(struct point));
    el_a->x = 1;
    el_a->y = 2;
    el_a->next = NULL;

    struct point *el_b = (struct point*)malloc(sizeof( struct point));

    el_b->x = 4;
    el_b->y = 5;
    el_b->next = NULL;

    struct point *el_c = (struct point*)malloc(sizeof( struct point));

    el_c->x = 3;
    el_c->y = 6;
    el_c->next = NULL;

    el_a->next  =el_b;
    el_b->next = el_c;

    struct point *ptrIx = NULL;
    int count=0, count_2=0;

    head = el_a;
    ptrIx = head;

    for(struct point *current = ptrIx; current && current->x != 3 && current->y != 6; current = current->next){
        count++;
    }
    for(struct point *current = ptrIx;count_2!=count; current = current->next){
        if(count_2+1==count){
            current = addBefore (current, 2, 0);
            break;
        }
        count_2++;
    }
    printf("\n");
    while (ptrIx) {
        printf("point(%d,%d)  ", ptrIx->x, ptrIx->y);
        ptrIx = ptrIx->next;
    }


}
