//
//  Tree.h
//  basic_adt
//
//  Created by zhengjack on 18/9/26.
//  Copyright © 2018年 xcode-c. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdlib.h>

/*Operation
InitTree(*T)
DestroyTree(*T)
CreateTree(*T, definition) based on definition
ClearTree(*T) if the T existed
TreeEmpty(T) if the tree is empty, return TRUE, else return FALSE
TreeDepth(T)
Root(T)
Value(T, cur_e) return the value of the treenode cur_e
Assign(T, cur_e, value)
Parent(T, cur_e) if the cur_e is not the root node,return the value, else return NULL
LeftChild(T, cur_e)
RightSibling(T, cur_e)
InsertChild(*T, *p, i, c) p point to some node,
DeleteChild(*T, *p, i)
*/

#define MAX_TREE_SIZE 100
//typedef int TElemType;
typedef char TElemType;

//parent
typedef struct PTNode
{
	TElemType data[MAX_TREE_SIZE];
	int parent;
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;
}PTree;
//end


//child
typedef struct CTNode
{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct  //root
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
}CTree;
//end


//child sibling
typedef struct CSNode
{
	TElemType data;
	struct CSNode *firstchild, *rightchild;
}CSNode, *CSTree;
//end


//binary tree
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

extern int CreateBiTree_PreOrder(BiTree *T);
extern void PreOrderTraverse(BiTree T);
extern void PostOrderTraverse(BiTree T);
extern void InOrderTraverse(BiTree T);
extern int TreeDepth(BiTree T);
extern int TreeLeaf(BiTree T);

#endif /* Tree_h */
