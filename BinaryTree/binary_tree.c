#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Tree* makeTree(TreeData data)
{
	Tree* new_tree = (Tree*)malloc(sizeof(Tree));
	new_tree->data = data;
	new_tree->left = NULL;
	new_tree->right = NULL;
	return new_tree;
}

TreeData getTreeData(Tree* p_tree)
{
	return p_tree->data;
}

void setTreeData(Tree* p_tree, TreeData data)
{
	p_tree->data = data;
}

Tree* getLeftSubTree(Tree* p_tree)
{
	return p_tree->left;
}

void setLeftSubTree(Tree* p_tree_parent, Tree* p_tree_child)
{
	if (p_tree_parent->left != NULL)
	{
		deleteTree(p_tree_parent->left);
	}

	p_tree_parent->left = p_tree_child;
}

Tree* getRightSubTree(Tree* p_tree)
{
	return p_tree->right;
}

void setRightSubTree(Tree* p_tree_parent, Tree* p_tree_child)
{
	if (p_tree_parent->right != NULL)
	{
		deleteTree(p_tree_parent->right);
	}

	p_tree_parent->right = p_tree_child;
}

void preorderTraverse(Tree* p_tree)
{
	if (p_tree == NULL)
	{
		return;
	}

	printf("%d ", p_tree->data);
	preorderTraverse(p_tree->left);
	preorderTraverse(p_tree->right);
}

void deleteTree(Tree* p_tree)
{
	if (p_tree == NULL)
	{
		return;
	}

	deleteTree(p_tree->left);
	deleteTree(p_tree->right);
	free(p_tree);
}
