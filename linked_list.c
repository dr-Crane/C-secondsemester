#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    struct node *prev;
    int key;
};
/*
 * Функция создаёт новый узел списка и ставит его в начало, причём если список пуст, то тот элемент и будет началом списка.
 * Параметрами являются указатель на список, "головой" которого должен стать новый элемент и информация для заполнения поля,
 * функция возвращает указатель на новый список.
*/
struct node *addtohead(struct node *list, int num)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=num;
    if(list==NULL) list = ptr;
    else
    {
        ptr->next=list;
        list->prev=ptr;
        list = ptr;
    }
    return list;
}
/*
 * Функция печати списка.
 */
void Printlist(struct node *list)
{
    if(list==NULL) return;
    struct node *ptr=NULL;
    ptr=list;
    printf("List:    ");
    while (ptr)
    {
        printf("%d ", ptr->key);
        ptr=ptr->next;
    }
}
/*
 * Функция печати списка с конца.
 */
void revPrntLst(struct node *list)
{
    if(list==NULL) return;
    struct node *ptr = list;
    int k = 0;
    printf("Rev list:");
    while (ptr)
    {
        if(ptr->next==NULL) break;
        ptr = ptr->next;
        k++;
    }
    while (k>=0)
    {
        printf("%d ", ptr->key);
        ptr = ptr->prev;
        k--;
    }
}
/*
 * Функция добавляет узел в конец списка.
 */
struct node *addtotail(struct node *list, int num)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *head = list;
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=num;
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
/*
 * Добавление узла перед заданным. Поиск ведём через параметр srch.
 */
struct node *addbefore(struct node *list, int num, int srch)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *head = list;
    if(ptr==NULL) return NULL;
    ptr->next=NULL;
    ptr->prev=NULL;
    ptr->key=num;
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

int main()
{
    struct node *head = NULL;

    // tests for addtohead()
    for(int i=0; i<8; i++)
    {
        head = addtohead(head, i);
    }
    Printlist(head);
    printf("\n");
    revPrntLst(head);
    printf("\n");

    //tests for addtotail()
//    for(int i=0; i<5; i++)
//    {
//        head = addtotail(head, i);
//    }
//    Printlist(head);
//    printf("\n");
//    revPrntLst(head);
//    printf("\n");

    // tests for addbefore()
//    for(int i=0; i<5; i++)
//    {
//        head = addtotail(head, i);
//    }
//    Printlist(head);
//    printf("\n");
//    revPrntLst(head);
//    printf("\n");
//    head = addbefore(head, 5, 4);
//    Printlist(head);
//    printf("\n");
//    revPrntLst(head);
//    printf("\n");
//    head = addbefore(head, 9, 0);
//    Printlist(head);
//    printf("\n");
//    revPrntLst(head);
//    printf("\n");
//    struct node *backup = head;
//    head = addbefore(head, 9, 10);
//    if(head==NULL) printf("NULL");
//    else
//    {
//        Printlist(head);
//        printf("\n");
//        revPrntLst(head);
//    }
//    printf("\n");

    return 0;
}
