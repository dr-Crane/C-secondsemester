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
    printf("\n");
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
    printf("\n");
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
/*
 * Функция считает количество узлов списка.
*/
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
/*
 *  Функция поиска узла в списке. В парамметрах передаём адрес начала списка, и значение которое необходимо найти.
 *  В случае если значение не было найдено возвращает NULL, иначе возвращает указатель на найденный узел.
 */
struct node *findNode(struct node *list, int x)
{
    while (list)
    {
        if(list->key == x) return list;
        list = list->next;
    }
    return NULL;
}
/*
 * Функция создаёт и устанавливает новый узел в заданную позицию, причём  позиция должна быть числом натуральным.
 * В случае какой либо ошибки, а именно установки в не существующую позицию (если количество элементов меньше
 * запрашиваемой позиции) или любого другого несоответсвтия (к примеру не выделилась память) возвращает NULL, иначе
 * указатель на начало нового списка.
 */
struct node *addPos(struct node *list, int x, int pos)
{
    if(pos<=0) return NULL;
    if(pos == 1)
    {
        struct node *for_1 = addtohead(list, x);
        return for_1;
    }
    struct node *head = list;
    int len = listlen(list);
    if(pos==(len+1))
    {
        struct node *for_last = addtotail(list, x);
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
                ptr->next = list;
                ptr->prev = list->prev;
                list->prev = ptr;
                ptr->prev->next = ptr;

                list = head;
                return head;
            }
            count++;
            list = list->next;
        }
    }
    return NULL;
}
/*
 * Удаляет все элементы списка и возвращает NUll.
 */
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
/*
 * Добавляет новый элемент после искомого параметра. В случае если такого элемегта нет, возвращает NULL.
 * Поиск ведём в цикле. Возвращает указатель на начало нового списка.
 */
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
/*
 * Удаляет "голову" списка, и возвращает указатель на начало нового.
 */
struct node *deleteHead(struct node *list)
{
    struct node *head = list;
    list = list->next;
    free(head);
    head = NULL;
    return list;
}
/*
 * Удаляет "хвост" и возвращает указатель на начало нового списка.
 */
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
/*
 * Удаляет узел после элемента заданного в параметре, в случае неудачи (элемент не был найден) возвращает NULL. Иначе
 * возвращает указатель на новый список.
 */
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
            struct node *space_1 = list->next->next;
            list->next = space_1;
            space_1->prev = list;
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
/*
 * Удаляет узел перед заданным параметром.
 */
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
/*
 * Удаляет элемент из заданной позиции. В случае отсутсвия позиции возвращает NULL, иначе указатель на новый список.
 */
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
// Функция делит список на два. В первом перечислены уникальные эленменты, во втором оствльные.
// Возвращает список уникальных элементов. 
struct node *separate(struct node* list, struct node** other)
{
    struct node* space = NULL;
    struct node* unique = list;
    list = list->next;
    unique->next = NULL;
    struct node* ptr = list;
    list = addtohead(list, 0); //  Создаю фиктивную голову, чтобы проще было разделить
    list->next = NULL;
    list->prev = NULL;
    ptr->prev = NULL;
    struct node* u_shift = unique;
    struct node* o_shift = list;
    int num = 0;
    while (ptr)
    {
        space = ptr;
        ptr = ptr->next;
        space->next = NULL;
        space->prev = NULL;
        num = 0;
        for(struct node* i=unique; i!=NULL; i=i->next)
        {
            if((space->key)==(i->key)) num++;
        }
        if(num)
        {
            o_shift->next = space;
            space->prev = o_shift;
            o_shift = o_shift->next;
        }
        else
        {
            u_shift->next = space;
            space->prev = u_shift;
            u_shift = u_shift->next;
        }
    }
    list = deleteHead(list);
    *(other) = list;

    return unique;
}

int main()
{
    struct node *head = NULL;
    head = addtotail(head, 1);
    head = addtotail(head, 2);
    head = addtotail(head, 1);
    head = addtotail(head, 1);
    head = addtotail(head, 2);
    head = addtotail(head, 1);
    head = addtotail(head, 3);
    head = addtotail(head, 3);
    head = addtotail(head, 3);
    // tests for addtohead()
    // for(int i=0; i<8; i++)
    // {
    //     head = addtohead(head, i);
    // }
    // Printlist(head);
    // printf("\n");
    // revPrntLst(head);
    // printf("\n");

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

// example for findnode()
    // struct node* ptr = head;
    // struct node* res = ptr;
    // res = findNode(ptr, 9);
    // if(res==NULL) printf("Theres no this number"\n);
    // else printf("%d\n", res->key);

// example for addPos()
    // struct node* ptr = head;
    // struct node* res = addPos(ptr, 11, 4);
    // if(res== NULL) printf("Something is wrong\n");
    // else
    // {
    //     Printlist(res);
    //     printf("\n");
    //     revPrntLst(res);
    //     printf("\n");
    // }
    // res = addPos(ptr, 11, 0);
    // if(res== NULL) printf("Something is wrong\n");
    // else
    // {
    //     Printlist(res);
    //     printf("\n");
    //     revPrntLst(res);
    //     printf("\n");
    // }

// example for deleteList()
    // struct node* ptr = head;
    // ptr = deleteList(ptr);
    // if(ptr == NULL) printf("List was dissmised\n");

// example for addAfter()
    // struct node* ptr = head;
    // ptr = addAfter(ptr, 11, 4);
    // Printlist(ptr);
    // revPrntLst(ptr);  

// example for deleteHead()  
    // struct node* ptr = head;
    // ptr = deleteHead(ptr);
    // Printlist(ptr);
    // revPrntLst(ptr);

// example for deleteAfter()
    // struct node* ptr = head;
    // ptr = deleteAfter(ptr, 4);
    // Printlist(ptr);
    // revPrntLst(ptr);

// example for deleteBefore()
    // struct node *ptr = head;
    // ptr = deleteBefore(ptr, 4);
    // Printlist(ptr);
    // revPrntLst(ptr);

// example for deletePos()
    // struct node *ptr = head;
    // ptr = deletePos(ptr, 4);
    // Printlist(ptr);
    // revPrntLst(ptr);

// example for separate()
    struct node *unique = head;
    unique = separate(unique, &head);
    Printlist(unique);
    revPrntLst(unique);
    Printlist(head);
    revPrntLst(head);

    return 0;
}
