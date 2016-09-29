/*
 * MyGraph.h
 *
 *  Created on: 2016��9��18��
 *      Author: Administrator
 */

#ifndef INC_MYGRAPH_H_
#define INC_MYGRAPH_H_

#include "Include.h"

typedef char VertexType;	//������������
typedef int EdgeType;		//��Ȩ����������

#define MAXVEX 20			//��󶥵���
#define INF		65535		//����������

#define debug

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVer, numEdg;
} MGraph;

int LocateMGraph(MGraph *g, VertexType v);
void CreateMGraph(MGraph *g);
void PrintMGraph(MGraph g);
void MGraphDFS(MGraph g, int i);
void MGraphDFSTraverse(MGraph g);
void MGraphTest();

typedef struct EdgeNode         //�߱���
{
	int adjvex;         //�ڽӵ��򣬴洢�ö����Ӧ���±�
	EdgeType weigth;        //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
	struct EdgeNode *next;      //����ָ����һ���ڽӵ�
} EdgeNode;
typedef struct VertexNode       //�����ṹ
{
	VertexType data;        //�����򣬴洢������Ϣ
	EdgeNode *firstedge;        //�߱�ͷָ��
} VertexNode, AdjList[MAXVEX];
typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;  //ͼ�е�ǰ�������ͱ���
} GraphList;

int LocateLGraph(GraphList *g, VertexType v);
void CreateLGraph(GraphList *g);
void PrintLGraph(GraphList *g);
void LGraphDFS(GraphList g, int i);
void LGraphDFSTraverse(GraphList g);
void LGraphTest();

//ʮ������
typedef struct VertexTNode       //�����ṹ
{
	VertexType data;        //�����򣬴洢������Ϣ
	EdgeNode *firstin;        //�߱�ͷָ��
	EdgeNode *firstout;
} VertexTNode, AdjTList[MAXVEX];
typedef struct {
	AdjTList adjList;
	int numVertexes, numEdges;  //ͼ�е�ǰ�������ͱ���
} GraphTList;

int LocateTGraph(GraphTList *g, VertexType v);
void CreateTGraph(GraphTList *g);
void PrintTGraph(GraphTList *g);
void TGraphTest();

//Prim�ýṹ��
struct CloseEdge {
	VertexType adjvex;
	EdgeType lowcost;
};
//Kruskal �ýṹ��
struct EdgeInfo {
	VertexType v1;
	VertexType v2;
	EdgeType cost;
	int used;		//0��ʾδ�ã�1��ʾ���ˣ�ɸѡʱ��
};
void MGraphPrimTest();
void MGraphKruskalTest();		//��ֵ��ʽ
void MGraphKruskalTest1();		//����ֵ��ʽ

void MGraphDijkstraTest();
void MGraphFloydTest();
void MGraphFloydTest1();
#endif /* INC_MYGRAPH_H_ */
