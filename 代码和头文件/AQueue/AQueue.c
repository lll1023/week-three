#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return;
    }
    int i;
    if(choice==1){
        for(i=0;i<MAXQUEUE;i++){
	              Q->data[i]=(int*)malloc(sizeof(int));
        }
    }else if(choice==2){
	    for(i=0;i<MAXQUEUE;i++){
	              Q->data[i]=(char*)malloc(sizeof(char));
        }
    }else if(choice==3){
	    for(i=0;i<MAXQUEUE;i++){
	              Q->data[i]=(float*)malloc(sizeof(float));
        }
    }else if(choice==4){
	    for(i=0;i<MAXQUEUE;i++){
	              Q->data[i]=(double*)malloc(sizeof(double));
        }
    }     
      Q->front=0;
      Q->rear=0;
      printf("队列初始化成功\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return;
    }
    int i;
    for(i=0;i<MAXQUEUE;i++){
	        free(Q->data[i]);
    }
      Q->front=0;
      Q->rear=0;
      printf("销毁队列成功\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
	if((Q->rear+1)%MAXQUEUE==Q->front){
	    return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return TRUE;
    }
    if(Q->front==Q->rear){
	    return TRUE;
    }
    return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
    if(e==NULL){
	        printf("指针e为空\n");
        return FALSE;
    }
    if(Q->front==Q->rear){
	        printf("队列没有元素，无法查看队头元素\n");
        return FALSE;
    }
    if(choice==1){
	    *(int*)e=*(int*)(Q->data) [Q->front];
    }else if(choice==2){
	    *(char*)e=*(char*)(Q->data) [Q->front];
    }else if(choice==3){
	    *(float*)e=*(float*)(Q->data) [Q->front];
    }else if(choice==4){
	    *(double*)e=*(double*)(Q->data) [Q->front];
    }
    return TRUE;
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return 0;
    }
    if(Q->front==Q->rear){
	    return 0;
    }
    int count=(Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
    return count;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
    if((Q->rear+1)%MAXQUEUE==Q->front){
	        printf("队列已满，无法入队\n");
        return FALSE;
    }
    if(choice==1){
	    *(int*)Q->data[Q->rear]=*(int*)data;
    }else if(choice==2){
	    *(char*)Q->data[Q->rear]=*(char*)data;
    }else if(choice==3){
	    *(float*)Q->data[Q->rear]=*(float*)data;
    }else if(choice==4){
	    *(double*)Q->data[Q->rear]=*(double*)data;
    }
      Q->rear=(Q->rear+1)%MAXQUEUE;
    return TRUE;
}	



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
    if(Q->front==Q->rear){
	        printf("队列没有元素，无法出队\n");
        return FALSE;
    }
      Q->front=Q->front+1;
    return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return;
    }
      Q->front=0;
      Q->rear=0;
      printf("清空队列成功\n");
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(Q==NULL){
	        printf("队列指针为空\n");
        return FALSE;
    }
    if(Q->front==Q->rear){
	        printf("队列没有元素\n");
        return FALSE;
    }
    int now=Q->front;
      printf("队列元素有:");
    while(now!=Q->rear){
	        foo(Q->data[now]);
            now=(now+1)%MAXQUEUE;
    }
    return TRUE; 
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
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
