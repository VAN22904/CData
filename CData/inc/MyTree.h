/*
 * MyTree.h
 *
 *  Created on: 2016��9��12��
 *      Author: Administrator
 */

#ifndef MYTREE_H_
#define MYTREE_H_

#include "Include.h"

typedef char TElemType;

typedef struct BitNode {
	TElemType data;
	struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

Status CreateBitTree(BitTree &T);
Status PreOrderTraverse(BitTree T);
Status InOrderTraverse(BitTree T);
Status PostOrderTraverse(BitTree T);
void LevelOrderTraverse(BitTree T);
Status Visit(BitTree &T);
void BitTreeTest();
void PreOrderTraverseFor(BitTree T);
void InOrderTraverseFor(BitTree T);
void PostOrderTraverseFor(BitTree T);

typedef BitTree StackElemType;
typedef BitTree QueueElemType;

#define MAX 10 // MAXIMUM STACK CONTENT
#define MAX_QUEUE 10 // MAXIMUM QUEUE CONTENT
class stack {
private:
	StackElemType arr[MAX];
	int tag[MAX];
	int top;
public:
	stack() {
		inItStack();
	}
	/************************************************************************/
	/* ��ʼ��ջ                                                                     */
	/************************************************************************/
	void inItStack() {
		top = -1;
	}
	/************************************************************************/
	/* ��ջ                                                                     */
	/************************************************************************/
	void push(StackElemType a) {
		top++;
		if (top < MAX) {
			arr[top] = a;
		} else {
			cout << "STACK FULL!!" << top;
		}
	}
	/************************************************************************/
	/* ��ջ                                                                     */
	/************************************************************************/
	StackElemType pop() {
		if (isEmpty()) {
			cout << "STACK IS EMPTY ";
			return NULL;
		} else {
			StackElemType data = arr[top];
			arr[top] = NULL;
			top--;
			return data;
		}
	}

	/************************************************************************/
	/* ��ջ                                                                     */
	/************************************************************************/
	StackElemType getTop() {
		if (isEmpty()) {
			cout << "STACK IS EMPTY ";
			return NULL;
		} else {
			return arr[top];
		}
	}
	/************************************************************************/
	/* �Ƿ�Ϊ��                                                                     */
	/************************************************************************/
	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}

	int SetTag(int v) {
		tag[top] = v;
	}
	int GetTag() {
		return tag[top];
	}
};

class queue {
private:
	QueueElemType elem[MAX_QUEUE];     ///���赱����ֻʣ��һ����Ԫʱ��Ϊ����
	int front;      //��ͷָ��
	int rear;       //��βָ��
public:
	/************************************************************************/
	/*
	 ��ʼ��
	 ֱ��ʹ�ýṹ��ָ������������ȷ����ڴ��ַ������ַ��ָ��
	 */
	/************************************************************************/
	void InitQueue() {
		front = rear = -1;

	}
	/************************************************************************/
	/*     ���
	 */
	/************************************************************************/

	void EnQueue(QueueElemType e) {
		if ((rear + 1) % MAX_QUEUE == front)
			exit(-1);
		rear = (rear + 1) % MAX_QUEUE;
		//cout << e->data;
		elem[rear] = e;
	}
	/************************************************************************/
	/*     ����
	 */
	/************************************************************************/
	QueueElemType DeQueue() {
		if (QueueEmpty())
			exit(-1);
		front = (front + 1) % MAX_QUEUE;
//		if (elem[front] != NULL) {
//			cout << elem[front]->data;
//		}

		return elem[front];
	}
	/************************************************************************/
	/*    ��ȡ��ͷԪ������
	 */
	/************************************************************************/

	QueueElemType GetFront() {
		if (QueueEmpty())
			exit(-1);
		return elem[(front + 1) % MAX_QUEUE];
	}
	/************************************************************************/
	/*    �ж϶���Q�Ƿ�Ϊ��
	 */
	/************************************************************************/
	int QueueEmpty() {
		if (front == rear)
			return 1;
		else
			return 0;
	}

};

#endif /* MYTREE_H_ */
