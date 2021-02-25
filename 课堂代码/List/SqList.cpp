#include<stdio.h>
#include<malloc.h>

#define MaxSize 10000

typedef struct LNode *List;

struct LNode{
    
    int last; // 线性表最后一个元素的位置
    int data[MaxSize]; // 存储线性表的数据

};

struct LNode L;

List PtrL;

//初始化
List MakeEmpty(){
    
    List PtrL;

    PtrL = (List)malloc(sizeof(struct LNode)); //初始化
    
    printf("输入表的最后元素的位置\n");

    int length;

    scanf("%d",&length);

    PtrL->last = length;

    return PtrL;

}

//查找
int Find(int X, List PtrL){

    int i = 0;

    /*
    *i <= PtrL->last 防止越界
    *PtrL->data[i] != X 查找
    * */
    while(i <= PtrL->last && PtrL->data[i] != X)
        i++;
    
    if(i > PtrL->last) //如果没找到，返回-1
        return -1;  //如果找到，返回位序
    else
        return i;

}

//插入
void Insert(int X,int i,List L){/*i代表 a1,a2,....,ai*/

    if(PtrL->last == MaxSize-1){/*判断表是否满*/
        printf("表满");
        return ;
    }

    if(i < 1 || i > PtrL->last+2){/*判断插入位置是否合法*/
        printf("输入的位置不合法\n");
        return ;
    }

    for (int j = PtrL->last; j > i-1; j--)/*数据后移*/
        PtrL->data[j+1] = PtrL->data[j];
    
    PtrL->data[i] = X;/*插入*/
    PtrL->last++; /*表长加1*/

    return ;
    
}

//删除
void Delete(int i,List L){/*i代表 a1,a2,....,ai*/

    if(i < 1 || i > PtrL->last+2){/*判断删除位置是否合法*/
        printf("输入的位置不合法\n");
        return ;
    }

    for (int j = i; j <= PtrL->last; j++)
        PtrL->data[j] = PtrL->data[j+1];

    PtrL->last--;
    return ;

}

//输出表的数据
void Display(){
   
    for (int i = 0; i <= PtrL->last; i++){
        printf("%d ",PtrL->data[i]);
    }

    printf("\n");
    
}


int main(){

    PtrL = MakeEmpty();

    printf("输入表的数据\n");
    
    //输入表的值
    for (int i = 0; i <= PtrL->last; i++){
        
        int e; 
        
        scanf("%d",&e);
        
        PtrL->data[i] = e;
    
   }

    int fx; //查找的值
    
    printf("请输入查找的元素\n");
    scanf("%d",&fx);

    printf("查找%d的位置%d\n",fx,Find(fx,PtrL));

    int ix; //插入的值
    int ii; //插入的位置
    printf("请输入插入的元素及位置\n");
    scanf("%d%d",&ix,&ii);
    Insert(ix,ii,PtrL);
    printf("插入后的表\n");
    Display();

    int di; //删除的位置
    printf("请输入删除的元素的位置\n");
    scanf("%d",&di);
    Delete(di,PtrL);
    printf("删除后的表\n");
    Display();

}