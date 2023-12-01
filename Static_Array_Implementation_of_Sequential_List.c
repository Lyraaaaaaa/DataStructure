//      线性结构+顺序存储==顺序表
//      顺序表的静态分配➡️数组

#include <stdio.h>
#include <stdbool.h>

#define MaxiSize 10                             //预处理指令➡️定义了一个名为MaxiSize的宏,值为10
                                                //在后续代码中MaxiSize会直接被替换为10
typedef struct {                                //声明SqList数据类型
    int data [MaxiSize];                        //声明名为data的数组,大小为MaxSize
    int length;                                 //顺序表的长度
}SqList;                                        //Sequence List

void InitList ( SqList *L) {                    //初始化函数,参数为指向SqList的指针
    for (int i = 0; i < MaxiSize; i++) {        //从0遍历到MaxSize-1
        L->data[i] = 0;                         //L指向的顺序表的data数组的所有元素设为0
    }
    L->length = 0;                              //空表
}

bool ListInsert (SqList *L,int i ,int e){        //声明在指定位置插入元素的函数➡️在顺序表L的i处插入e
    if(i<1 || i>L->length+1)                     //先判断i的范围是否有效
        return false;
    if (L->length>=MaxiSize)                    //如果存储空间已满则不能插入
        return false;
    for ( int j=L->length; j>=i; j-- )           //将第i个元素及之后的元素后移
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;                            //在i处放入e
    L->length++;                                 //长度+1
    return true;
}

bool ListDelete (SqList *L,int i ,int *e){       //删除L顺序表中第i个数据元素,删除的元素用e返回
    if (i<1 || i>L->length)                      //判断i的范围是否有效
        return false;
    *e = L->data[i-1];                           //将被删除的元素赋值给指针变量e所指向的内存区域中
    for (int j = i ;j<L->length;j++)             //用循环将第i个位置后的元素前移
        L->data[j-1] = L->data[j];
        L->length--;                             //线性表长度-1
        return true;
}

int main() {                                     //程序入口
    SqList L;                                    //声明一个顺序表
                                                 // ➡️在内存中分配存储顺序表L的空间
                                                 //MaxSize*sizeof(int)+存储length的空间
    InitList(&L);                                //调用初始化函数,将L的地址作为参数传递
    for (int a = 0; a < MaxiSize; a++) {
        L.data[a] = a;
        L.length++;
        printf("Before insertion：Length:%d,Elements:%d\n", L.length, L.data[a]);
    }

    ListInsert(&L, 3, 3);                   //删除L顺序表中第三个元素,将删除的元素用变量e返回
    for (int a = 0; a < L.length; a++) {
        printf("After insertion - Length:%d, Element:%d\n", L.length, L.data[a]);
    }
    int e = -1;                                 //用变量e把删除的元素“带回”
    bool deleteSuccess = ListDelete (&L, 3, &e);
    if (deleteSuccess){
        printf("Deleted the third element which is:%d\n", e);
    } else
        printf("illegal i,Deletion failed");
    return 0;
}