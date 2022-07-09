#ifndef LOPTC_H
#define LOPTC_H

#include "sinhvien.h"
#include "dangki.h"
#include <stdio.h>
#include <math.h> 
struct Lop{
	int malop;  
	int hocky;
	int nhom;
	int sosvmax;
	int sosvmin;
	char mamh[10];
	char nienkhoa[10];
	dsdk * dssvdk;
};

struct Node{ //node cua cay nhi phan
	Lop data;
	Node * left;
	Node * right;
};

void printtree(Node *);

Node * createNode(Lop); //tao node
Node * insertLop(Node* &, Lop ); //them node vao cay
Node * delLop(Node * , int ); // xoa node khoi cay
Node * getNode(Node *,int key);// tim mot node theo malop
int countlop=0; //bien dem so luong node da sinh
int generateKey();//sinh khoa

int generateKey()
{
	//sinh khoa theo cay nhi phan bang mang 256 khoa:
	//         128
	//       /     \
	//     64      192
	//    /  \     /  \
	//  32   96  160  224  
	//   ....      ...
	int t=countlop;
	int r=128;
	int level=int(log(t+1)/log(2)); // tinh muc cua node can them
	int delta=128>>level;  
	while (t!=0)
	{
		if (t%2==0)
			r=r+delta;
			else
			r=r-delta;
		t=(t-1)/2;
		delta*=2;
	}
	countlop++;
	return r;	
}


Node * createNode(Lop x)
{
	Node * p= new Node;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
Node* insertLop(Node * & root, Lop x)
{
	
	if (root==NULL)
	{
		root=createNode(x);
		return root;
	}
	
	if (root->data.malop > x.malop)
	{
		root->left=insertLop(root->left,x);	
	}
	else
	if (root->data.malop < x.malop)
	{
		root->right=insertLop(root->right,x);
	}	
	return root;
}

Node * getMinNode(Node * root)
{
	Node * c=root;
	
	while (c!=NULL && c->left!=NULL)
		c=c->left;
	return c;
	
}

Node * delLop(Node * root, int malop)
{
	if (root==NULL) return NULL;
	
	 if (root->data.malop > malop) 
        root->left = delLop(root->left, malop); 
   	
    else 
	
	if (malop > root->data.malop) 
        root->right = delLop(root->right, malop);
		
	else
    { 
    
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            Node * r=root->right;
            delete root;
            return r;
        } 
        else if (root->right == NULL) 
        { 
           Node * r=root->left;
           delete root;
           return r;
        } 
        
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node* t = getMinNode(root->right); 
  		
        // Copy the inorder successor's content to this node 
        root->data = t->data; 
  		
        // Delete the inorder successor 
        root->right = delLop(root->right, t->data.malop); 
    } 
    return root;  
}

Node * getNode(Node * root,int key)
{
	Node * p=root;
	while (p!=NULL)
	{
	
		
		if (p->data.malop==key)
			return p;
			
		if (p->data.malop>key)
			p=p->left;
		else
			p=p->right;
	}
	return p;
}

void printtree(Node * root)
{
	if (root==NULL)
		return;
	printf("%d %s %d %s %d\n",root->data.malop,root->data.nienkhoa, root->data.hocky, root->data.mamh, root->data.nhom);
	printtree(root->left);
	printtree(root->right);
}

Node* getNode(Node * root, int hocky, int nhom, char * nienkhoa, char * mamh)
{
	if (root==NULL)
		return NULL;
	
	if (root->data.hocky == hocky && root->data.nhom == nhom && strcmp(root->data.nienkhoa, nienkhoa) == 0 && strcmp(root->data.mamh, mamh) == 0)
	{
		return root;
	}
	Node * p1 = getNode(root->left, hocky, nhom, nienkhoa, mamh);
	if (p1 != NULL) 
	{
		return p1;
	}
	return getNode(root->right, hocky, nhom, nienkhoa, mamh);	
}

Node * getNode(Node * root, int hocky, char * nienkhoa)
{
	if (root==NULL)
		return NULL;
	
	if (root->data.hocky == hocky && strcmp(root->data.nienkhoa, nienkhoa) == 0)
	{
		return root;
	}
	Node * p1 = getNode(root->left, hocky, nienkhoa);
	if (p1 != NULL) 
	{
		return p1;
	}
	return getNode(root->right, hocky, nienkhoa);	
}
#endif 
