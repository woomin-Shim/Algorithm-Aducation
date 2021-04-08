#include <stdio.h>
#include <stdlib.h>   // �������� ����ϱ� ���� ������� 
#define MAX 100

//��� ���� ���(����ġ�� ��Ÿ��)
int graph[9][9] = { {0, 4, -1, -1, -1, -1, -1, 8, -1},
					{4, 0, 8, -1, -1, -1, -1, 11, -1},
					{-1, 8, 0, 7, -1, 4, -1, -1, 2},
					{-1, -1, 7, 0, 9, 14, -1, -1, -1},
                    {-1, -1, -1, 9, 0, 10, -1, -1, -1},
	                {-1, -1, 4, 14, 10, 0, 2, -1, -1},
                    {-1, -1, -1, -1, -1, 2, 0, 1, 6},
                    {8, 11, -1, -1, -1, -1, 1, 0, 7},
					{-1, -1, 2, -1, -1, -1, 6, 7, 0},
};

typedef struct edge {  //���� ������ ���� ����ü 
	int weight; //���� ����ġ 
	int v1;  //����1
	int v2;  //����2
}Edge;

int parent[MAX];  //vertex�� �ִ� ������ 100������ ����, input_graph�� ��� vertex=9
Edge edge_set[MAX];  //��ȿ�� ������ �����ϱ� ���� Edge����ü�� �迭�� ����

void init_set(int n) {  //������ �ʱ� ���·� setting
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = -1;  //parent �迭�� -1(root node)�� �ʱ�ȭ
		
	}
}


int find(int vertex) {   //parent node�� ã�� �Լ� , �ر���Ģ ��� x 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	else {
		return find(parent[vertex]);
	}
}  

/*
int find(int vertex) {
	int p, s, i = 0;
	for (i = vertex; (p = parent[i]) > 0; i = p)
		;
	s = i;
	return s;
}    */
                               
void set_union(int v1, int v2) {   
	printf("%d\n", parent[8]);
	printf("%d  %d\n", v1, v2);
	printf("%d  %d\n", parent[v1], parent[v2]);
	if ((parent[v1] < 0 && parent[v2] <  0)) {  //�θ� ��尡 �ʱ� ���(-1)�̶�� 
		if (parent[v1] <= parent[v2]) {
			parent[v1] += parent[v2];
			parent[v2] = v1;
		}
		else {
			parent[v2] += parent[v1];
			parent[v1] = v2;
		}
		printf("xxxx\n");
	}
	else if ((parent[v1] >= 0) && (parent[v2] < 0)) { // ���� v1 ������ ��Ʈ ��尡 �ƴҶ�
		int p1, p2;
		
		p1 = find(v1);   // ���� v1�� ���� ��Ʈ ��带 ã�� 
		p2 = parent[v2];
		printf("%d %d\n", p1, p2);
		if (p1 <= p2) {  //�����ϱ� �ݴ�� 
			parent[parent[parent[v1]]] += parent[v2];
			parent[v2] = v1;
		}
		else {   // (p1 > p2) 
			parent[parent[v2]] += parent[v1];
			parent[v1] = v2;
		}
	}

	else if ((parent[v1] < 0) && (parent[v2] >= 0)) { // ���� v1 ������ ��Ʈ ��尡 �ƴҶ�
		int p1, p2;
		p2 = find(v2) ;   // ���� v1�� ���� ��Ʈ ��带 ã�� 
		printf("%d\n", p2);
		p1 = parent[v1];
		if (p2 <= p1) {
			parent[parent[v2]] += parent[v1];
			parent[v1] = v2;
		}
		else {
			parent[parent[v1]] += parent[v2];
			parent[v2] = v1;
		}
	}

	else if((parent[v1] >= 0) && (parent[v2] >= 0)) {
		int p1 = find(v1);
		int p2 = find(v2);
		if (p2 <= p1) {
			parent[parent[parent[v2]]] += parent[parent[v1]];
			parent[parent[v1]] = v2;
		}
		else {
			parent[parent[v1]] += parent[v2];
			parent[v2] = v1;
		}
	}

	
	



	/*
	if (parent[v1] <= parent[v2]) {  //���� v1 �迭�� �� ���� ���Ҹ� ���� ��(�����ϱ� �ݴ��)
		//-4   -2
		//int temp = parent[v2];  //parent[v2] �� �ӽ� ����
		parent[v1] += parent[v2];  //parent[v1]�� ���Ұ� �߰� 
		parent[v2] = v1;  //���� v2 node�� ����v1�� �θ�� ���� 
	}
	else {  //���� v2 �迭�� �� ���� ���Ҹ� ���� �� 
		//1   -1
		//int temp = parent[v1];
		parent[v2] += parent[v1];  
		parent[v1] = v2;
	}
	*/

	for (int i = 0; i < 9; i++) {
		printf("%3d", parent[i]);
	}
	printf("\n");

	printf("\n");
}

int set_Edge(int n) { //���������Ŀ��� ��ȿ�� ���鸸 ������� edge_set(�迭)�� ���� 
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {  //������������ ��Ī���
			if (graph[i][j] > 0) {  //����ġ�� ��ȿ�� ���̶��
				edge_set[idx].weight = graph[i][j];  //����ġ 
				edge_set[idx].v1 = i;   //���� 1
				edge_set[idx].v2 = j;   //���� 2
				idx++;
			}
			
			
		}
	}
	return idx;
}

int compare(const void* a, const void* b) {  //quicksort���� ���� �� �Լ�
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;

	if (e1->weight < e2->weight) return -1;
	if (e1->weight > e2->weight) return 1;
	return 0;
}

void kruskal(int n, int edge_count) {  //minimum Spanning Tree �Լ�, �ּ� ����� ���ϱ� ���� �Լ� 
	int mst_e = 0; //�ּ� ����� ���� 
	int mst_e_count = 0;  //�ּ� ��� ���� Ʈ���� �߰��� ���� �� ���� 
	qsort(edge_set, edge_count, sizeof(Edge), compare); //������ �迭, ��Ұ���, ���ũ��, ���Լ�
	init_set(n); //parent node �迭�� -1�� �ʱ�ȭ 

	for (int i = 0; mst_e_count < n - 1; i++) {  //edge = vertex-1
		int x = find(edge_set[i].v1);
		int y = find(edge_set[i].v2);
		printf("%d : %d, %d : %d\n", edge_set[i].v1, x, edge_set[i].v2, y);

		if ((x == -1 && y == -1) || x != y) {
			printf("���� (%d, %d) �߰�\n", edge_set[i].v1, edge_set[i].v2);
			mst_e += edge_set[i].weight;
			mst_e_count++;
			set_union(edge_set[i].v1, edge_set[i].v2);

		}
	}
	printf("�ּ� ����� %d �Դϴ�.\n", mst_e);


}


int main(void) {
	int edge = set_Edge(9);  //��� ���� ��ķκ��� ������� ��ȿ�� ������ ��(����Ŭ ����) return 
	printf("%d\n", edge);
	kruskal(9, edge);
}