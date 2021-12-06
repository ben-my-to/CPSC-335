#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct node {
	int info;
	node *left, *right;
};

struct qnode {
	node *qinfo;//each data in queue is pointing to a tree node
	qnode *next;
};

void insert(node* &p, int x)//-------------------------inserting x in BST
{
	if( p==NULL)
	{
		p = new node; p->info = x;  
		p->left = NULL; p->right = NULL;
	}
	else
	{
		if (x < p->info) insert(p->left, x);
		if (x > p->info) insert(p->right, x);
	}
}
bool emptyQueue(qnode *q)
{
	return (q == NULL) ? true : false;
}
void queuePush(qnode* &q, node *x)
{
	qnode* r = new qnode; r->qinfo = x; r->next = NULL;
	if (q == NULL) q = r;
	else
	{
		qnode* t = q;
		while (t->next != NULL) t = t->next;
		t->next = r;
	}
}
node* queuePop(qnode* &q)
{
	qnode *r = q; node *tt = r->qinfo;
	q = q->next;
	delete r;
	return tt;
}

void deleteQueue(qnode* &q)
{
	qnode* t = q;
	while (t != NULL)
	{
		q = q->next; delete t; t = q;
	}
	delete t; delete q;
}
void displayLevelLevel(node *t)//------------------------- display tree level-by-level
{
	qnode *q=NULL;
	node *temp;

	if (t==NULL) return;
	
	queuePush(q, t);
	while (!emptyQueue(q))
	{
		temp = queuePop(q);
		while (temp == NULL) continue;
		
		cout << temp->info << "  ";
		if (temp->left != NULL)
			queuePush(q, temp->left);
		if (temp->right != NULL)
			queuePush(q, temp->right);
	}
	
	deleteQueue(q);
}
void show(node* p)//----------------------------display BST using inorder traversal
{
	if (p != NULL)
	{
		show(p->left);
		cout << p->info << "  ";
		show(p->right);
	}
}



void sideWay(node* t, int s)// ------------------------------- display BST sideway
{
	if (t != NULL)
	{
		sideWay(t->right, s += 5);
		cout << setw(s) << t->info<<endl;
		sideWay(t->left, s);
	}
}

int height(node* p)//-------------------------------------- return the tree height
{
	if (p == NULL) return -1;  //for tree level return 0
	else return 1 + max(height(p->left), height(p->right));
}

void search(node* p, int x)//------------------------------------ search for item X
{
	if (p == NULL) {cout <<x<< " not found\n:"; exit(1) ; }
	else if (p->info == x) {cout <<x<<" Found\n"; exit(1) ;	}
	else
	{
		if (x < p->info) search(p->left, x);
		if (x > p->info) search(p->right, x);
	}
}
int countNodes(node* t)// ----------------------count number of nodes recursively 
{
	if (t == NULL) return 0;
	else return 1 + countNodes(t->left) + countNodes(t->right);
	//to find total of all nodes replace 1 with t->info
}
int findMaxBT(node* t) //------------------------------find the max node of a Binary Tree
{
	if (t != NULL)
             return max(t->info,	max(findMaxBT(t->left), findMaxBT(t->right)));
	else
	      return 0;
}

int findMinBST(node *t) //----------------------------------find the minimum data in BST

{
	while (t->left != NULL) t = t->left;
	return t->info;
}
int findMaxBTBST(node *t) //find the maximum data in BST

{
	while (t->right != NULL) t = t->right;
	return t->info;

}



bool sameTrees(node *t1, node *t2) //----test whether two BT are structurally the same
{
	if (t1 == NULL && t2 == NULL) return true;
	if (t1 == NULL || t2 == NULL) return false;
	//both not empty, compare them
	return (t1->info == t2->info)&&
		   sameTrees(t1->left, t2->left)&&
		   sameTrees(t1->right, t2->right);	
}
void displayPath(int p[], int len) //--------------------display all root-to-leaf paths
{
	for (int i = 0; i < len; ++i)
		cout << p[i] << " ";
	cout << endl;
}


