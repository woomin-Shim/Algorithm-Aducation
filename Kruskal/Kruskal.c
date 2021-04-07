#include <stdio.h>
#include <stdlib.h>   // �������� ����ϱ� ���� ������� 
#define MAX 100

//��� ���� ���(����ġ�� ��Ÿ��)
int graph[9][9] = { 0, 4, -1, -1, -1, -1, -1, 8, -1,
				   4, 0, 8, -1, -1, -1, -1, 11, -1,
				   -1, 8, 0, 7, -1, 4, -1, -1, 2,
				   -1, -1, 7, 0, 9, 14, -1, -1, -1,
				   -1, -1, -1, 9, 0, 10, -1, -1, -1,
				   -1, -1, 4, 14, 10, 0, 2, -1, -1,
				   -1, -1, -1, -1, -1, 2, 0, 1, 6,
				   8, 11, -1, -1, -1, -1, 1, 0, 7,
				   -1, -1, 2, -1, -1, -1, 6, 7, 0,
};

typedef struct edge {  //���� ������ ���� ����ü 
	int weight; //���� ����ġ 
	int v1;  //����1
	int v2;  //����2
}Edge;

int parent[MAX];  //vertex�� �ִ� ������ 100������ ����, input_graph�� ��� vertex=9
Edge edge_set[MAX];  //��ȿ�� ������ �����ϱ� ���� Edge����ü�� �迭�� ����

void init_set(int n) {  //parent �迭�� -1(root node)�� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int find(int vertex) {   //parent node�� ã�� �Լ� , �ر���Ģ ��� x 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	else {
		return parent[vertex] = find(parent[vertex]);
	}
}
                               
void do_union(int v1, int v2) {  // 0  3  
	if (v1 > v2) {
		int temp = v1;
		v1 = v2;
		v2 = temp;
	}

	if (parent[v1] <= parent[v2]) {  //���� v1 �迭�� �� ���� ���Ҹ� ���� ��(�����ϱ� �ݴ��)
		//-4   -2
		//int temp = parent[v2];  //parent[v2] �� �ӽ� ����
		parent[v1] += parent[v2];  //parent[v1]�� ���Ұ� �߰� 
		parent[v2] = v1;  //���� v2 node�� ����v1�� �θ�� ���� 
	}
	else {  //���� v2 �迭�� �� ���� ���Ҹ� ���� �� 
		//-2   -4
		//int temp = parent[v1];
		parent[v2] += parent[v1];  
		parent[v1] = v2;
	}
}

void set_Edge(int* Graph, int n) {
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (graph[i][j] != -1) {  //����ġ�� ��ȿ�� ���̶��
				edge_set[idx].weight = graph[i][j];  //����ġ 
				edge_set[idx].v1 = i;   //���� 1
				edge_set[idx].v2 = j;   //���� 2
				idx++;
			}
			
		}
	}
}


int main(void) {
	set_Edge(graph, 9);

}