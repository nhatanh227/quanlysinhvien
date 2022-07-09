#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
struct Sinhvien
{
	
	int namhoc;
	char masv[12];
	char ho[10];
	char ten[30];
	char phai[4];
	char sdt[13];
	char malop[15];
	
};

struct Nodesv
{
	Sinhvien data;
	Nodesv * next;
};

Nodesv * createSV(Sinhvien);
void addSV(Nodesv * &, Sinhvien);
void delSV(Nodesv * &, char * masv);
Sinhvien getSV(Nodesv *, char *);
int SinhvienCompare(Sinhvien, Sinhvien);
bool searchSV(Nodesv *, char*);


void delSV(Nodesv * & head, char * masv)
{
	if (strcmp(head->data.masv,masv)==0)
	{
		Nodesv * p=head;
		head=head->next;
		delete p;
	}
	Nodesv * p=head;
	while (p->next!=NULL && strcmp(p->next->data.masv,masv)!=0)
		p=p->next;
	if (p->next!=NULL)
	{
		
		Nodesv * nex=p->next->next;
		delete p->next;
		p->next=nex;
	}
}

Nodesv * createSV(Sinhvien x)
{
	Nodesv * p= new Nodesv;
	p->data=x;
	p->next=NULL;
	return p;
}


void addSV(Nodesv *& head, Sinhvien x)
{
	
	Nodesv * p= createSV(x);
	if (head==NULL)
	{
		head=p;
		return;
	}
	if (SinhvienCompare(head->data,x)==1)
	{
		
		p->next=head;
		head=p;
		return;
	}
	
	Nodesv * r=head;
	while (r->next!=NULL && SinhvienCompare(x,r->next->data)==1)
		r=r->next;
	
	p->next=r->next;
	r->next=p;
	
	
}


int SinhvienCompare(Sinhvien a, Sinhvien b)
{
	int cmp=strcmp(a.malop,b.malop);
	if (cmp>0)
	{
		return 1;
	}
	if (cmp<0)
	{
		return -1;
	}
	if (cmp==0)
	{
		if (strcmp(a.masv,b.masv)>0)
			return 1;
			else
			return -1; 
	}
		
}

void printlist(Nodesv * head)
{
	Nodesv * p= head;
	while (p!=NULL)
	{
		printf("%s %s %d\n",p->data.malop,p->data.masv,p->data.namhoc);
		p=p->next;
	}
}

bool searchSV(Nodesv * head, char* masv)
{
	if (head == NULL)
	{
		return false;
	}
	Nodesv * p=head;
	while (p!=NULL)
	{
		if (strcmp(p->data.masv, masv) == 0 )
		{
			return true;
		}
		p=p->next;
	}
	return false;
}

Sinhvien getSV (Nodesv * head, char * masv)
{
	Nodesv * p=head;
	while (p!=NULL && strcmp(p->data.masv,masv)!=0)
	{
		p=p->next;
	}
	return p->data;
}


bool searchMaLop(Nodesv * head, char* malop)
{
	if (head == NULL)
	{
		return false;
	}
	Nodesv * p=head;
	while (p!=NULL && strcmp(p->data.malop, malop)!=0)
	{
		p=p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	return true;
}
#endif 
