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


int find(int vertex) {   //root node(��ǥ��)�� ã�� �Լ� , �ر���Ģ ��� x 
	if (parent[vertex] < 0) {  //based condition
		return parent[vertex];
	}
	//based condition�� ������ �� ���� ��� ȣ�� 
	else {
		return find(parent[vertex]);  
	}
}  
               
//���� v1, v2 ������ �պ��ϴ� �Լ� 
void set_union(int v1, int v2) {   
	if ((parent[v1] < 0 && parent[v2] <  0)) {  //�θ� ��尡 root node(����)�� ��� 
		if (parent[v1] <= parent[v2]) {   //  ex) -4  <=  -1  
			parent[v1] += parent[v2];   // �����̹Ƿ� ���� �� �������� ������ ������ �� ����.
			parent[v2] = v1;           //������ ������ �������� ū������ �պ�   
		}
		else {  // v2 ������ v1 ���պ��� ���� ��� 
			parent[v2] += parent[v1];  //������ ������ ���� v1������ v2�������� �պ�(v2������ v1�� ��) 
			parent[v1] = v2;
		}
	}
	else if ((parent[v1] >= 0) && (parent[v2] < 0)) { // ���� v1 = root node�� �ƴϰ�
		                                              // ���� v2 = root node�� ��� 	
		int p1 = find(v1);    // ���� v1�� ���� ������ root node(��ǥ��)�� ã�� 

		if (p1 <= parent[v2]) {  // v1 ������ ���� ������ v2 ���պ��� ���ų� ���� ��� 
			parent[parent[parent[v1]]] += parent[v2]; //������ ������ ���� v2 ������ v1�������� �պ� 
			parent[v2] = v1;
		}
		else {   //v2 ������ v1 ���պ��� ���� ��� 
			parent[parent[parent[v2]]] += parent[v1]; //������ ������ ���� v1 ������ v2 �������� �պ� 
			parent[v1] = v2;
		}
	}

	else if ((parent[v1] < 0) && (parent[v2] >= 0)) { // ���� v1 = root node�̰� 
		                                              // ���� v2 = root node�� �ƴ� ��� 
		int p2 = find(v2) ;   // ���� v2�� ���� ������ ��Ʈ ���(��ǥ��)�� ã�� 

		if (p2 <= parent[v1]) {  //v2 ������ v1������ �������� ���ų� ���� ��
			parent[parent[v2]] += parent[v1];  //������ ���� v1������ v2�������� �պ�
			parent[v1] = v2;
		}
		else {  //v1 ������ v2 ���պ��� ���� ��� 
			parent[parent[v1]] += parent[v2];   //������ ���� v2������ v1�������� �պ�(v2�� v1������ ��)
			parent[v2] = v1; 
		}
	}

	else if((parent[v1] >= 0) && (parent[v2] >= 0)) {  //���� v1, v2 ��� root node �� ��� 
		int p1 = find(v1);  //���� v1�� ���� ������ root node�� ã��
		int p2 = find(v2);  //���� v2�� ���� ������ root node�� ã�� 
		if (p2 <= p1) {   //�������� ���ϹǷ� �������� �� ���� ���� ���� ���� 
			parent[parent[parent[v2]]] += parent[parent[v1]];  //������ ���� v1������ v2�������� �պ�
			parent[parent[v1]] = v2;               
		}
		else {  // p2 > p1  --> v1�� ���� ������ node������ v2���պ��� ����
			parent[parent[v1]] += parent[v2];  //.������ ���� v2������ v1�������� �պ� 
			parent[v2] = v1;
		}
	}

	//�θ� ����� ���¸� union �� ������ �˾ƺ� �� �ְ� ��� 
	printf("Parent node --->");   
	for (int i = 0; i < 9; i++) { 	
		printf("%4d", parent[i]);
	}
	printf("\n");
	printf("\n");
}

int set_Edge(int n) { //���������Ŀ��� ��ȿ�� ���鸸 ������� edge_set(�迭)�� ���� 
	int idx = 0;   //�ʿ��� ������ �� return �����ֱ� ���� �� 
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {  //������������ ��Ī���(���� �ﰢ���� ����) 
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

	if (e1->weight < e2->weight) return -1;   // e1����ġ�� e2����ġ���� ���� ��� -1
	if (e1->weight > e2->weight) return 1;    // e1����ġ�� e2����ġ���� Ŭ ��� 1 
	return 0;  // ����ġ�� ���� ��� 0 
}

void kruskal(int n, int edge_count) {  //minimum Spanning Tree �Լ�, �ּ� ����� ���ϱ� ���� �Լ� 
	int mst_e = 0; //�ּ� ����� ���� 
	int mst_e_count = 0;  //�ּ� ��� ���� Ʈ���� �߰��� ���� �� ���� 
	qsort(edge_set, edge_count, sizeof(Edge), compare); //������ �迭, ��Ұ���, ���ũ��, ���Լ�
	init_set(n); //parent node �迭�� -1�� �ʱ�ȭ 

	for (int i = 0; mst_e_count < n - 1; i++) {  //edge = vertex-1
		//������������ �̿��Ͽ� ������ ����ü �迭 edge_set �� �̿��Ͽ� ���� 1,2�� root node find  
		int x = find(edge_set[i].v1);  
		int y = find(edge_set[i].v2);  
		printf("vertex %d�� root node : %d\n", edge_set[i].v1, x);  //������ �ĺ��ϰ� ��ǥ�� �ĺ� 
		printf("vertex %d�� root node : %d\n", edge_set[i].v2, y);
		
		if ((x == -1 && y == -1) || x != y) {  //�ʱ������ ���(-1)�� �պ� union ����
			printf("Edge(%d, %d) �߰�\n", edge_set[i].v1, edge_set[i].v2);
			mst_e += edge_set[i].weight;   //�� ����ġ ��� 
			mst_e_count++;   //mst���� ������ ������ ����-1�̹Ƿ� ������ ����-1�� �Ǹ� break;
			set_union(edge_set[i].v1, edge_set[i].v2);   //���ǿ� ������ �ΰ��� ���� union 

		}
	}
	printf("Total weight : %d\n", mst_e);  //MST�� �����ϴµ� �ʿ��� ������ ����ġ�� �� 


}


int main(void) {
	int edge = set_Edge(9);  //��� ���� ��ķκ��� ������� ��ȿ�� ������ �� return 
	kruskal(9, edge);  //���ڷ� input_graph�� ���� ����, ������ ���� ���� 
}