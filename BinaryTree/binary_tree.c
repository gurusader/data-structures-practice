#include <stdlib.h>
#include "binary_tree.h"
#include <stdio.h>

Tree* makeTree(Data data)
{
	Tree* new_tree = (Tree*)malloc(sizeof(Tree));
	new_tree->data = data;
	new_tree->left = NULL;
	new_tree->right = NULL;
	return new_tree;
}

Data getData(Tree* p_tree)
{
	return p_tree->data;
}

void setData(Tree* p_tree, Data data)
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
	else
	{
		printf("%d ", p_tree->data);
		preorderTraverse(p_tree->left);
		preorderTraverse(p_tree->right);
	}
}

void deleteTree(Tree* p_tree)
{
	if (p_tree == NULL)
	{
		return;
	}
	else
	{
		deleteTree(p_tree->left);
		deleteTree(p_tree->right);
		free(p_tree);
	}
}
