#pragma once

typedef int BinaryTreeData;
typedef BinaryTreeData Data;

typedef struct _BinaryTree
{
	Data data;
	struct _BinaryTree* left;
	struct _BinaryTree* right;
} BinaryTree;

typedef BinaryTree Tree;

Tree* makeTree(Data data);

Data getData(Tree* p_tree);
void setData(Tree* p_tree, Data data);

Tree* getLeftSubTree(Tree* p_tree);
void setLeftSubTree(Tree* p_tree_parent, Tree* p_tree_child);

Tree* getRightSubTree(Tree* p_tree);
void setRightSubTree(Tree* p_tree_parent, Tree* p_tree_child);

void preorderTraverse(Tree* p_tree);
void deleteTree(Tree* p_tree);
