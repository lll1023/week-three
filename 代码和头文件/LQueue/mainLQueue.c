#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include <malloc.h>
#include <string.h>

int menu(){ 
    
    int menuDecision;
    char check[100];
    	printf(
    
		"\n\t_________________��ʽ���й��ܲ˵�_________________________\t\n"
		"\t|1:ѡ��洢�ķ�ʽ                                         |\t\n"
		"\t|2:�˳�����                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t������������еĲ�����");
        scanf("%s",check);
	//������
     while(1){
        while(strlen(check)!=1){ 
                	printf("�����빩�ο���ѡ�");
                   scanf("%s",check);
    //  fflush(stdin);
        }
            menuDecision=(int)check[0]-48;
        if(menuDecision==1||menuDecision==2){
	      break;
       }
           	printf("���������Ϲ��ο���ѡ�");
           scanf("%s",check);
     }

//	while (choice<1||choice>2){//�ж�ִ��1-6�����Ҽ��Ϸ�����
//		printf("\t��������: '%d' ����!���������룺", choice);
//		scanf(" %d", &choice); 
//	}
    
	return menuDecision;
}

int init(){ 
    
    int initDecision;
    char check[100];
    	printf(
    
		"\n\t_________________��ʽ���й��ܲ˵�___________________________\t\n"
		"\t|1:��ʼ������                                             |\t\n"
		"\t|2:���ٶ���                                               |\t\n"
		"\t|3:�������Ƿ�Ϊ��_______________________________________|\t\n"
        "\t|4:�鿴��ͷԪ��___________________________________________|\t\n"
        "\t|5:ȷ�����г���___________________________________________|\t\n"
        "\t|6:��Ӳ���_______________________________________________|\t\n"
        "\t|7:���Ӳ���_______________________________________________|\t\n"
        "\t|8:��ն���_______________________________________________|\t\n"
        "\t|9:չʾ����Ԫ��___________________________________________|\t\n"
        "\t|10:�˳�����______________________________________________|\t\n"
	    "\t|_________________________________________________________|\t\n"
    );
    	printf("\t������������еĲ�����");
        scanf("%s",check);
	//������
     while(1){
        while(strlen(check)==0||strlen(check)>2){ 
                	printf("���������Ϲ��ο���ѡ�");
                   scanf("%s",check);
    //  fflush(stdin);
        }
        if(strlen(check)==2&&check[0]=='1'&&check[1]=='0'){
	              initDecision=10;
        }else{
	              initDecision=(int)check[0]-48;
        }
       
       if(initDecision>=1&&initDecision<=10){
	      break;
       }
           	printf("�����빩�ο���ѡ�");
           scanf("%s",check);
     }

//	while (choice<1||choice>2){//�ж�ִ��1-6�����Ҽ��Ϸ�����
//		printf("\t��������: '%d' ����!���������룺", choice);
//		scanf(" %d", &choice); 
//	}
    
	return initDecision;
}

int main(){
    int menuDecision=menu();
    switch(menuDecision){
        case 1:kind();
               break;
        case 2:exit(0);	   
    }
    int decision,flag=0,intChoice,length,element;
    char charChoice;float floatChoice;double doubleChoice;
      LQueue Q;
    while(1){
	        decision=init();
        if(flag==0&&decision>1&&decision<10){
	             printf("���ȳ�ʼ������");
            continue;
        }else if(flag==1&&decision==1){
	             printf("�ѳ�ʼ������ѡ����������\n");
           continue;
        }
        switch(decision){
	        case 1:InitLQueue(&Q);
                             flag=1;
                   break;
            case 2:DestoryLQueue(&Q);
                             flag=0;
                   break;
            case 3:if(IsEmptyLQueue(&Q)){
	                                printf("����Ϊ��\n");
                   }else{
	                                printf("���в�Ϊ��\n");
                   }
                   break;
            case 4:if(choice==1){
	                    if(GetHeadLQueue(&Q,&intChoice) ){
	                                      printf("��ͷԪ��Ϊ%d\n",intChoice);
                        }	                           
                    }else if(choice==2){
	                    if(GetHeadLQueue(&Q,&charChoice) ){
	                                      printf("��ͷԪ��λ%c\n",charChoice);
                        } 
                    }else if(choice==3){
	                    if(GetHeadLQueue(&Q,&floatChoice) ){
	                                      printf("��ͷԪ��Ϊ%f\n",floatChoice);
                        }
                    }else if(choice==4){
	                    if(GetHeadLQueue(&Q,&doubleChoice) ){
	                                      printf("��ͷԪ��Ϊ%lf\n",doubleChoice);
                        }
                    }
                    break;
            case 5:length=LengthLQueue(&Q);
                              printf("���г���Ϊ:%d\n",length);
                    break;
            case 6:if(choice==1){
	                                printf("������int�����Ԫ��ֵ:\n");
	                    while(scanf(" %d", &intChoice)!=1){
                                       	printf("������int�ͱ���ֵ:\n");
                                          fflush(stdin);
                        } 
                                    EnLQueue(&Q,&intChoice);	                  
                    }else if(choice==2){
	                                printf("������char�����Ԫ��ֵ:\n");
	                    while(scanf(" %c", &charChoice)!=1){
                                    	printf("������char�ͱ���ֵ:\n");
                                          fflush(stdin);
                        }
                                    EnLQueue(&Q,&charChoice); 
                    }else if(choice==3){
	                                printf("������float�����Ԫ��ֵ:\n");
	                    while(scanf(" %f", &floatChoice)!=1){
                                       	printf("������float�ͱ���ֵ:\n");
                                          fflush(stdin);
                        }
                                    EnLQueue(&Q,&floatChoice); 	
                    }else if(choice==4){
	                                printf("������double�����Ԫ��ֵ:\n");
	                    while(scanf(" %lf", &doubleChoice)!=1){
                                       	printf("������double�ͱ���ֵ:\n");
                                          fflush(stdin);
                        } 
                                    EnLQueue(&Q,&doubleChoice);	
                    }
                    break; 
            case 7: if(DeLQueue(&Q)){
	                                printf("���ӳɹ�\n");
                    }
                    break;
            case 8:ClearLQueue(&Q);
                   break;
            case 9:TraverseLQueue(&Q,LPrint);
                   break;
            case 10:exit(0);
        }
    }
}
