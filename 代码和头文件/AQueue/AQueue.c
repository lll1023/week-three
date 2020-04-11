#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
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
      printf("���г�ʼ���ɹ�\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return;
    }
    int i;
    for(i=0;i<MAXQUEUE;i++){
	        free(Q->data[i]);
    }
      Q->front=0;
      Q->rear=0;
      printf("���ٶ��гɹ�\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
	if((Q->rear+1)%MAXQUEUE==Q->front){
	    return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return TRUE;
    }
    if(Q->front==Q->rear){
	    return TRUE;
    }
    return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
    if(e==NULL){
	        printf("ָ��eΪ��\n");
        return FALSE;
    }
    if(Q->front==Q->rear){
	        printf("����û��Ԫ�أ��޷��鿴��ͷԪ��\n");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
    if((Q->rear+1)%MAXQUEUE==Q->front){
	        printf("�����������޷����\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
    if(Q->front==Q->rear){
	        printf("����û��Ԫ�أ��޷�����\n");
        return FALSE;
    }
      Q->front=Q->front+1;
    return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return;
    }
      Q->front=0;
      Q->rear=0;
      printf("��ն��гɹ�\n");
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
    if(Q->front==Q->rear){
	        printf("����û��Ԫ��\n");
        return FALSE;
    }
    int now=Q->front;
      printf("����Ԫ����:");
    while(now!=Q->rear){
	        foo(Q->data[now]);
            now=(now+1)%MAXQUEUE;
    }
    return TRUE; 
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q){
	if(q==NULL){
	        printf("ָ��qΪ��\n");
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
    	printf("��ѡ�����µĴ洢��ʽ��\n 1.int \t2.char \t3.float \t4.double\n");
      scanf("%s",choose);
    while(1){
        while(strlen(choose)!=1){ 
               	printf("�����빩�ο���ѡ�");
                  scanf("%s",choose);
    //  fflush(stdin);
        }
            choice=(int)choose[0]-48;
        if(choice==1||choice==2||choice==3||choice==4){
	        break;
        }
           	printf("�����빩�ο���ѡ�");
            scanf("%s",choose);
     }
} 
