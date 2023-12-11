#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LNode{                   //声明单链表结点类型
    int data;                           //每个结点放一个int类型的data
    struct LNode *next;                 //指针指向下一个结点
}LNode,*LinkedList;

bool InitList1 (LinkedList L){          //不带头结点的单链表的初始化
    return NULL;
}

bool Empty1(LinkedList L){               //判断不带头结点的单链表是否为空
    return (L == NULL);
}

bool InitList2() {                                                  //带头结点的单链表的初始化
    LinkedList L = (LNode *) malloc(sizeof(LNode));           //用malloc函数申请空间来存储一个头结点
                                                                    //将malloc返回的地址赋值给L➡️头指针L指向这个结点
    if (L == NULL)                                                  //内存不足➡️分配失败
        return false;
    L->next = NULL;                                     //头结点之后暂时还没有结点
    return true;
}

bool Empty2(LinkedList L){                          //判断带头结点的单链表是否为空
    if (L->next == NULL)
        return true;
    else
        return false;
}

int GetElem(LinkedList L,int i){     //声明一个函数来获取链表中第i个元素
    int j = 1;
    if (L == NULL)
        return -1;
    LNode *p = L ->next;
    if (i ==0)
        return -1;
    if ( i<1 )
        return -1;
    while (p != NULL && j<i){
        p = p->next;
        j++;
    }
    if (p == NULL)
        return -1;
    else
    return p ->data;
}

bool ListInsert1(LinkedList L,int i,int e){          //在第i个位置插入元素e(带头结点)
    if (i<1)
        return false;
    LNode *p;                                       //指针p指向当前扫描到的结点
    int j = 0;                                      //当前p指向的是第几个结点
    p= L;                                           //L指向头结点,头结点是第0个结点(不存数据)
    while ( p != NULL && j<i-1){                    //循环找到第 i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)                                  //i值不合法
        return false;
    LNode  *s = (LNode*) malloc (sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;                                    //将结点s连到p之后
    return true;                                    //insert成功
}

bool ListInsert2(LinkedList L,int i,int e){          //在第i个位置插入元素e(不带头结点)
    if (i<1)
        return false;
    if(i ==1 ){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;                                         //指针p指向当前扫描到的结点
    int j = 1;                                        //当前p指向的是第几个结点
    p= L;                                             //L指向头结点,头结点是第0个结点(不存数据)
    while ( p != NULL && j<i-1){                      //循环找到第 i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)                                      //i值不合法
        return false;
    LNode  *s = (LNode*) malloc (sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;                                        //将结点s连到p之后
    return true;                                        //insert成功
}

bool InsertNextNode (LNode *p,int e){               //在p结点之后插入元素e
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc (sizeof (LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode (LNode *p,int e){              //在P结点之前插入元素e
    if (p == NULL)
        return false;
    LNode *s = (LNode*)malloc (sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p ->data;
    p->data =e;
    return true;
}

bool ListDelete(LinkedList L,int i ,int e){         //带头结点➡️按位序删除
    if (i<1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p !=NULL && j<i-1){
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

int main(){
    LinkedList L1;                                      //声明一个指向单链表的指针
    LinkedList L2;

    L1 = (LinkedList)InitList1(L1);

    bool isEmpty1 = Empty1(L1);
    printf("List 1 is empty: %s\n", isEmpty1 ? "true" : "false");

    L2 = (LinkedList) InitList2(L2);

    bool isEmpty2 = Empty2(L2);
    printf("List 2 is empty: %s\n", isEmpty2 ? "true" : "false");

    int elem = GetElem(L2,3);
    printf("The 3rd element of the LinkedList is %d\n", elem);
}