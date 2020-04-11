#include <stdio.h>
#include <malloc.h>
#include "LQueue.h"
#include <string.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */

void InitLQueue(LQueue *Q){
	if(Q==NULL){
        	printf("����ָ��Ϊ��\n");
        return;
    }
      Q->front=NULL;
      Q->rear=NULL;
      printf("��ʼ���ɹ�\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return TRUE;
    }
    if(Q->front==NULL){
	    return TRUE;
    }
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
    if(Q->front==NULL){
	        printf("����û��Ԫ�أ��޷������ͷԪ��\n");
        return FALSE;
    }
    if(e==NULL){
	        printf("ָ��eΪ��\n");
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }
    if(Q->front==NULL){
	        printf("����û��Ԫ�أ��޷�����\n");
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
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
      printf("�����ɹ�\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q==NULL){
	        printf("����ָ��Ϊ��\n");
        return FALSE;
    }if(Q->front==NULL){
	        printf("����û��Ԫ��\n");
        return FALSE;
    }
      Node* printNode=Q->front;
      printf("����Ԫ����:");
    while(printNode!=NULL){
	        foo(printNode->data);
            printNode=printNode->next;
    }
      printf("\n");
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
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
