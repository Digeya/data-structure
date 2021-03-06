//实验8.c 
//by midi

#include "stdio.h"
#include "stdlib.h"
#include<stdlib.h>
#define MAX 20
#define Null 0

typedef  char TElemType;
typedef  int Status;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;



Status CreateBiTree(BiTree *T) {
	char ch;
	ch=getchar();
	if (ch=='#') //#代表空指针
	(*T)=Null; else {
		(*T)=(BiTree) malloc(sizeof(BiTNode));
		//申请结点
		(*T)->data=ch;
		//生成根结点 
		CreateBiTree(&(*T)->lchild);
		//构造左子树
		CreateBiTree(&(*T)->rchild) ;
		//构造右子树
	}
	return 1;
}

// 递归 先序遍历 
void PreOrder(BiTree T) {
	if (T) {
		printf("%2c",T->data);
		//访问根结点，此处简化为输出根结点的数据值
		PreOrder(T->lchild);
		//先序遍历左子树
		PreOrder(T->rchild);
		//先序遍历右子树
	}
}

void Norec_PreOrder(BiTree T) {
	if (T) {
		BiTree stack[10];
		int stackTop = -1;
		BiTree t = T;
		while(stackTop != -1 || t) {
			while(t) {
				printf(" %c", t->data);
				stack[++stackTop] = t;
				t = t->lchild;
			}
			if(stackTop != -1) {
				t = stack[stackTop--];
				t = t->rchild;
			}
		} 
	}
}



// 递归 中序遍历 
void InOrder(BiTree T) {
	if (T) {

		InOrder(T->lchild);
		//先序遍历左子树
		printf("%2c",T->data);
		//访问根结点，此处简化为输出根结点的数据值
		InOrder(T->rchild);
		//先序遍历右子树
	}
}

void Norec_InOrder(BiTree T) {
	
	if (T) {
		BiTree stack[10];
		int stackTop = -1;
		BiTree t = T;
		while(stackTop != -1 || t) {
			while(t) {
				
				stack[++stackTop] = t;
				t = t->lchild;
			}
			if(stackTop != -1) {
				t = stack[stackTop--];
				printf(" %c", t->data);
				t = t->rchild;
			}
		} 
	}
}

void PostOrder(BiTree T) {
	if (T) {
		
		PostOrder(T->lchild);
		//先序遍历左子树
		PostOrder(T->rchild);
		//先序遍历右子树
		
		printf("%2c",T->data);
		//访问根结点，此处简化为输出根结点的数据值
	}

} 

void Norec_PostOrder(BiTree T) {

	if (T) {
		BiTree stack[10];
		int stackTop = -1;
		BiTree t = T;
		BiTree tem = Null;
		
		while(stackTop != -1 || t) {
			if(t) {
				
				stack[++stackTop] = t;
				t = t->lchild;
//				printf("stackTop : %d , value:%c",stackTop,t->data);
				
			} else {
				t = stack[stackTop];
				if(t->rchild&&t->rchild!=tem) {
					t = t->rchild;
				} else {
					stackTop--;
					printf(" %c", t->data);
					tem = t;
					t = Null;
				}
				
			}
			
		} 
	}
} 



void LevleOrder(BiTree T) {
	//层次遍历二叉树T，从第一层开始，每层从左到右
	BiTree Queue[MAX],b;
	//用一维数组表示队列
	int front,rear;
	// front和rear分别表示队首和队尾指针
	front=rear=0;
	if(T) {
		//若树非空
		Queue[rear++]=T;
		//根结点入队列
		while (front!=rear) {
			//当队列非空
			b=Queue[front++];
			//队首元素出队列，并访问这个结点
			printf("%2c",b->data);
			if (b->lchild!=Null) 		//左子树非空，则入队列
			Queue[rear++]=b->lchild;
			if (b->rchild!=Null)		 //右子树非空，则入队列
			Queue[rear++]=b->rchild;
		}
	}
}
//LevelOrder


int depth(BiTree T) {
	//求二叉树的深度
	int dep1,dep2;
	if (T==Null) 
		return 0; else {
		dep1=depth(T->lchild);
		dep2=depth(T->rchild);
		return dep1>dep2?dep1+1:dep2+1;
	}
}
//depth



void main() {
	printf("-----------------------------\n");
	BiTree T=Null;
	printf("\n请输入一颗二叉树~：\n");
	CreateBiTree(&T);
	printf("\n一颗二叉树创建完成~：\n");
	printf("\n");

	
	
	while(1) {
		printf("\n-----------------------------\n");
		int num;
		printf("请输入序号1-8:\n");
		printf("1. 先序非递归遍历\n");
		printf("2. 先序递归遍历\n");
		printf("3. 中序非递归遍历\n");
		printf("4. 中序递归遍历\n");
		printf("5. 后序非递归遍历\n");
		printf("6. 后序递归遍历\n");
		printf("7. 层次遍历\n");
		printf("8. 树的深度\n");
		printf("9. 退出\n");
		printf("\n-----------------------------\n");
		scanf("%d",&num);
		
		switch(num) {
			case 1:printf("\n先序非递归遍历结果为:\n");Norec_PreOrder(T);printf("\n");break; 
			case 2:printf("\n先序递归遍历结果为:\n");PreOrder(T);printf("\n");break;
			
			case 3:printf("\n中序非递归遍历结果为:\n");Norec_InOrder(T);printf("\n");break;
			case 4:printf("\n中序递归遍历结果为:\n");InOrder(T);printf("\n");break; 
					
			case 5:printf("\n后序非递归遍历结果为:\n");Norec_PostOrder(T);printf("\n");break; 
			case 6:printf("\n后序递归遍历结果为:\n");PostOrder(T);printf("\n");break; 
			
			case 7:printf("\n层次遍历的结果为:\n");LevleOrder(T);printf("\n");break; 
			case 8:printf("\n数的深度为:%d\n",depth(T));printf("\n");break; 
			case 9:printf("\n886\n");exit(0); 

	
	}
}
} 