void findPathsToLeaf(node *t, int p[], int pathLen) //----display path from root to leaf
{
	if (t == NULL) return;
	//append this node to array p
	p[pathLen] = t->info;
	pathLen++;
	//if it is a leaf, print path to here
	if (t->left == NULL && t->right == NULL)
		displayPath(p, pathLen);
	else
	{
		findPathsToLeaf(t->left, p, pathLen);
		findPathsToLeaf(t->right, p, pathLen);
	}
}
node *mirror(node *t) //---------------------------make a mirror image of a binary tree
{
	node *temp;
	if (t != NULL)
	{
		mirror(t->left);
		mirror(t->right);
		//swap the pointers
		temp = t->left;
		t->left = t->right;
		t->right = temp;
	}
	return t;
}


bool showAncestor(node* t, int target) //--display the ancestors of node with info target
{
	if (t == NULL) return false;
	if (t->info == target) return true;

	if (showAncestor(t->left, target) ||
		showAncestor(t->right, target) )
	{
		cout << t->info << " ";
		return true;
	}
	else
		return false;
}

node *findMaxBT(node* t) //----------------------return the node with max value in BST
{
	if (t == NULL) return NULL;
	else
	{
		while (t->right != NULL) t = t->right;
		return t;
	}
}




bool isBST(node* t) //----------------------test whether tree is a BST or not
{
	if (t == NULL) return true;
	if (t->left != NULL && findMin(t->left) > t->info)
		return false; //Lc>p
	if (t->right != NULL && findMin(t->right) < t->info)
		return false; //Rc <P
	if (!isBST(t->left) || !isBST(t->right))
		return false;
	return true;
}


void remLeaves(node* &t)//---------------------remove existing binary tree leaves
{
	if (t != NULL)
	{
		remLeaves(t->left);
		if (t->left == NULL && t->right == NULL)
			delete t;
		remLeaves(t->right);
	}
}







void deleteBST(node* &t) //-------------------------------------------delete BST
{
	if (t != NULL)
	{
		//post order
		deleteBST(t->left);
		deleteBST(t->right);
		delete t;
	}
}
 
//--------------------------------main --------------------------------------------
int main()
{
	node *t = NULL; node *t2=NULL;
	int a[7] = { 20,30,10, 25,35, 15, 5 };

	//creat tree and display 
	for (int i = 0; i < 7; ++i)
	{
		insert(t, a[i]); insert(t2, a[i]);
	}
	show(t); cout << endl;
	//search BST for 10 and 17
/*
	search(t, 10); 
	search(t, 17);
*/
	//find and display tree hight
	cout << "The tree hight is " << height(t) << endl;

	//display tree side-way
	cout << "Tree in sideway direction\n";
	int s = 0;
	sideWay(t, s);

	//display tree level-by-level

	cout << "Tree level-by-level\n";
	displayLevelLevel(t);
	cout << endl;

	//fid and display number of nodes in tree
	cout << "No. of nodes=" << countNodes(t) << endl;

	//find and display maximum node value
	cout << "Maximum node value=" << maxNode(t);
	cout << endl; 

	//find paths from root to leaves
	cout << "paths from root to leaves\n";
	int path[10] = { 0 };
	findPathsToLeaf(t, path, 0);
	
	if (sameTrees(t, t2) ) cout << "Trees are the same\n";
	else cout << "Trees are not same\n";

	//create a mirror image of tree t
	node*mir= mirror(t);
	cout << "This is the mirror image of tree t\n:";
	s = 0;
	sideWay(mir, s);

	//display ancestor of 35
	cout << "These are the ancestor of 35: ";
	showAncestor(t, 35);
	//delete the tree works fine
	//deleteBST(t);

	//construct a BT when inorder and preorder are given
	int io[5] = { 4,2,5,1,3 };
	int pro[5] = { 1,2,4,5,3 };
	//node* newT = buildBT(io, pro);
	//s = 0;
	//sideWay(newT, s);
	//cout<<endl
	//display the max element. max vlue is 5 because 
	//the tree is the mirror of original tree
	node *maxx = findMaxBT(t);
	cout << "\nMaximum data is " << maxx->info << endl;
	return 0;
}
