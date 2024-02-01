#include "binarytrees.h"

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if the binary tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height, perfect_check1, perfect_check2;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (tree->left == NULL || tree->right == NULL)
		{
			return (1);
		}
		else
		{
			perfect_check1 = binary_tree_is_perfect(tree->left);
			perfect_check2 = binary_tree_is_perfect(tree->right);
			return (perfect_check1 && perfect_check2);
		}
	}

	return (0);
}
