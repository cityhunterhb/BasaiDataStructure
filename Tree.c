//
//  Tree.c
//  basic_adt
//
//  Created by zhengjack on 18/9/26.
//  Copyright © 2018年 xcode-c. All rights reserved.
//

#include "Tree.h"
#define MAX 100

typedef struct SeqQueue
{
	BiTree data[MAX];
	int front;
	int rear;
}SeqQueue;

//PreOrder middle left right
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)
	{
		printf("PreOrder The tree is empty!\n");
		return;
	}

	printf("%c\n", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//InOrder left middle right
void InOrderTraverse(BiTree T)
{
	if(T == NULL)
	{
		printf("InOrder the tree is empty!\n");
		return;
	}

	InOrderTraverse(T->lchild);
	printf("%c\n", T->data);
	InOrderTraverse(T->rchild);
}


//PostOrder left right middle
void PostOrderTraverse(BiTree T)
{
	if(T == NULL)
	{
		printf("PostOrder the tree is empty!\n");
		return;
	}

	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c\n", T->data);
}


//Create BiTree
int CreateBiTree_PreOrder(BiTree *T)
{
	TElemType ch;
	scanf(" %c", &ch);
	if(ch == '#')
	{
		*T = NULL;
	    //return -1;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
		{
			printf("malloc is fail!\n");
			return -1;
		}
		(*T)->data = ch;
		CreateBiTree_PreOrder(&((*T)->lchild));
		CreateBiTree_PreOrder(&((*T)->rchild));
		//return 0;
	}

	return 0;
}

int CreateBiTree_InOrder(BiTree T)
{
	TElemType ch;
	scanf("%c", &ch);
	if(ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(T == NULL)
		{
			printf("malloc error!\n");
			return -1;
		}
		CreateBiTree_InOrder(T->lchild);
		T->data = ch;
		CreateBiTree_InOrder(T->rchild);
	}
	return 0;

}

int CreateBiTree_PostOrder(BiTree T)
{
	TElemType ch;
	scanf("%c", &ch);

	if(ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(T == NULL)
		{
			printf("malloc if failed!\n");
			return  -1;
		}
		CreateBiTree_PostOrder(T->lchild);
		CreateBiTree_PostOrder(T->rchild);
		T->data = ch;
	}

	return 0;
}


//get the depth of the tree
int TreeDepth(BiTree T)
{
	int Depth = 0;

	if(T != NULL)
	{
		int LeftDepth = TreeDepth(T->lchild);
		int RightDepth = TreeDepth(T->rchild);

		Depth = (LeftDepth >= RightDepth) ? LeftDepth + 1 : RightDepth + 1 ;
	}

	return Depth;
}

//get the leaf count of the tree
int TreeLeaf(BiTree T)
{
	static int LeafCount;

	if(T != NULL)
	{
		if(T->lchild == NULL && T->rchild == NULL)
		{
			LeafCount++;
		}

		TreeLeaf(T->lchild);
		TreeLeaf(T->rchild);
	}

	return LeafCount;
}



//=============Binary Search Tree================//
//f 指向P的双亲,初始化为NULL
//若查找成功，p指向该数据节点，否则P指向访问的最后一个节点
int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if(T == NULL)
	{
		*p = f;
		return 0;
	}
	else if(key == T->data)
	{
		*p = T;
		return 1;
	}
	else if(key < T->data) //left child
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);
	}
}

//insert BSTNode
int InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if(!SearchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;

		if(p == NULL) //new node
		{
			*T = s;   //s is root node
		}
		else if(key < p->data)
		{
			p->lchild = s; //s is left child
		}
		else
		{
			p->rchild = s; //s is right child
		}
		return 1;
	}
	else
	{
		return 0; //the tree already has the same node.
	}
}

//删除节点p，并重组左子树和右子树
int DeleteBSTNode(BiTree *p)
{
	BiTree q,s;
	if((*p)->lchild == NULL)//左子树为空重接右子树
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else if((*p)->rchild == NULL) //右子树为空，重接左子树
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q != *p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		free(s);
	}

	return 1;
}

//DeleteBST
int DeleteBST(BiTree *T, int key)
{
	if(*T == NULL)
	{
		return 0;
	}
	else
	{
		if(key == (*T)->data)
		{
			return DeleteBSTNode(T);
		}
		else if(key < (*T)->data)
		{
			return DeleteBSTNode((*T)->lchild);
		}
		else
		{
			return DeleteBSTNode((*T)->rchild);
		}
	}

	return 1;
}
