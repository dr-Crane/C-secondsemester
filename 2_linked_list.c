#include <stdlib.h>
#include <stdio.h>

struct node
{
    int key;
    struct node *next;
    struct node *prev;
};

struct node *addtoHead(struct node *list, int x)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=x;
    if(list==NULL) list = ptr;
    else
    {
        ptr->next=list;
        list->prev=ptr;
        list = ptr;
    }
    return list;

}

struct node *addtoTail(struct node *list, int x)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *head = list;
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=x;
    if(list==NULL)
    {
        list = ptr;
        return list;
    }
    else
    {
        while (1)
        {
            if(list->next==NULL)
            {
                list->next=ptr;
                ptr->prev=list;
                list = head;
                return list;
            }
            list = list->next;
        }
    }
}

struct node *addBefore(struct node *list, int x, int srch)
{

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *head = list;
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=x;
    if(list==NULL)
    {
        list = ptr;
        return list;
    }
    else
    {
        while(list)
        {
            if(list->key==srch)
            {
                if(list->prev==NULL)
                {
                    ptr->next = list;
                    list->prev = ptr;
                    head = ptr;
                    return head;
                }
                ptr->next= list;
                ptr->prev= list->prev;
                ptr->prev->next=ptr;
                list->prev= ptr;
                list = head;
                return list;
            }
            list = list->next;
        }
        return NULL;
    }
}

int listlen(struct node *list)
{
    int count = 0;
    while(list)
    {
        list= list->next;
        count++;
    }
    return count;
}

struct node *findNode(struct node *list, int x)
{
    while (list)
    {
        if(list->key == x) return list;
        list = list->next;
    }
    return NULL;
}

void printList(struct node *list)
{
    while (list)
    {
        printf("%d ", list->key);
        list = list->next;
    }
}

struct node *addPos(struct node *list, int x, int pos)
{
    if(pos<=0) return NULL;
    if(pos == 1)
    {
        struct node *for_1 = addtoHead(list, x);
        return for_1;
    }
    struct node *head = list;
    int len = listlen(list);
    if(pos==(len+1))
    {
        struct node *for_last = addtoTail(list, x);
        return for_last;
    }
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int count = 1;
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=x;
    if(list==NULL)
    {
        list = ptr;
        return list;
    }
    else
    {
        while (list)
        {
            if(count==pos)
            {
                ptr->next =list;
                ptr->prev =list->prev;
                list->prev->next=ptr;
                list = head;
                return head;
            }
            count++;
            list = list->next;
        }
    }
    return NULL;
}

struct node *deleteList(struct node *list)
{
    if(list == NULL) return NULL;
    struct node *head = list;
    struct node *space = head->next;
    while (space)
    {
        free(head);
        head = space;
        space = space->next;
    }
    head = NULL;
    space = NULL;
    return NULL;
}

struct node *addAfter(struct node *list, int x, int srch)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *head = list;
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=x;
    if(list==NULL)
    {
        list = ptr;
        return list;
    }
    else
    {
        while(list)
        {
            if(list->key==srch)
            {
                if(list->next==NULL)
                {
                    list->next = ptr;
                    ptr->prev = list;
                    list = head;
                    return list;
                }
                ptr->next=list->next;
                list->next->prev= ptr;
                list->next=ptr;
                ptr->prev=list;
                list = head;
                return list;
            }
            list = list->next;
        }
    }
}

struct node *deleteHead(struct node *list)
{
    struct node *head = list;
    list = list->next;
    free(head);
    head = NULL;
    return list;
}

struct node *deleteTail(struct node *list)
{
    if(list == NULL) return NULL;
    if(listlen(list)==1)
    {
        list = deleteList(list);
        return list;
    }
    struct node *head = list;
    while (list)
    {
        if(list->next==NULL)
        {
            list->prev->next = NULL;
            free(list);
            list = head;
            return list;
        }
        list = list->next;
    }
    return NULL;
}

struct node *deleteAfter(struct  node *list, int x)
{
    if(list==NULL) return NULL;
    struct node *head = list;
    while (list)
    {
        if(list->key==x)
        {
            if((list->next)==NULL)
            {
                list = head;
                return list;
            }
            if(((list->next)->next)==NULL)
            {
                list = deleteTail(list);
                list = head;
                head = NULL;
                return list;
            }
            struct node *space = list->next;
            list->next = list->next->next;
            list->next->next->prev = list;
            free(space);
            list = head;
            space=NULL;
            head = NULL;
            return list;
        }
        list = list->next;
    }
    return NULL;
}

struct node *deleteBefore(struct  node *list, int x)
{
    if(list==NULL) return NULL;
    struct node *head = list;
    while (list)
    {
        if(list->key==x)
        {
            if((list->prev)==NULL) return list;
            if(((list->prev)->prev)==NULL)
            {
                list = deleteHead(list);
                list = head;
                head = NULL;
                return list;
            }
            struct node *space = list->prev;
            list->prev->prev->next=list;
            list->prev = list->prev->prev;
            free(space);
            space=NULL;
            list = head;
            head = NULL;
            return list;
        }
        list = list->next;
    }
    return NULL;
}

struct node *deletePos(struct node *list, int pos)
{
    if(list==NULL) return NULL;
    if(pos==1)
    {
        list = deleteHead(list);
        return list;
    }
    int len = listlen(list);
    if(len==pos)
    {
        list = deleteTail(list);
        return list;
    }
    struct node *head = list;
    int count = 1;
    while (list)
    {
        if(count==pos)
        {
            list->prev->next=list->next;
            list->next->prev=list->prev;
            free(list);
            list=head;
            head=NULL;
            return list;
        }
        count++;
        list = list->next;
    }
    return NULL;
}

int main()
{
    struct node *head = NULL;
    for(int i=0; i<10; i++)
    {
        head = addtoHead(head, i);
    }
    struct node *ptr = head;
    ptr = deleteBefore(ptr, 12);
    if(ptr==NULL) printf("Null\n");
    printList(ptr);

}
