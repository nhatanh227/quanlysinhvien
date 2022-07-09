#ifndef MONHOC_H
#define MONHOC_H


#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <iostream>
using namespace std;
const int slmhmax=300;
	
struct MonHoc
{
	int stclt;  //so tin chi ly thuyet 
	int stcth; // so tin chi thuc hanh
	char mamh[10]; //ma mon hoc
	char tenmh[30]; // ten mon hoc
};

	
//them mon hoc
void addMH(MonHoc* arr[], int &n, MonHoc x)
{
	arr[n]=new MonHoc;
	*(arr[n])=x;
	n++;
}


//xoa mon hoc
void delMH(MonHoc * arr[], int & n, char * mamh)
{
	int pos=-1;
	for (int i=0;i<n;i++)
	{
		if (strcmp(arr[i]->mamh,mamh)==0)
			pos=i;
	}
	if (pos!=-1)
	{
		delete arr[pos];
		
		for (int i=pos;i<n-1;i++)
		{
			arr[i]=arr[i+1];	
		}
		n--;
	}
	
}




bool searchMonHoc(MonHoc * arr[], int n, char* mamh)
{
	for (int i=0; i<n; i++)
	{
		if (strcmp(arr[i]->mamh, mamh) == 0)
		{
			return true;
		}
	}
	return false;
}

//sap xep mon hoc
void sortMonHoc(MonHoc * arr[], int n)
{
	MonHoc temp;
	for (int i=0; i<n-1 ; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (strcmp(arr[i]->tenmh, arr[j]->tenmh) > 0)
			{
				temp = *arr[i];
				*arr[i] = *arr[j];
				*arr[j] = temp;
			}
		}
	}	
}
// lay ten mon hoc
char * getTenMH(MonHoc * arr[], int n, char * mamh)
{
	for (int i=0; i<n; i++)
	{
		if (strcmp(arr[i]->mamh, mamh) == 0)
		{
			return arr[i]->tenmh;
		}
	}
	return NULL;
}

//tim mon hoc them ma mon hoc
MonHoc * getMH(MonHoc * arr[], int n, char * mamh)
{
	for (int i=0; i<n; i++)
	{
		if (strcmp(arr[i]->mamh, mamh) == 0)
		{
			return arr[i];
		}
	}
	return NULL;
}

//dem tong so chi cua mon hoc
int getTongTinChi(MonHoc * arr[], int n, char * mamh)
{
	for (int i=0; i<n; i++)
	{	
		
		if (strcmp(arr[i]->mamh, mamh) == 0)
		{
			return (arr[i]->stclt + arr[i]->stcth);
		}
	}
	return 0;
}
#endif 
