#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结点结构体
typedef struct Node{
	struct Node* left;
	struct Node* right;
	char value;
}Node;

//确定左子树长度
int Find(char inorder[], int size, char value){
	for (int i = 0; i < size; i++){
		if (inorder[i] == value){
			return i;
		}
	}
	return -1;
}

//根据前序序列和中序序列创建二叉树
Node* CreateTree_P_I(char preorder[], char inorder[], int size){
	//终止条件
	if (size == 0){
		return NULL;
	}
	//根据前序序列找到根结点
	char root_value = preorder[0];
	//根据根结点在中序序列中确定左子树的长度
	int left_size = Find(inorder, size, root_value);
	//创建根结点
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = root_value;
	//创建左子树
	root->left = CreateTree_P_I(
		preorder + 1,	//左子树的前序
		inorder,	//左子树的中序
		left_size	//左子树的长度
		);
	//创建右子树
	root->right = CreateTree_P_I(
		preorder + 1 + left_size,	//右子树的前序
		inorder + left_size + 1,//右子树的中序
		size - left_size - 1//右子树的长度
		);
	//返回根
	return root;
}

//后序遍历打印二叉树
void Print_PostOrder(Node* root){
	if (root != NULL){
		Print_PostOrder(root->left);
		Print_PostOrder(root->right);
		printf("%c ", root->value);
	}
}

//测试 前序 + 中序  --> 后序打印二叉树
void Test_P_I(){
	//前序序列
	char preorder[] = "ABDCEF";
	//中序序列
	char inorder[] = "DBAECF";
	//结点个数
	int size = strlen(preorder);
	//根据前序序列和中序序列创建树
	Node* root = CreateTree_P_I(preorder, inorder, size);
	//根据后序遍历打印二叉树
	Print_PostOrder(root);
}



//根据中序序列和后序序列创建二叉树
Node* CreateTree_I_P(char inorder[], char postorder[], int size){
	//终止条件
	if (size == 0){
		return NULL;
	}
	//根据后序序列找到根结点
	char root_value = postorder[size - 1];
	//根据中序序列确定左子树长度
	int left_size = Find(inorder, size, root_value);
	//创建根结点
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = root_value;
	//创建左子树
	root->left = CreateTree_I_P(
		inorder,	//左子树的中序
		postorder,	//左子树的后序
		left_size	//左子树长度
		);
	//创建右子树
	root->right = CreateTree_I_P(
		inorder + left_size + 1,	//右子树的中序
		postorder + left_size,	//右子树的后序
		size - left_size - 1	//右子树的长度
		);
	//返回根
	return root;
}

//根据前序遍历打印二叉树
void Print_PreOrder(Node* root){
	if (root != NULL){
		printf("%c ", root->value);
		Print_PreOrder(root->left);
		Print_PreOrder(root->right);
	}
}

//测试 中序 + 后序 --> 前序打印二叉树
void Test_I_P(){
	//中序序列
	char inorder[] = "DBAECF";
	//后序序列
	char postorder[] = "DBEFCA";
	//结点个数
	int size = strlen(inorder);
	//根据中序 + 后序 创建二叉树
	Node* root = CreateTree_I_P(inorder, postorder, size);
	//前序打印二叉树
 	Print_PreOrder(root);
}


int main(){
	printf("前序 + 中序 --> 后序打印二叉树\n");
	//测试 前序 + 中序 --> 后序打印二叉树
	Test_P_I();

	printf("\n中序 + 后序 --> 前序打印二叉树\n");
	//测试 中序 + 后序 --> 前序打印二叉树
	Test_I_P();

	printf("\n");
	system("pause");
	return 0;
}
