#include<stdio.h>
#include<malloc.h>

#define MaxSize 10000

typedef struct LNode *List;

struct LNode{
    
    int data; //存数数据
    List next; //指向下一节点的指针

};

struct LNode L;
List Ptrl;

//初始化
List InitList(){

    Ptrl =  (List)malloc(sizeof(struct LNode));
    Ptrl->next = NULL;

    return Ptrl;

}


//创建链表

//方法一：头插法
void CreateList_H(List Ptrl, int length){

    List p;
    
    for (int i = 0; i < length; i++){

        p = (List)malloc(sizeof(struct LNode));
        scanf("%d",&p->data);
        p->next = Ptrl->next;
        Ptrl->next = p;

    }
    
}

//方法二:尾插法
void CreateList_T(List Ptrl, int length){

    List r,p;

    r = Ptrl;

    for (int i = 0; i < length; i++){
        
        p = (List)malloc(sizeof(struct LNode));
        scanf("%d",&p->data);
        p->next = NULL;
        r->next = p;
        r = p;

    }
    
}

//求表长
int Length(List Ptrl){

    List p = Ptrl;
    
    int length = 0;

    while (p->next != NULL){
        p = p->next;
        length++;
    }
    
    return length;

}

//查找(序号)
List FindKth(int K, List Ptrl){

    List p = Ptrl;

    int i = 1;

    while (p && i < K){
        p = p->next;
        i++;
    }
    
    if(i == K) return p;
    else return NULL;

}

//查找(按值)
List Find(int X, List Ptrl){

    List p = Ptrl;

    while (p != NULL && p->data != X){
        p = p->next;
    }
    
    return p;

}

/* 插入
1. 用 s 指向一个新的结点
2. 用 p 指向链表的第 i-1 个结点 
3. s->Next = p->Next，将 s 的下一个结点指向 p 的下一个结点 
4. p->Next = s，将 p 的下一结点改为 s   */
List Insert(int X, int i){/*插入在第i-1个结点*/

    List p, s;

    if( i == 1){ /*新节点插在表头*/

        s = (List)malloc(sizeof(struct LNode)); //申请结点
        s->next = Ptrl; //指向下一个链表
        s->data = X;    //赋值
        
        return s;

    }

    p = FindKth(i-1,Ptrl); //查找插入位置

    if (p == NULL){
        
        printf("参数错误");

        return NULL;

    }else{

        s = (List)malloc(sizeof(struct LNode));

        s->next = p->next;
        s->data = X;
        p->next = s;
   
        return Ptrl;

    }
    

}

/* 删除
1. 用 p 指向链表的第 i-1 个结点 
2. 用 s 指向要被删除的的第 i 个结点
3. p->Next = s->Next，p 指针指向 s 后面
4. free(s)，释放空间 
*/
List Delete(int i,List Ptrl){

    List s,p;

    if(i == 1){

        s = Ptrl;

        if (Ptrl != NULL){
            Ptrl = Ptrl->next;
        }else{
            return NULL;
        }

        free(s);

        return Ptrl;
        
    }

    p = FindKth(i-1,Ptrl);

    if (p == NULL || p->next == NULL){
        
        printf("节点不存在");
        
        return NULL;
    
    }else{

        s = p->next;
        p->next = s->next;
        free(s);

        return Ptrl;
    }
    

}


void Display(List Ptrl){

    List t;
	int flag = 1;
	
    printf("当前链表为：");
	
    for(t = Ptrl->next; t;t = t->next){
		printf("%d  ",t->data);
		flag = 0;
	}
	
    if(flag)
		printf("NULL");
	printf("\n"); 
}

int main(){

    Ptrl = InitList();

    int l;
    printf("输入链表初始长度\n");
    scanf("%d",&l);

    //CreateList_H(Ptrl,l);
    CreateList_T(Ptrl,l);
    Display(Ptrl);

    Insert(4,2);
    Display(Ptrl);

    Delete(2,Ptrl);
    Display(Ptrl);

	return 0;

}
