#include <stdlib.h>
#include <stdio.h>

struct node
{
    int key;
    struct node *next;
    struct node *prev;
};

struct table
{
    struct node *reference;
    struct node *other;
};

/*
 * Функция создаёт новый узел списка и ставит его в начало, причём если список пуст, то тот элемент и будет началом списка.
 * Параметрами являются указатель на список, "головой" которого должен стать новый элемент и информация для заполнения поля,
 * функция возвращает указатель на новый список.
*/
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
/*
 * Функция создаёт и добавляет новый элемент в конец списка. Для этого в чикле ищем элемент указатель после которого равен NULL.
 * После добавляем этот самый элемент. Возвращает  указатель на список.
 */
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

/*
 *  Функция добавляет элемнт перед заданным. srch- элемент списка, после которого нужно добавить новый элемент,
 *  х- значение нового узла. Создаём новый узел и заполняем поля, после выполняем поиск в цикле пока не находим
 *  нужный нам элемент и добавляем его перед ним. Функция возвращает указатель на начало нового списка.
 */
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
 * Функция печати списка.
 */
void printList(struct node *list)
{
    while (list)
    {
        printf("%d ", list->key);
        list = list->next;
    }
    printf("\n");
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

/*
 * Функция делит список на два. В одном уникальные, а вдругом прочие элементы с сохранением порядка. Для неё я создал
 * новую структуру table с полями: reference и other. После свёл задачу к решённой использую addtoTail и deleteHead.
 */
struct table separate(struct node *head)
{
    struct table separated;
    separated.reference=NULL;
    separated.other = NULL;
    int space = 0 ;
    struct node *ptr = head;
    while (ptr)
    {
        int condition = 0;
        space = ptr->key;
        for(struct node *copy = separated.reference; copy!=NULL; copy = copy->next) // Поиск элемента среди "особенных"
        {
            if(space == copy->key)
            {
                condition = 1;                                                      // Если такой элемент уже был
            }                                                                       // То изменяем значение condition
        }
        if(condition)
        {
            separated.other = addtoTail(separated.other, space);
        } else
        {
            separated.reference = addtoTail(separated.reference, space);
        }
        ptr = deleteHead(ptr); 
    }
    return separated;
}


int main()
{
    struct node *head = NULL;
    head = addtoTail(head, 2);
    head = addtoTail(head, 0);
    head = addtoTail(head, 5);
    head = addtoTail(head, 6);
    head = addtoTail(head, 3);
    head = addtoTail(head, 2);
    head = addtoTail(head, 2);
    head = addtoTail(head, 4);
    head = addtoTail(head, 5);
    head = addtoTail(head, 6);
    head = addtoTail(head, 0);
    head = addtoTail(head, 0);
    printf("List: ");
    struct node *ptr = head;
    printList(ptr);

    struct table separated = separate(ptr);
    printf("Reference:");
    printList(separated.reference);
    printf("Other:");
    printList(separated.other);



}
