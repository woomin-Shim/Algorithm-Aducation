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

int count[MAX]; //parent node�� ������ node ������ ���� �����ϱ� ���� Array 
int parent[MAX];  //vertex�� �ִ� ������ 100������ ����, input_graph�� ��� vertex=9
Edge edge_set[MAX];  //��ȿ�� ������ �����ϱ� ���� Edge����ü�� �迭�� ����


void init_set(int n) {  //parent �迭�� count �迭 �ʱ� ���·� setting
	int i;
	for (i = 0; i < n; i++) {
		parent[i] = i;  //parent node���� -1�� �ƴ� ���� �ڱ� �ε����� ����Ű���� ����
		count[i] = 1;   //�ʱ� ���¿��� node���� ��� ������ node �ϳ����� ������ ���� 
	}

}


int find(int vertex) {   //root node�� ã�� �Լ� 
	if (parent[vertex] == vertex) {  //based condition
		return parent[vertex];     //�ڽ��� �ε����� ����Ű�� return 
	}
	else {
		parent[vertex] = find(parent[vertex]);   //based condition �� �����Ҷ����� �ݺ� 
	}
}

//���� v1, v2 ������ �պ��ϴ� �Լ� 
void set_union(int v1, int v2) {
	int p1 = find(v1);  //���� v1�� ���� ������ root node find
	int p2 = find(v2);  //���� v2�� ���� ������ root node find 
	if (count[p1] < count[p2]) {  //v1 ������ node ������ v2 ���� ���ų� ������
		parent[p1] = p2;  // �ٷ� ���� parent node�� �ƴ� root node�� ���� (collapsing Rule) 
		parent[v1] = p2;  // �ڽĵ鵵 root node�� ���� 
		count[p2] += count[v1];  //count �迭�� root node index�� ������ node ���� �߰� 
	}
	else {   //v1 ������ node ������ v2 ���� ���� ��� 
		parent[p2] = p1;  //�ٷ� �� parent node�� �ƴ� root node�� ����
		parent[v2] = p1;  //root node(p2)�� ���տ� �ҼӵǾ��ִ� node�鵵 root node�� ���� 
		count[p1] += count[v2]; //count �迭�� root node index�� ������ node ���� �߰� 
	}


	//�θ� ����� ���¸� union �� ������ �˾ƺ� �� �ְ� ��� 
	printf(" Root ------>");
	for (int i = 0; i < 9; i++) {   
		printf("%4d", parent[i]);
	}
	printf("\n");

	//count ����� ���¸� union �� ������ �˾ƺ� �� �ְ� ��� 
	printf("Count ------>");
	for (int i = 0; i < 9; i++) {
		printf("%4d", count[i]);
	}
	printf("\n");
	printf("\n");
}

int set_Edge(int n) { //���������Ŀ��� ��ȿ�� ���鸸 ������� edge_set(�迭)�� ���� 
	int idx = 0;   //�ʿ��� ������ �� return �����ֱ� ���� �� 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {  //������������ ��Ī���
			if (graph[i][j] > 0) {  //����ġ�� ��ȿ�� ���̶��
				edge_set[idx].weight = graph[i][j];  //����ġ 
				edge_set[idx].v1 = i;   //���� 1
				edge_set[idx].v2 = j;   //���� 2
				idx++;
			}
		}
	}
	return idx;  //��ȿ�� ������ ��
}

int compare(const void* a, const void* b) {  //quicksort���� ���� �� �Լ�
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;

	if (e1->weight < e2->weight) return -1;    // e1����ġ�� e2����ġ���� ���� ��� -1
	if (e1->weight > e2->weight) return 1;     // e1����ġ�� e2����ġ���� Ŭ ��� 1
	return 0;   // ����ġ�� ���� ��� 0 
}

void kruskal(int n, int edge_count) {  //minimum Spanning Tree �Լ�, �ּ� ����� ���ϱ� ���� �Լ� 
	int mst_e = 0; //�ּ� ����� ���� 
	int mst_e_count = 0;  //�ּ� ��� ���� Ʈ���� �߰��� ���� �� ���� 
	qsort(edge_set, edge_count, sizeof(Edge), compare); //������ �迭, ��Ұ���, ���ũ��, ���Լ�
	init_set(n); //parent node �迭�� index������ �ʱ�ȭ, count �迭 1�� setting 


	//�� ó�� ������ parent node print
	printf("�ʱ� root node ---->");
	for (int i = 0; i < 9; i++) {
		printf("%4d", parent[i]);
	}
	printf("\n");
	printf("\n");

	for (int i = 0; mst_e_count < n - 1; i++) {  //edge = vertex-1
		//������������ ���ĵ� edge_set ����ü�� �̿� root node�� ã�� 
		int x = find(edge_set[i].v1);
		int y = find(edge_set[i].v2);
		printf("vertex %d�� root node : %d\n", edge_set[i].v1, x);  //������ �ĺ��ϰ� ��ǥ�� �ĺ� 
		printf("vertex %d�� root node : %d\n", edge_set[i].v2, y);

		if (x != y) {   //�� ���� root node ���� �ٸ� ��� union ���� 
			printf("Edge(%d, %d) �߰�\n", edge_set[i].v1, edge_set[i].v2);
			mst_e += edge_set[i].weight;   //�� ������ ����ġ�� ���� �ּ� ��� ����
			mst_e_count++;  //mst�� �̷�µ� �ʿ��� ���� 
			set_union(edge_set[i].v1, edge_set[i].v2);  //�� ���� ������ ���� ���� �պ� 
		}
	}
	printf("Total weight : %d\n", mst_e);   //MST �� �ʿ��� ����ġ 
}


int main(void) {
	int edge = set_Edge(9);  //��� ���� ��ķκ��� ������� ��ȿ�� ������ ��(����Ŭ ����) return 
	kruskal(9, edge); //input_graph�� ������ ������ ������ ���ڷ� ���� 
}