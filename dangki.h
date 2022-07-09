#ifndef DANGKI_H
#define DANGKI_H
#include <string.h>
#include <stdio.h>
struct dangky
{
	char masv[12];
	float diem;
};

struct dsdk
{
	dsdk * next;
	dangky data;
	
};

void delDK(dsdk * & head, char * masv)
{
	if (strcmp(head->data.masv,masv)==0)
	{	
		
		dsdk * p=head;
		head=head->next;
		delete p;
		return;
	}
	dsdk * p=head;
	while (p->next!=NULL && strcmp(p->next->data.masv,masv)!=0)
		p=p->next;
		
	if (p->next!=NULL)
	{
		
		dsdk * nex=p->next->next;
		delete p->next;
		p->next=nex;
	}
}

dsdk * searchDK(dsdk * head, char* msv)
{
	
	dsdk * p=head;
	while (p!=NULL && strcmp(p->data.masv,msv)!=0)
	{
		p=p->next;
	}
	return p;
}

dsdk * createDK(char * msv, float d)
{
	dsdk * p= new dsdk;
	strcpy(p->data.masv,msv);
	p->data.diem=d;
	p->next=NULL;
	return p;
}


void addDK(dsdk *& head, char * msv,float d)
{


	if (searchDK(head,msv)!=NULL)
		{
			
			return;
		}
		
	
	dsdk * p= createDK(msv,d);
	if (head==NULL)
	{
		
		head=p;
		return;
	}
	if (strcmp(head->data.masv,msv)==1)
	{
		
		p->next=head;
		//head->prev=p;
		head=p;
		return;
	}
	
	dsdk * r=head;
	while (r->next!=NULL && strcmp(msv,r->next->data.masv)==1)
		r=r->next;
	dsdk * t=r->next;
	r->next=p;
	p->next=t;
	
}



void printlistDK(dsdk * head)
{
	dsdk * p= head;
	while (p!=NULL)
	{
		printf("%s %f\n",p->data.masv,p->data.diem);
		p=p->next;	
	}

}
#endif
