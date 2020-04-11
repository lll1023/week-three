#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include <malloc.h>
#include <string.h>

int menu(){ 
    
    int menuDecision;
    char check[100];
    	printf(
    
		"\n\t_________________链式队列功能菜单_________________________\t\n"
		"\t|1:选择存储的方式                                         |\t\n"
		"\t|2:退出程序                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t请输入你想进行的操作：");
        scanf("%s",check);
	//输入检测
     while(1){
        while(strlen(check)!=1){ 
                	printf("请输入供参考的选项：");
                   scanf("%s",check);
    //  fflush(stdin);
        }
            menuDecision=(int)check[0]-48;
        if(menuDecision==1||menuDecision==2){
	      break;
       }
           	printf("请输入以上供参考的选项：");
           scanf("%s",check);
     }

//	while (choice<1||choice>2){//判断执行1-6，并且检测合法输入
//		printf("\t您的输入: '%d' 有误!请重新输入：", choice);
//		scanf(" %d", &choice); 
//	}
    
	return menuDecision;
}

int init(){ 
    
    int initDecision;
    char check[100];
    	printf(
    
		"\n\t_________________链式队列功能菜单___________________________\t\n"
		"\t|1:初始化队列                                             |\t\n"
		"\t|2:销毁队列                                               |\t\n"
		"\t|3:检查队列是否为空_______________________________________|\t\n"
        "\t|4:查看队头元素___________________________________________|\t\n"
        "\t|5:确定队列长度___________________________________________|\t\n"
        "\t|6:入队操作_______________________________________________|\t\n"
        "\t|7:出队操作_______________________________________________|\t\n"
        "\t|8:清空队列_______________________________________________|\t\n"
        "\t|9:展示队列元素___________________________________________|\t\n"
        "\t|10:退出程序______________________________________________|\t\n"
	    "\t|_________________________________________________________|\t\n"
    );
    	printf("\t请输入你想进行的操作：");
        scanf("%s",check);
	//输入检测
     while(1){
        while(strlen(check)==0||strlen(check)>2){ 
                	printf("请输入以上供参考的选项：");
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
           	printf("请输入供参考的选项：");
           scanf("%s",check);
     }

//	while (choice<1||choice>2){//判断执行1-6，并且检测合法输入
//		printf("\t您的输入: '%d' 有误!请重新输入：", choice);
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
	             printf("请先初始化队列");
            continue;
        }else if(flag==1&&decision==1){
	             printf("已初始化，请选择其他操作\n");
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
	                                printf("队列为空\n");
                   }else{
	                                printf("队列不为空\n");
                   }
                   break;
            case 4:if(choice==1){
	                    if(GetHeadLQueue(&Q,&intChoice) ){
	                                      printf("队头元素为%d\n",intChoice);
                        }	                           
                    }else if(choice==2){
	                    if(GetHeadLQueue(&Q,&charChoice) ){
	                                      printf("队头元素位%c\n",charChoice);
                        } 
                    }else if(choice==3){
	                    if(GetHeadLQueue(&Q,&floatChoice) ){
	                                      printf("队头元素为%f\n",floatChoice);
                        }
                    }else if(choice==4){
	                    if(GetHeadLQueue(&Q,&doubleChoice) ){
	                                      printf("队头元素为%lf\n",doubleChoice);
                        }
                    }
                    break;
            case 5:length=LengthLQueue(&Q);
                              printf("队列长度为:%d\n",length);
                    break;
            case 6:if(choice==1){
	                                printf("请输入int型入队元素值:\n");
	                    while(scanf(" %d", &intChoice)!=1){
                                       	printf("请输入int型变量值:\n");
                                          fflush(stdin);
                        } 
                                    EnLQueue(&Q,&intChoice);	                  
                    }else if(choice==2){
	                                printf("请输入char型入队元素值:\n");
	                    while(scanf(" %c", &charChoice)!=1){
                                    	printf("请输入char型变量值:\n");
                                          fflush(stdin);
                        }
                                    EnLQueue(&Q,&charChoice); 
                    }else if(choice==3){
	                                printf("请输入float型入队元素值:\n");
	                    while(scanf(" %f", &floatChoice)!=1){
                                       	printf("请输入float型变量值:\n");
                                          fflush(stdin);
                        }
                                    EnLQueue(&Q,&floatChoice); 	
                    }else if(choice==4){
	                                printf("请输入double型入队元素值:\n");
	                    while(scanf(" %lf", &doubleChoice)!=1){
                                       	printf("请输入double型变量值:\n");
                                          fflush(stdin);
                        } 
                                    EnLQueue(&Q,&doubleChoice);	
                    }
                    break; 
            case 7: if(DeLQueue(&Q)){
	                                printf("出队成功\n");
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
