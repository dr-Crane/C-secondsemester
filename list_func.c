#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point{
    int x;
    int y;
    struct point *next;
};

// Функция добавляет элемент в начало списка , рабочий НЕ УДАЛЯТЬ!
struct point * addToHead(struct point *list, int x,int y) {
    struct point *PtrIx = (struct point*) malloc(sizeof(struct point));
    if (PtrIx){
        PtrIx->x = x;
        PtrIx->y = y;
        PtrIx->next = NULL;
        if (list == NULL)
            list = PtrIx;
        else {
            PtrIx->next = list;
            list = PtrIx;
        }
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
    head = el_a;
    ptrIx = head;

    while (ptrIx) {
        printf("point(%d,%d)  ", ptrIx->x, ptrIx->y);
        ptrIx = ptrIx->next;
    }

    ptrIx = addToHead(head, 2 , 6);
    printf("\npoint(%d,%d)" , ptrIx->x, ptrIx->y);
}


