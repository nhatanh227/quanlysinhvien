#ifndef STORE_H
#define STORE_H

#include "monhoc.h"
#include "sinhvien.h"
#include "lopTC.h"
#include <stdlib.h>
#include <stdio.h>

void saveMonHoc(MonHoc* arr[],int n);
void saveSinhVien(Nodesv *);
void saveLopTinChi(Node * root);
void loadMonHoc(MonHoc *[],int&);
Nodesv * loadSinhVien();
Node* loadLopTinChi();

void saveMonHoc(MonHoc* arr[],int n)
{
	FILE * f= fopen("data/monhoc.dat","wb");
	
	for (int i=0;i<n;i++)
	{
		fwrite(arr[i],sizeof(MonHoc),1,f);
	}
	fclose(f);
}
void saveSinhVien(Nodesv * head)
{
	FILE * f= fopen("data/sinhvien.dat","wb");
	while (head!=NULL)
	{
		
		fwrite(&(head->data),sizeof(Sinhvien),1,f);
		head=head->next;
	}
	fclose(f);
}
void writeLop(Node * root, FILE * f)
{
	
	if (root==NULL)
	{
		return;
	}
		
	fwrite(&(root->data),sizeof(Lop),1,f);
	int c=0;
	dsdk * p=root->data.dssvdk;
	while (p!=NULL)
	{
		c++;
		p=p->next;
	}
	p=root->data.dssvdk;
	fwrite(&c,sizeof(int),1,f);
	for (int i=0;i<c;i++)
	{
		fwrite(&(p->data),sizeof(dangky),1,f);
		p=p->next;
	}
	writeLop(root->left,f);
	writeLop(root->right,f);
}
void saveLopTinChi(Node * root)
{
	FILE * f= fopen("data/Loptc.dat","wb");
	writeLop(root,f);
	fclose(f);
}

void  loadMonHoc(MonHoc * arr[],int & n)
{
	FILE * f= fopen("data/monhoc.dat","rb");
	MonHoc buff;
	
	fseek(f,0,SEEK_SET);
	while (fread(&buff,sizeof(MonHoc),1,f)){
		addMH(arr,n,buff);
	}
		
	
	fclose(f);
	
}

Nodesv * loadSinhVien()
{
	FILE * f= fopen("data/sinhvien.dat","rb");
	Sinhvien s;
	Nodesv * sv = NULL;
	fseek(f,0,SEEK_SET);
	while(fread(&s,sizeof(s),1,f))
	{
		addSV(sv,s);
	}
	return sv;
}

Node * loadLopTinChi()
{
	FILE * f= fopen("data/Loptc.dat","rb");
	Lop x;
	Node * r=NULL;
	fseek(f,0,SEEK_SET);
	while (fread(&x,sizeof(x),1,f))
	{
		
		int c;
		fread(&c,sizeof(c),1,f);
		x.dssvdk=NULL;
		for (int i=0;i<c;i++)
		{
			dangky dk;
			fread(&dk,sizeof(dk),1,f);
			addDK(x.dssvdk,dk.masv,dk.diem);
		}
		x.malop=generateKey();
		insertLop(r,x);
	}
	return r;
}

#endif
