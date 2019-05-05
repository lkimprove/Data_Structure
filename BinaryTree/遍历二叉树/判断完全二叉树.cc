#include<stdlib.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	char value;
};

//创建结点
Node* CreateNode(char value){
	Node* node = (Node*)malloc(sizeof(Node));
	node->left = node->right = NULL;
	node->value = value;
	return node;
}

//创建一颗未知 A 树
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

//创建一颗未知 B 树
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

//判断完全二叉树
bool IsComplete(Node* root){
	//判空
	if (root == NULL){
		return true;
	}
	//创建一个队列
	std::queue<Node*> q;
	q.push(root);
	//层序遍历
	while (1){
		Node* front = q.front();
		q.pop();
		if (front == NULL){
			break;
		}
		q.push(front->left);
		q.push(front->right);
	}
	//判断队列中是否还有非空结点
	while (!q.empty()){
		Node* front = q.front();
		q.pop();
		if (front != NULL){
			return false;
		}
	}
	return true;
}

//测试
void Test(){
	Node* A_root = CreateTree_A();
	Node* B_root = CreateTree_B();
	if (IsComplete(A_root)){
		printf(" A 树是一颗完全二叉树！\n");
	}
	else {
		printf(" A 树不是一颗完全二叉树！\n");
	}
	if (IsComplete(B_root)){
		printf(" B 树是一颗完全二叉树！\n");
	}
	else {
		printf(" B 树不是一颗完全二叉树！\n");
	}
}

int main(){
	//测试
	Test();
	system("pause");
	return 0;
}