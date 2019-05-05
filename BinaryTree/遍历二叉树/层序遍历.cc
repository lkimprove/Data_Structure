//利用C++中已定义好的队列
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

//创建树
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

//层序遍历
void Level_Order(Node* root){
	//判空
	if (root == NULL){
		return;
	}
	//创建一个成员都是 Node* 的队列
	std::queue<Node*> q;
	//层序遍历
	q.push(root);
	while (!q.empty()){
		//取出队首元素
		Node* front = q.front();
		//删除队首元素并打印
		q.pop();
		printf("%c ", front->value);
		//如果左右子树不为空，则将其入队
		if (front->left != NULL){
			q.push(front->left);
		}
		if (front->right != NULL){
			q.push(front->right);
		}
	}
}

//测试
void Test(){
	//创建树
	Node* root = CreateTree();
	//层序遍历
	Level_Order(root);
}

int main(){
	//测试
	Test();

	system("pause");
	return 0;
}