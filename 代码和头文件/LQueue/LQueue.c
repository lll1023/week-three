#include <stdio.h>
#include <malloc.h>
#include "LQueue.h"
#include <string.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */

void InitLQueue(LQueue *Q){
	if(Q==NULL){
        	printf("队列指针为空\n");
        return;
    }
      Q->front=NULL;
      Q->rear=NULL;
      printf("初始化成功\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return TRUE;
    }
    if(Q->front==NULL){
	    return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
    if(Q->front==NULL){
	        printf("队列没有元素，无法输出队头元素\n");
        return FALSE;
    }
    if(e==NULL){
	        printf("指针e为空\n");
        return FALSE;
    }
    if(choice==1){
	    *(int*)e=*(int*)Q->front->data;
    }else if(choice==2){
	    *(char*)e=*(char*)Q->front->data;
    }else if(choice==3){
	    *(float*)e=*(float*)Q->front->data;
    }else if(choice==4){
	    *(double*)e=*(double*)Q->front->data;
    }
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return 0;
    }
    if(Q->front==NULL){
	    return 0;
    }
    int num=1;
      Node* traverseNode=Q->front; 
    while(traverseNode!=Q->rear){
	        num++;
            traverseNode=traverseNode->next;
    }
    return num;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
      Node* newNode=(Node*)malloc(sizeof(Node));
    if(choice==1){
	        newNode->data=(int*)malloc(sizeof(int)); 
	    *(int*)newNode->data=*(int*)data;
    }else if(choice==2){
	        newNode->data=(char*)malloc(sizeof(char));
     	*(char*)newNode->data=*(char*)data;
    }else if(choice==4){
	        newNode->data=(float*)malloc(sizeof(float));
	    *(float*)newNode->data=*(float*)data;
    }else if(choice==4){
	        newNode->data=(double*)malloc(sizeof(double));
	    *(double*)newNode->data=*(double*)data;
    }
      newNode->next=NULL;
    if(Q->front==NULL){
	        Q->front=newNode;
            Q->rear=newNode;
    }else{
	        Q->rear->next=newNode;
            Q->rear=newNode;
    }
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
    if(Q->front==NULL){
	        printf("队列没有元素，无法出队\n");
        return FALSE;
    }
    if(Q->front->next==NULL){
	        Q->front=NULL;
            Q->rear=NULL;
    }else{
	        Q->front=Q->front->next;
    }
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return;
    }
    if(Q->front!=NULL){
	    if(Q->front!=Q->rear){
	              Node* clearNode=Q->front;
                  Q->front=clearNode->next;
                  free(clearNode);
        }
	        free(Q->front);
            Q->front=NULL;
            Q->rear=NULL;
    }
      printf("操作成功\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }if(Q->front==NULL){
	        printf("队列没有元素\n");
        return FALSE;
    }
      Node* printNode=Q->front;
      printf("队列元素有:");
    while(printNode!=NULL){
	        foo(printNode->data);
            printNode=printNode->next;
    }
      printf("\n");
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
    if(q==NULL){
	        printf("指针q为空\n");
        return;
    }
    if(choice==1){
	        printf("%d\t",*(int*)q);
    }else if(choice==2){
	        printf("%c\t",*(char*)q);
    }else if(choice==3){
	        printf("%f\t",*(float*)q);
    }else if(choice==4){
	        printf("%lf\t",*(double*)q);
    }
}


int kind(){
    char choose[100];
    	printf("请选择如下的存储方式：\n 1.int \t2.char \t3.float \t4.double\n");
      scanf("%s",choose);
    while(1){
        while(strlen(choose)!=1){ 
               	printf("请输入供参考的选项：");
                  scanf("%s",choose);
    //  fflush(stdin);
        }
            choice=(int)choose[0]-48;
        if(choice==1||choice==2||choice==3||choice==4){
	        break;
        }
           	printf("请输入供参考的选项：");
            scanf("%s",choose);
     }
} 
