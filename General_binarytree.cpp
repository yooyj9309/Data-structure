#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node * treeptr;
typedef struct node
{
	int level;
	int key;
	char Ckey[7];
	treeptr leftC;
	treeptr rightS;
};
typedef struct binary *Btree;
typedef struct binary
{
	int key;
	Btree L_child, R_child;
};

void binary(treeptr * root, int level, int key, char * Ckey);
void preorder(Btree ptr);
Btree copy(treeptr original);
treeptr search(treeptr tree, int level, int key);

/*
This program is to change general tree to binary tree.
Read a general tree from tree1,2 files ,then connecting node.
If same level, link rightchild (R_child).
After complete to make binary tree,then copy key, leftchild, rightchild
Finally print binary tree in preorder.
input: root's address, key, level and Childkey's address
output : not return value.
*/
void main()
{
	treeptr root = NULL;
	treeptr * rootptr = &root;

	Btree btree;

	int key, level;
	char child[7];

	FILE *fp;

	fp = fopen("tree2.txt", "r");

	if (fp == NULL)
	{
		printf(" Error !");
		exit(1);
	}

	while (fscanf(fp, "%d %d %s", &level, &key, child) != EOF)
	{
		binary(rootptr, key, level, child);
	}
	btree = copy(root);
	preorder(btree);
	fclose(fp);
}
/*
This function is to change general tree to binary tree.
First, make new node(ptr) then insert general tree data in the new node.
Search whether the node is root or not.
If it is not root , then connecting leftchild(condition : same) or rightsibling(condition : another)

input : root's address, key, level and Childkey's address
output : not return value.
*/
void binary(treeptr * root, int key, int level, char * childkey)
{
	treeptr ptr;
	treeptr temp;
	ptr = (treeptr)malloc(sizeof(*ptr));

	if (ptr == NULL)
	{
		printf("Error : Not success malloc \n");
		exit(1);
	}
	ptr->key = key;
	ptr->level = level;
	strcpy(ptr->Ckey, childkey);
	ptr->leftC = ptr->rightS = NULL;
	temp = search((*root), level, key);

	if (temp != NULL)
	{
		if (temp->level + 1 == level && atoi(temp->Ckey) == key)
			temp->leftC = ptr;

		if (temp->level == level)
			temp->rightS = ptr;
	}
	else
		(*root) = ptr;
}
/*
This function is to display key in preorder.([order] = Parent key -> left key ->  right key)
input : node's address
output :print data(key in preorder)
*/
void preorder(Btree ptr)
{
	if (ptr)
	{
		printf("%d \n", ptr->key);
		preorder(ptr->L_child);
		preorder(ptr->R_child);
	}
}
/*
This function is copying linked tree excepted childkey and level in binary tree and then return copied root's address.
input : original's tree root's address
output : return copied's tree root's address

*/
Btree copy(treeptr original)
{
	Btree temp;
	if (original != NULL)
	{
		temp = (Btree)malloc(sizeof(*temp));


		temp->key = original->key;
		temp->L_child = copy(original->leftC);
		temp->R_child = copy(original->rightS);

		return temp;
	}

	return NULL;
}
/*
This function is searching function.
With searching return node's address.
input : tree's address, key, level
output : traverse node and return node's address

*/
treeptr search(treeptr tree, int level, int key)
{

	treeptr leftmove;
	treeptr tmp;

	if (level == 1)
	{
		if (tree == NULL)
			return NULL;
		else
			return tree;
	}
	else
	{
		while (1)
		{
			if (tree->level == (level - 1))
			{
				if (atoi(tree->Ckey) == key)
					return tree;

				if (tree->leftC != NULL && tree->rightS != NULL)
					leftmove = tree->leftC;
				if (tree->rightS != NULL)
					tree = tree->rightS;
				else
				{
					if (tree->leftC == NULL)
					{
						tree = leftmove;
					}
					else
						tree = tree->leftC;
				}
			}
			else if (tree->level == level)
			{
				tmp = tree;
				tree = tree->rightS;
				if (tree == NULL)
					return tmp;
			}
			else
			{
				if (tree->leftC != NULL)
					tree = tree->leftC;
				else
					tree = tree->rightS;
			}
		}
	}

}