#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
    struct point *next;
};

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



int deleteAfter(struct point *list, int a, int b)
{
    if(list==NULL) return -1;
    struct point *ptrIx = list;
    while (ptrIx)
    {
        if(ptrIx->x==a&&ptrIx->y==b)
        {
            struct point *space = ptrIx->next;
            if(space==NULL) return -2;
            struct point *space_2 = ptrIx->next->next;
            if(space_2==NULL)
            {
                ptrIx->next = NULL;
                free(space);
                space= NULL;
                return 0;
            }
            ptrIx->next = space_2;
            free(space);
            space=NULL;
            return 0;
        }
        ptrIx = ptrIx->next;
    }

    return -3;
}

int deleteBefore(struct point *list, int a, int b)
{
    if(list==NULL) return -1;
    struct point *ptrIx = list;
    while (ptrIx)
    {
        if(((ptrIx->next)->next)->x==a&&((ptrIx->next)->next)->y==b)
        {
            struct point *space = ptrIx->next;
            if(space==NULL) return -2;
            struct point *space_2 = ptrIx->next->next;
            ptrIx->next = space_2;
            free(space);
            space=NULL;
            return 0;
        }
        ptrIx = ptrIx->next;
    }

    return -3;
}

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

struct point *addLast(struct point *list, int x,int y)
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
            struct point *space = list;
            while (space)
            {
                if((space->next)==NULL)
                {
                    space->next=PtrIx;
                    return list;
                }
                else space = space->next;
            }
        }
    }
    else return NULL;
}

struct point *addAfter(struct point *list, int n_x,int n_y, int a, int b)
{
    struct point *PtrIx = (struct point*) malloc(sizeof(struct point));
    if (PtrIx)
    {
        PtrIx->x = n_x;
        PtrIx->y = n_y;
        PtrIx->next = NULL;
        if (list == NULL) list = PtrIx;
        else
        {
            struct point *space = list;
            while (space)
            {
                if((space->x==a)&&(space->y==b))
                {
                    PtrIx->next = space->next;
                    space->next = PtrIx;
                    return list;
                }
                else space = space->next;
            }
        }
    }
    else return NULL;
}

struct point *addBefore(struct point *list, int n_x,int n_y, int a, int b)
{
    struct point *PtrIx = (struct point*) malloc(sizeof(struct point));
    if (PtrIx)
    {
        PtrIx->x = n_x;
        PtrIx->y = n_y;
        PtrIx->next = NULL;
        if (list == NULL) list = PtrIx;
        else
        {
            struct point *space = list;
            while (space)
            {
                if(((space->next)->x==a)&&((space->next)->y==b))
                {
                    PtrIx->next = space->next;
                    space->next = PtrIx;
                    return list;
                }
                else space = space->next;
            }
        }
    }
    else return NULL;
}

int main()
{
    struct point *head = NULL;
    for(int i=0; i<10; i++)
    {
        int y=i+1;
        head = addToHead(head, i, y);
    }
    struct point *ptrIx = head;

    deleteBefore(ptrIx, 6, 7);

    while (ptrIx)
    {
        printf("point(%d,%d)  ", ptrIx->x, ptrIx->y);
        ptrIx = ptrIx->next;
    }
    printf("\n");


}
