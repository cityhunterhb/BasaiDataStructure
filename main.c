//
//  main.c
//  basic_adt
//
//  Created by zhengjack on 18/9/26.
//  Copyright © 2018年 xcode-c. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Header.h"

//#include <Python/Python.h>
#define OK      1
#define ERROR   0
#define FALSE   0
#define TRUE    1
typedef int Status;




void PrintStr(const char *src)
{
	if(src == NULL)
	{
		return;
	}
    printf("==========%s==========\n", src);
	/* printf("\n"); */
}

int Sequential_Search(int *a, int n, int key)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i] == key)

        {
            return i+1;
        }
    }

    return FALSE;
}

void Swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_sort(int a[], int n)
{
    if (a == NULL || n < 1)
    {
        return;
    }

    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if(a[j] < a[i])
            {
                Swap(&a[i], &a[j]);
            }
        }
    }
}

void Bubble_sort1(int a[], int n)
{
	if(a == NULL || n < 1)
	{
		return;
	}


}

void TestFunction(void)
{
	int i, a[100];
	int count = 0;
	srand((unsigned int)time(NULL));
	for(i=0; i<10; i++)
	{
		a[i] = rand() % 1000;
		printf("%d ", a[i]);
		count += a[i];
	}
	printf("\n");

	printf("count = %d\n", count);
}

int main(int argc, const char * argv[])
{

    //PrintStr("test xcode!");

    int Test[100] = {0};
    int j;
	BiTree TestTree;
	int TDepth;
	int TLeaf;


	TestFunction();

    srand((unsigned int)time(NULL));
	PrintStr("==========Generate random number==========");
    for(j=0; j<100; j++)
    {
        Test[j] = rand() % 100 + 1;
        printf("%d ", Test[j]);
        if ((j+1) % 10 == 0)
        {
            printf("\n");
        }
    }
    //printf("\n");
	PrintStr("==========Generate random number finish!!!==========");
	printf("\n");


    Bubble_sort(Test, 100);
	PrintStr("==========After Bubble_sort==========");
    for (j=0; j<100; j++)
    {
        printf("%d ", Test[j]);
    }
    printf("\n");
	PrintStr("==========After Bubble_sort finish!!!==========");
	printf("\n");

	PrintStr("==========CreateBiTree_PreOrder==========");

	printf("Please input numbers:\n");
	CreateBiTree_PreOrder(&TestTree);
	PrintStr("==========CreateBiTree_PreOrder finish!!!==========");
	printf("\n");

	PrintStr("PreOrderTraverse begin");
	PreOrderTraverse(TestTree);
	PrintStr("PreOrderTraverse finish!!!");
	printf("\n");



	PrintStr("InOrderTraverse begin");
	InOrderTraverse(TestTree);
	PrintStr("InOrderTraverse finish!!!");
	printf("\n");

	PrintStr("PostOrderTraverse begin");
	PostOrderTraverse(TestTree);
	PrintStr("PostOrderTraverse finish!!!");
	printf("\n");


	PrintStr("TreeDepth begin");
	TDepth = TreeDepth(TestTree);
	printf("TDepth=%d\n", TDepth);
	PrintStr("TreeDepth finish!!!");
	printf("\n");

	TLeaf = TreeLeaf(TestTree);
	printf("TLeaf=%d\n", TLeaf);

    return 0;
}
