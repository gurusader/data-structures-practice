#pragma once

typedef int TreeData;

typedef struct _BinaryTree
{
	TreeData data;
	struct _BinaryTree* left;
	struct _BinaryTree* right;
} BinaryTree;

typedef BinaryTree Tree;

Tree* makeTree(TreeData data);

TreeData getTreeData(Tree* p_tree);
void setTreeData(Tree* p_tree, TreeData data);

Tree* getLeftSubTree(Tree* p_tree);
void setLeftSubTree(Tree* p_tree_parent, Tree* p_tree_child);

Tree* getRightSubTree(Tree* p_tree);
void setRightSubTree(Tree* p_tree_parent, Tree* p_tree_child);

void preorderTraverse(Tree* p_tree);
void deleteTree(Tree* p_tree);
