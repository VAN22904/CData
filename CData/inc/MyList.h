/*
 * MyList.h
 *
 *  Created on: 2016��9��1��
 *      Author: Administrator
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include "Include.h"

#define ARRLIST_INIT_SIZE 50
#define ARRLISTINCREMENT 10

typedef  int ElemType;
typedef  int Status;

typedef struct{
	ElemType *elem;		//����ַ
	int length;
	int listSize;
}ArrList;


void errInfo(char *info,int status);
void normalInfo(char *info);
void MyListTest();
Status initList(ArrList *L,int length);
Status isEmpty(ArrList *L);
Status insertList(ArrList *L,ElemType elem,int pos);
Status delList(ArrList *L,int pos);
void printArrList(ArrList *L);



#endif /* MYLIST_H_ */
