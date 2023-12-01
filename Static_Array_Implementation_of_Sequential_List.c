//      线性结构+顺序存储==顺序表
//      顺序表的静态分配➡️数组

#include <stdio.h>
#define MaxiSize 10

typedef struct {
    int data [MaxiSize];                    //声明名为data的数组,大小为MaxSize
    int length;                             //顺序表的长度
}SqList;                                    //Sequence List

void InitList ( SqList *L) {                //初始化函数,参数为指向SqList的指针
    for (int i = 0; i < MaxiSize; i++) {    //从0遍历到MaxSize-1
        L->data[i] = 0;                     //L指向的顺序表的data数组的所有元素设为0
    }
    L->length = 0;                      //空表

}
int main() {                            //程序入口
    SqList L;                           //声明一个顺序表
    // ➡️在内存中分配存储顺序表L的空间
    //MaxSize*sizeof(int)+存储length的空间
    InitList(&L);                       //调用初始化函数,将L的地址作为参数传递
    printf("Length:%d,Fist element:%d\n",L.length,L.data[0]);
}
