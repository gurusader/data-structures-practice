#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main()
{
	Tree* p_tree = makeTree(1);
	setLeftSubTree(p_tree, makeTree(2));
	setRightSubTree(p_tree, makeTree(3));

	preorderTraverse(p_tree);
	puts("");

	setLeftSubTree(p_tree, makeTree(4));
	setRightSubTree(p_tree, makeTree(5));

	preorderTraverse(p_tree);
	puts("");

	deleteTree(p_tree);

	system("pause");

	return 0;
}
