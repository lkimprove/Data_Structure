//����C++���Ѷ���õĶ���
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

//������
Node* CreateTree(){
	Node* a = CreateNode('A');
	Node* b = CreateNode('B');
	Node* c = CreateNode('C');
	Node* d = CreateNode('D');
	Node* e = CreateNode('E');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	return a;
}

//�������
void Level_Order(Node* root){
	//�п�
	if (root == NULL){
		return;
	}
	//����һ����Ա���� Node* �Ķ���
	std::queue<Node*> q;
	//�������
	q.push(root);
	while (!q.empty()){
		//ȡ������Ԫ��
		Node* front = q.front();
		//ɾ������Ԫ�ز���ӡ
		q.pop();
		printf("%c ", front->value);
		//�������������Ϊ�գ��������
		if (front->left != NULL){
			q.push(front->left);
		}
		if (front->right != NULL){
			q.push(front->right);
		}
	}
}

//����
void Test(){
	//������
	Node* root = CreateTree();
	//�������
	Level_Order(root);
}

int main(){
	//����
	Test();

	system("pause");
	return 0;
}