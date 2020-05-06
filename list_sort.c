#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
    struct point *next;
};

// Добавляет новый элемент в начало списка.
struct point * addToHead(struct point *list, int x,int y)
{
    struct point *PtrIx = (struct point*) malloc(sizeof(struct point));
    if (PtrIx)
    {
        PtrIx->x = x;
        PtrIx->y = y;
        PtrIx->next = NULL;
        if (list == NULL) list = PtrIx;
        else
        {
            PtrIx->next = list;
            list = PtrIx;
        }
        return PtrIx;
    }
    return NULL;
}

// Печать списка.
void PrintList(struct point *ptrIx)
{
    while (ptrIx)
    {
        printf("point(%d,%d)  ", ptrIx->x, ptrIx->y);
        ptrIx = ptrIx->next;
    }
    printf("\n");
}

// Удаляет голову списка и возвращает указатель на начало нового.
struct point *deleteHead(struct point *list)
{
    if(list)
    {
        struct point *ptrIx = list;
        list = list->next;
        free(ptrIx);
        ptrIx = NULL;
        return list;
    }
    else return NULL;

}

struct point *SortList(struct point *list) {
    struct point *new_list = (struct point*)malloc(sizeof(struct point));
    struct point *elem = list;
    list = list->next;
    elem->next = NULL;
    new_list->next = elem;
    while (list)
    {
        elem = list;
        list = list->next;
        elem->next = NULL;
        struct point *ptrIx = new_list;
        // Цикл ищет позицию, после которой необходимо вставить элемент. Сначала выполняем проверку на существование следующего
        // элемента, т.к. таким образом можно обойти ситуацию, когда элемент больше остальных элементов списка,
        // а следовательно должен встать в конец.
        for(;ptrIx->next&&ptrIx->next->x<elem->x; ptrIx = ptrIx->next);
        elem->next = ptrIx->next;
        ptrIx->next = elem;
    }
    PrintList(new_list);
    new_list = deleteHead(new_list);
    return new_list;

}

int main()
{
    struct point *head = NULL;
    head = addToHead(head, 1, 1);
    head = addToHead(head, 2, 1);
    head = addToHead(head, 3, 1);
    head = addToHead(head, 4, 1);
    head = addToHead(head, 5, 1);
    head = addToHead(head, 2, 0);
    PrintList(head);
    head = SortList(head);
    struct point *ptrIx = head;
    PrintList(ptrIx);
    return 0;
}
