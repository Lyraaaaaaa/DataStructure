//用malloc实现动态数组的扩展➡️顺序表的扩展


#include<stdlib.h>      //malloc  free
#include<stdio.h>

#define InitSize 10
typedef struct {
    int *data;
    int MaxSize;
    int length;
}SeqList;

void InitList1 (SeqList *L){                                  //声明初始化函数
    L->data = (int *) malloc (InitSize * sizeof(int));  //malloc函数会为SeqList的data成员申请新的内存区域,大小=InitSize个int的大小
                                                             //malloc会返回一个指针(指向存储空间的起始地址)
                                                             // 将malloc函数返回的指针的值赋给data
                                                             //执行完此语句➡️data指针会指向空间起始位置
    L->length = 0;
    L->MaxSize = InitSize;
}

void IncreaseSize (SeqList *L, int len){                //声明增加顺序表大小的函数
    int *p = L->data;                                   //将data成员的当前值保存到指针p指向的地址➡️data与p指向同一地址
    L->data = (int *) malloc ((L->MaxSize+len) * sizeof(int));
                                                        //malloc函数为data申请新的内存区域,大小为MaxSize+len个int的大小
                                                        //data指针指向新的内存区域
    for (int i = 0;i<L->length;i++){
        L->data[i]=p[i];                                //通过循环将原来的数据复制到新的内存区域
    }
    L->MaxSize = L->MaxSize + len;                      //为MaxSize增加len
    free(p);                                            //释放原来的内存
}

int GetElem (SeqList L,int i){                          //按位查找
    return L.data[i-1];
}

int main(){
    SeqList L;
    InitList1 (&L);
    printf("MaxSize:%d\n",L.MaxSize);
    IncreaseSize(&L,5);                             //调用函数将内存大小增加5
    printf("MaxSize:%d\n",L.MaxSize);

    GetElem(L,3);                                    //调用按位查找
    return 0;


}