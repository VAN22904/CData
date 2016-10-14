/*
 * MyFound.h
 *
 *  Created on: 2016��10��14��
 *      Author: Administrator
 */

#ifndef INC_MYSEARCH_H_
#define INC_MYSEARCH_H_

#include "Include.h"

void OrderSearchTest();
void BinarySearchTest();

/*
 * ��ϣ��
 */
#define HASHTABLEMAX 100
typedef int HashDataType;
typedef int HashIdType;

typedef struct _link_node {
	HashIdType id;
	HashDataType data;
	struct _link_node *next;
} HLinkNode, *HLinkNodePtr;
typedef struct _hash_header {
	struct _link_node *next;
} HashHead, *HashHeadPtr;

void hashTableTest();

#endif /* INC_MYSEARCH_H_ */
