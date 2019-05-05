#include<stdlib.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	char value;
};

//�������
Node* CreateNode(char value){
	Node* node = (Node*)malloc(sizeof(Node));
	node->left = node->right = NULL;
	node->value = value;
	return node;
}

//����һ��δ֪ A ��
Node* CreateTree_A(){
	Node* a = CreateNode('A');
	Node* b = CreateNode('B');
	Node* c = CreateNode('C');
	Node* d = CreateNode('D');
	Node* e = CreateNode('E');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	return a;
}

//����һ��δ֪ B ��
Node* CreateTree_B(){
	Node* a = CreateNode('A');
	Node* b = CreateNode('B');
	Node* c = CreateNode('C');
	Node* d = CreateNode('D');
	Node* e = CreateNode('E');

	a->left = b; a->right = c;
	b->left = d; c->right = e;
	return a;
}

//�ж���ȫ������
bool IsComplete(Node* root){
	//�п�
	if (root == NULL){
		return true;
	}
	//����һ������
	std::queue<Node*> q;
	q.push(root);
	//�������
	while (1){
		Node* front = q.front();
		q.pop();
		if (front == NULL){
			break;
		}
		q.push(front->left);
		q.push(front->right);
	}
	//�ж϶������Ƿ��зǿս��
	while (!q.empty()){
		Node* front = q.front();
		q.pop();
		if (front != NULL){
			return false;
		}
	}
	return true;
}

//����
void Test(){
	Node* A_root = CreateTree_A();
	Node* B_root = CreateTree_B();
	if (IsComplete(A_root)){
		printf(" A ����һ����ȫ��������\n");
	}
	else {
		printf(" A ������һ����ȫ��������\n");
	}
	if (IsComplete(B_root)){
		printf(" B ����һ����ȫ��������\n");
	}
	else {
		printf(" B ������һ����ȫ��������\n");
	}
}

int main(){
	//����
	Test();
	system("pause");
	return 0;
}