#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ṹ��
typedef struct Node{
	struct Node* left;
	struct Node* right;
	char value;
}Node;

//ȷ������������
int Find(char inorder[], int size, char value){
	for (int i = 0; i < size; i++){
		if (inorder[i] == value){
			return i;
		}
	}
	return -1;
}

//����ǰ�����к��������д���������
Node* CreateTree_P_I(char preorder[], char inorder[], int size){
	//��ֹ����
	if (size == 0){
		return NULL;
	}
	//����ǰ�������ҵ������
	char root_value = preorder[0];
	//���ݸ����������������ȷ���������ĳ���
	int left_size = Find(inorder, size, root_value);
	//���������
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = root_value;
	//����������
	root->left = CreateTree_P_I(
		preorder + 1,	//��������ǰ��
		inorder,	//������������
		left_size	//�������ĳ���
		);
	//����������
	root->right = CreateTree_P_I(
		preorder + 1 + left_size,	//��������ǰ��
		inorder + left_size + 1,//������������
		size - left_size - 1//�������ĳ���
		);
	//���ظ�
	return root;
}

//���������ӡ������
void Print_PostOrder(Node* root){
	if (root != NULL){
		Print_PostOrder(root->left);
		Print_PostOrder(root->right);
		printf("%c ", root->value);
	}
}

//���� ǰ�� + ����  --> �����ӡ������
void Test_P_I(){
	//ǰ������
	char preorder[] = "ABDCEF";
	//��������
	char inorder[] = "DBAECF";
	//������
	int size = strlen(preorder);
	//����ǰ�����к��������д�����
	Node* root = CreateTree_P_I(preorder, inorder, size);
	//���ݺ��������ӡ������
	Print_PostOrder(root);
}



//�����������кͺ������д���������
Node* CreateTree_I_P(char inorder[], char postorder[], int size){
	//��ֹ����
	if (size == 0){
		return NULL;
	}
	//���ݺ��������ҵ������
	char root_value = postorder[size - 1];
	//������������ȷ������������
	int left_size = Find(inorder, size, root_value);
	//���������
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = root_value;
	//����������
	root->left = CreateTree_I_P(
		inorder,	//������������
		postorder,	//�������ĺ���
		left_size	//����������
		);
	//����������
	root->right = CreateTree_I_P(
		inorder + left_size + 1,	//������������
		postorder + left_size,	//�������ĺ���
		size - left_size - 1	//�������ĳ���
		);
	//���ظ�
	return root;
}

//����ǰ�������ӡ������
void Print_PreOrder(Node* root){
	if (root != NULL){
		printf("%c ", root->value);
		Print_PreOrder(root->left);
		Print_PreOrder(root->right);
	}
}

//���� ���� + ���� --> ǰ���ӡ������
void Test_I_P(){
	//��������
	char inorder[] = "DBAECF";
	//��������
	char postorder[] = "DBEFCA";
	//������
	int size = strlen(inorder);
	//�������� + ���� ����������
	Node* root = CreateTree_I_P(inorder, postorder, size);
	//ǰ���ӡ������
 	Print_PreOrder(root);
}


int main(){
	printf("ǰ�� + ���� --> �����ӡ������\n");
	//���� ǰ�� + ���� --> �����ӡ������
	Test_P_I();

	printf("\n���� + ���� --> ǰ���ӡ������\n");
	//���� ���� + ���� --> ǰ���ӡ������
	Test_I_P();

	printf("\n");
	system("pause");
	return 0;
}
