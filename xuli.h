#ifndef XULI_H
#define XULI_H

#include <conio.h>
#include "monhoc.h"
#include "lopTC.h"
#include "store.h"
#include "sinhvien.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

void gotoXY(int x, int y) ;
string convertToString(char* a, int size);
void themSinhVien(Nodesv * &head);
void readstr(char* d, const char s[], int size);
void xoaSinhVien(Nodesv * &head);
void inDSSV(Nodesv * head);
void toUpper (char *  s);

//gan chuoi
void readstr(char* d, const char s[], int size)
{
	for (int i=0;i<size;i++)
	{
		d[i]=s[i];
	}
	d[size]=0;
}

//di chuyen toa do con tro
void gotoXY(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) 
	{
    	if(a[i] != ' ') 
    	{
        	s = s + a[i]; 
        }
    } 
    return s; 
}


//xu li sinh vien
void themSinhVien(Nodesv * & head)
{
	char malop [15] ;
	cout<<"Nhap ma lop: ";
	fflush(stdin);
	cin.getline(malop, 15);
	while (true)
	{
		cout<<"----------------------------------------------------"<<endl;
		Sinhvien sv;
		char masv[12];
		while (true)
		{
			cout<<"Nhap ma sinh vien: ";
			fflush(stdin);
			cin.getline(masv, 12);
			if (searchSV(head, masv) == true)
			{
				cout<<"Ma sinh vien da ton tai!"<<endl;
			}
			else
			{
				break;
			}
		}
		if(strlen(masv) == 0)
		{
			break;
		}
		cout<<"Nhap ho: ";
		fflush(stdin);
		cin.getline(sv.ho, 10);
		cout<<"Nhap ten: ";
		fflush(stdin);
		cin.getline(sv.ten, 30);
		cout<<"Gioi tinh: ";
		fflush(stdin);
		cin.getline(sv.phai, 4);
		cout<<"Nhap SDT: ";
		fflush(stdin);
		cin.getline(sv.sdt, 13);
		cout<<"Nam nhap hoc: ";
		//fflush(stdin);
	
		cin>>sv.namhoc;
		strcpy(sv.malop, malop);
		strcpy(sv.masv, masv);
		addSV(head, sv);
		cout<<"them thanh cong"<<endl;
		system("pause");
	}
	
}

void xoaSinhVien(Nodesv * &head)
{
	while (true)
	{
		char masv [12];
		cout<<"Nhap ma sinh vien can xoa: ";
		fflush(stdin);
		cin.getline(masv, 12);
		if (searchSV(head, masv) == true)
		{
			delSV(head, masv);
			cout<<"Xoa sinh vien thanh cong!"<<endl;
		}
		else 
		{
			cout<<"Khong tim thay ma sinh vien ban vua nhap!"<<endl;
		}
		cout<<"An 1 de tiep tuc, an phim bat ki de quay lai"<<endl;
		char temp;
		fflush(stdin);
		cin>>temp;
		if (temp != '1')
		{
			break;
		}
	}
}

void suaSinhVien(Nodesv * & head)
{
	while (true)
	{
		char masv [12];
		cout<<"Nhap ma sinh vien can sua: ";
		fflush(stdin);
		cin.getline(masv, 12);
		if (searchSV(head, masv) == true)
		{
			
			
			
			Sinhvien sv;
			char masv2[12];
			while (true)
			{
				cout<<"Nhap ma sinh vien: ";
				fflush(stdin);
				cin.getline(masv2, 12);
				if (strcmp(masv2, masv) == 0)
				{
					break;
				}
				if (searchSV(head, masv2) == true)
				{
					cout<<"Ma sinh vien da ton tai!"<<endl;
				}
				else
				{
					break;
				}
				
			}
			
			cout<<"Nhap ho: ";
			fflush(stdin);
			cin.getline(sv.ho, 10);
			cout<<"Nhap ten: ";
			fflush(stdin);
			cin.getline(sv.ten, 30);
			cout<<"Gioi tinh: ";
			fflush(stdin);
			cin.getline(sv.phai, 4);
			cout<<"Nhap SDT: ";
			fflush(stdin);
			cin.getline(sv.sdt, 13);
			cout<<"Nhap ma lop: ";
			fflush(stdin);
			cin.getline(sv.malop, 15);
			cout<<"Nam nhap hoc: ";
			fflush(stdin);
			cin>>sv.namhoc;
			strcpy(sv.masv, masv2);
			delSV(head, masv);
			addSV(head, sv);
		}
		else 
		{
			cout<<"Khong tim thay ma sinh vien ban vua nhap!"<<endl;
		}
		cout<<"An 1 de tiep tuc, an phim bat ki de quay lai"<<endl;
		char temp;
		fflush(stdin);
		cin>>temp;
		if (temp != '1')
		{
			break;
		}
	}
}

void inDSSV(Nodesv * head)
{
	cout<<"Nhap ma lop: ";
	char malop [15];
	fflush(stdin);
	cin.getline(malop, 15);
	Nodesv * p = head;
	while (p!=NULL)
	{
		if (strcmp(p->data.malop,malop) == 0)
		{
			break;
		}
		p=p->next;
	}
	if (p==NULL)
	{
		cout<<"Khong tim thay sinh vien lop "<<malop<<endl;
	}
	else
	{
		system("cls");
		gotoXY(35,0);
		cout<<"DANH SACH SINH VIEN LOP "<<malop<<endl;
		cout<<"MASV";
		gotoXY(14, 1);
		cout<<"HO";
		gotoXY(25, 1);
		cout<<"TEN";
		gotoXY(60, 1);
		cout<<"PHAI";
		gotoXY(67, 1);
		cout<<"SDT";
		gotoXY(80, 1);
		cout<<"NAM NHAP HOC"<<endl;
		int line = 2;
		
		while (p!=NULL)
		{
			if (strcmp(p->data.malop,malop) != 0)
			{
				break;
			}
			
			cout<<p->data.masv;
			gotoXY(14, line);
			cout<<p->data.ho;
			gotoXY(25, line);
			cout<<p->data.ten;
			gotoXY(60, line);
			cout<<p->data.phai;
			gotoXY(67, line);
			cout<<p->data.sdt;
			gotoXY(80, line);
			cout<<p->data.namhoc<<endl;
			
			line++;
			p = p->next;
		}
	}
	
}


//xu li mon hoc
void themMonHoc(MonHoc* arr[], int &n)
{
	while (true)
	{
		cout<<"----------------------------------------------------"<<endl;
		MonHoc mh;
		char mamh[10];
		while (true)
		{
			
			cout<<"Nhap ma mon hoc: ";
			fflush(stdin);
			cin.getline(mamh, 10);
			toUpper(mamh);
			if (searchMonHoc(arr, n, mamh) == true)
			{
				cout<<"Ma mon hoc da ton tai!"<<endl;
			}
			else
			{
				break;
			}
		}
		cout<<"Nhap ten mon hoc: ";
		fflush(stdin);
		cin.getline(mh.tenmh, 30);
		cout<<"So tin chi ly thuyet: ";
		cin>>mh.stclt;
		cout<<"So tin chi thuc hanh: ";
		cin>>mh.stcth;
		strcpy(mh.mamh, mamh);
		addMH(arr, n, mh);
		
		cout<<"an phim bat ki de tiep tuc, an ESC de ket thuc"<<endl;
		char temp;

		temp=getch();
		if (temp == 27)
		{
			return;
		}
	}
}

void xoaMonHoc(MonHoc* arr[], int &n)
{
	while (true)
	{
		cout<<"----------------------------------------------------"<<endl;
		cout<<"Nhap ma mon hoc can xoa: ";
		char mamh[10];
		fflush(stdin);
		cin.getline(mamh, 10);
		toUpper(mamh);
		if (searchMonHoc(arr, n , mamh) == false)
		{
			cout<<"Khong ton tai mon hoc ban can xoa!"<<endl;
		}
		else
		{
			delMH(arr, n, mamh);
		}
		
		cout<<"an phim bat ki de tiep tuc, an ESC de ket thuc"<<endl;
		char temp;
		
		temp=getch();
		
		
		if ((int)temp == 27)
		{
			return;
		}
		
	}
}

void suaMonHoc(MonHoc* arr[], int n)
{
	while (true)
	{
		cout<<"----------------------------------------------------"<<endl;
		cout<<"Nhap ma mon hoc can sua: ";
		char mamh[10];
		fflush(stdin);
		cin.getline(mamh, 10);
		toUpper(mamh);
		if (searchMonHoc(arr, n , mamh) == false)
		{
			cout<<"Khong ton tai mon hoc ban can xoa!"<<endl;
		}
		else
		{
			MonHoc mh;
			char mamh2[12];
			while (true)
			{
				cout<<"Nhap ma mon hoc: ";
				fflush(stdin);
				cin.getline(mamh2, 12);
				toUpper(mamh2);
				if (strcmp(mamh2, mamh) == 0)
				{
					break;
				}
				if (searchMonHoc(arr, n , mamh) == true)
				{
					cout<<"Ma mon hoc da ton tai!"<<endl;
				}
				else
				{
					break;
				}
				
			}
			
			cout<<"Nhap ten mon hoc: ";
			fflush(stdin);
			cin.getline(mh.tenmh, 30);
			cout<<"So tin chi ly thuyet: ";
			cin>>mh.stclt;
			cout<<"So tin chi thuc hanh: ";
			cin>>mh.stcth;
			strcpy(mh.mamh, mamh2);
			delMH(arr, n, mamh);
			addMH(arr, n, mh);
			
			
		}
		
		cout<<"an phim bat ki de tiep tuc, an ESC de ket thuc"<<endl;
			char temp;
			temp=getch();
			
			if (temp == 27)
			{
				return;
			}
		}
}

void inDSMH(MonHoc * arr[], int n)
{
	sortMonHoc(arr, n);
	system("cls");
	gotoXY(35, 0);
	cout<<"DANH SACH MON HOC"<<endl;
	gotoXY(5,1);
	cout<<"MA MH";
	gotoXY(20, 1);
	cout<<"TEN MH";
	gotoXY(53, 1);
	cout<<"SO TCLT";
	gotoXY(65, 1);
	cout<<"SO TCTH"<<endl;
	for (int i=0; i<n; i++)
	{
		gotoXY(5,i+2);
		cout<<arr[i]->mamh;
		gotoXY(20, i+2);
		cout<<arr[i]->tenmh;
		gotoXY(56, i+2);
		cout<<arr[i]->stclt;
		gotoXY(69, i+2);
		cout<<arr[i]->stcth<<endl;
	}
	getchar();
}


//quan ly diem
void nhapDiem(Node * & node, Nodesv * nodesv)
{
	char hocky[4], nhom[4];
	char nienkhoa[10], mamh[10];
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(nienkhoa, 10);
	cout<<"Nhap hoc ky: ";
	cin.getline(hocky,4);
	cout<<"Nhom: ";
	cin.getline(nhom,4);
	cout<<"Ma mon hoc: ";
	fflush(stdin);
	cin.getline(mamh, 10);
	fflush(stdin);
	Node * p = getNode(node, atoi(hocky), atoi(nhom), nienkhoa, mamh);
	if (p == NULL)
	{
		cout<<"Khong tim thay danh sach phu hop!"<<endl;
	}
	else
	{
		dsdk * p1 = p->data.dssvdk;
		if (p1 == NULL)
		{
			cout<<"Danh sach rong!"<<endl;
			getchar();
			return;
		}
		system("cls");
		gotoXY(15, 1);
		cout<<"STT";
		gotoXY(22, 1);
		cout<<"MASV";
		gotoXY(33, 1);
		cout<<"HO";
		gotoXY(52, 1);
		cout<<"TEN";
		gotoXY(78, 1);
		cout<<"DIEM";
		int n = 1;
		
		while (p1 != NULL)
		{
			gotoXY(15, n+1);
			cout<<n;
			gotoXY(22, n+1);
			cout<<p1->data.masv;
			Sinhvien sv = getSV(nodesv, p1->data.masv);
			gotoXY(33, n+1);
			cout<<sv.ho;
			gotoXY(45, n+1);
			cout<<sv.ten;
			//gotoXY(78, n+1);
			//cout<<"DIEM";
			p1=p1->next;
			n++;
		}
		
		//Nhap diem
		p1 = p->data.dssvdk;
		n = 1;
		while (p1 != NULL)
		{
			gotoXY(78, n+1);
			float a;
			cin>>a;
			p1->data.diem = a;
			p1=p1->next;
			n++;
		}
	}
}

void suaDiem(Node * & node, Nodesv * nodesv)
{
	int hocky, nhom;
	char nienkhoa[10], mamh[10];
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(nienkhoa, 10);
	cout<<"Nhap hoc ky: ";
	cin>>hocky;
	cout<<"Nhom: ";
	cin>>nhom;
	cout<<"Ma mon hoc: ";
	fflush(stdin);
	cin.getline(mamh, 10);
	Node * p = getNode(node, hocky, nhom, nienkhoa, mamh);
	if (p == NULL)
	{
		cout<<"Khong tim thay danh sach phu hop!"<<endl;
	}
	else
	{
		dsdk * p1 = p->data.dssvdk;
		if (p1 == NULL)
		{
			cout<<"Danh sach rong!"<<endl;
			getchar();
			return;
		}
		system("cls");
		gotoXY(15, 1);
		cout<<"STT";
		gotoXY(22, 1);
		cout<<"MASV";
		gotoXY(33, 1);
		cout<<"HO";
		gotoXY(52, 1);
		cout<<"TEN";
		gotoXY(78, 1);
		cout<<"DIEM";
		int n = 1;
		
		while (p1 != NULL)
		{
			gotoXY(15, n+1);
			cout<<n;
			gotoXY(22, n+1);
			cout<<p1->data.masv;
			Sinhvien sv = getSV(nodesv, p1->data.masv);
			gotoXY(33, n+1);
			cout<<sv.ho;
			gotoXY(45, n+1);
			cout<<sv.ten;
			gotoXY(78, n+1);
			cout<<p1->data.diem;
			p1=p1->next;
			n++;
		}
		
		//Nhap diem
		p1 = p->data.dssvdk;
		n = 1;
		while (p1 != NULL)
		{
			gotoXY(78, n+1);
			float a;
			cin>>a;
			p1->data.diem = a;
			p1=p1->next;
			n++;
		}
	}
}

void inBangDiem(Node * & node, Nodesv * nodesv, MonHoc * arr[], int n)
{
	int hocky, nhom;
	char nienkhoa[10], mamh[10];
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(nienkhoa, 10);
	cout<<"Nhap hoc ky: ";
	cin>>hocky;
	cout<<"Nhom: ";
	cin>>nhom;
	cout<<"Ma mon hoc: ";
	fflush(stdin);
	cin.getline(mamh, 10);
	Node * p = getNode(node, hocky, nhom, nienkhoa, mamh);
	if (p == NULL)
	{
		cout<<"Khong tim thay danh sach phu hop!"<<endl;
	}
	else
	{
		dsdk * p1 = p->data.dssvdk;
		if (p1 == NULL)
		{
			cout<<"Danh sach rong!"<<endl;
			getchar();
			return;
		}
		system("cls");
		gotoXY(35, 0);
		cout<<"BANG DIEM MON HOC "<<getTenMH(arr, n, mamh);
		gotoXY(35, 1);
		cout<<"Nien khoa: "<<nienkhoa<<" Hoc ky: "<<hocky<<" Nhom: "<<nhom;
		gotoXY(15, 2);
		cout<<"STT";
		gotoXY(22, 2);
		cout<<"MASV";
		gotoXY(33, 2);
		cout<<"HO";
		gotoXY(52, 2);
		cout<<"TEN";
		gotoXY(78, 2);
		cout<<"DIEM";
		int n = 1;
		
		while (p1 != NULL)
		{
			gotoXY(15, n+2);
			cout<<n;
			gotoXY(22, n+2);
			cout<<p1->data.masv;
			Sinhvien sv = getSV(nodesv, p1->data.masv);
			gotoXY(33, n+2);
			cout<<sv.ho;
			gotoXY(45, n+2);
			cout<<sv.ten;
			gotoXY(78, n+2);
			cout<<p1->data.diem;
			p1=p1->next;
			n++;
		}
	}
}

float tinhDiemTrungBinh(char * masv, Node * loptc, MonHoc * arr[], int n)
{
	
	Node * p;
	float diem = 0;
	int tongchi = 0;
	Node * root = loptc;
	while( root ){
		if( root->left == NULL ){
			
			dsdk * ds = root->data.dssvdk;
			while (ds != NULL)
			{
				if (strcmp(ds->data.masv, masv) == 0)
				{
					int tinchi = getTongTinChi(arr, n, root->data.mamh); 		
					diem += ds->data.diem*tinchi;
					//cout<<root->data.mamh<<" ";
					//cout<<root->data.mamh<<ds->data.diem<<tinchi;
					tongchi += tinchi;
					
				}
				ds = ds->next;
			}
			root = root->right;
		}
		else{
			p = root->left;
			while(p->right && p->right != root ){
				p = p->right;
			}
			if( p->right == NULL ){
				p->right = root;
				
				dsdk * ds = root->data.dssvdk;
				while (ds != NULL)
				{
					if (strcmp(ds->data.masv, masv) == 0)
					{
						int tinchi = getTongTinChi(arr, n, root->data.mamh);
						diem += ds->data.diem*tinchi;
						//cout<<root->data.mamh<<" ";
						//cout<<root->data.mamh<<ds->data.diem<<tinchi;
						tongchi += tinchi;
						
					}
					ds = ds->next;
				}
				root = root->left;
			}
			else{
				p->right = NULL;
				root = root->right;
			}
		}
	}
	
		/*int tinchi = getTongTinChi(arr, n, loptc->data.mamh);
				cout<<tinchi;
				dsdk * ds = loptc->data.dssvdk;
				while (ds != NULL)
				{
					if (strcmp(ds->data.masv, masv) == 0)
					{
						cout<<"Diem"<< ds->data.diem;
						diem += ds->data.diem*tinchi;
						tongchi += tinchi;
						break;
					}
					ds = ds->next;
				}
		p = p->right;*/
	
	if (tongchi != 0)
	{
		return diem/tongchi;
	}
	return 0;
}
void inDiemTrungBinh(Node * loptc, Nodesv * nodesv, MonHoc * arr[], int n)
{
	cout<<"Nhap ma lop: ";
	char malop[15];
	fflush(stdin);
	cin.getline(malop, 15);
	if (searchMaLop(nodesv, malop) == false)
	{
		cout<<"Khong ton tai ma lop "<<malop<<endl;
	}
	else 
	{
		system("cls");
		gotoXY(35, 0);
		cout<<"BANG THONG KE DIEM TRUNG BINH KHOA HOC"<<endl;
		gotoXY(35, 1);
		cout<<"Lop: "<<malop<<endl;
		gotoXY(15, 2);
		cout<<"STT";
		gotoXY(22, 2);
		cout<<"MASV";
		gotoXY(33, 2);
		cout<<"HO";
		gotoXY(52, 2);
		cout<<"TEN";
		gotoXY(78, 2);
		cout<<"DIEM";
		int count = 1;
		Nodesv * p = nodesv;
		while (p != NULL)
		{
			if (strcmp(p->data.malop, malop) == 0){
				gotoXY(15, count+2);
				cout<<n;
				gotoXY(22, count+2);
				cout<<p->data.masv;
				gotoXY(33, count+2);
				cout<<p->data.ho;
				gotoXY(45, count+2);
				cout<<p->data.ten;
				gotoXY(78, count+2);
				cout.precision(3);
				cout<<tinhDiemTrungBinh(p->data.masv, loptc, arr, n);
				count++;
			}
			p = p->next;
		}
	}
}



//Tin chi
void moLopTinChi(Node * & loptc, MonHoc * arr[], int &n)
{
	Lop lop;
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(lop.nienkhoa, 10);
	while (true) 
	{
		cout<<"Ma mon hoc: ";
		fflush(stdin);
		cin.getline(lop.mamh, 10);
		toUpper(lop.mamh);
		if (searchMonHoc(arr, n, lop.mamh) == false)
		{
			cout<<"Khong ton tai ma mon hoc nay! Vui long nhap lai."<<endl;
		}
		else 
		{
			break;
		}
	} 
	
	cout<<"Hoc ky: ";
	cin>>lop.hocky;
	cout<<"Nhom: ";
	cin>>lop.nhom;
	cout<<"So sinh vien toi da: ";
	cin>>lop.sosvmax;
	cout<<"So sinh vien toi thieu: ";
	cin>>lop.sosvmin;
	lop.dssvdk=NULL;
	lop.malop = generateKey();
	loptc = insertLop(loptc, lop);
}

void xoaLopTinChi(Node * loptc)
{
	int hocky;
	int nhom;
	char mamh[10];
	char nienkhoa[10];
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(nienkhoa, 10);
	cout<<"Ma mon hoc: ";
	fflush(stdin);
	cin.getline(mamh, 10);
	toUpper(mamh);
	cout<<"Hoc ky: ";
	cin>>hocky;
	cout<<"Nhom: ";
	cin>>nhom;
	
	Node * p = getNode(loptc, hocky, nhom, nienkhoa, mamh);
	if (p == NULL)
	{
		cout<<"Khong tim thay lop tin chi ban muon xoa!"<<endl;
	}
	else
	{
		loptc = delLop(loptc, p->data.malop);
		cout<<"Xoa lop tin chi thanh cong"<<endl;
	}
}

void suaLopTinChi(Node * &loptc, MonHoc * arr[], int n)
{
	int hocky;
	int nhom;
	char mamh[10];
	char nienkhoa[10];
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(nienkhoa, 10);
	cout<<"Ma mon hoc: ";
	fflush(stdin);
	cin.getline(mamh, 10);
	cout<<"Hoc ky: ";
	cin>>hocky;
	cout<<"Nhom: ";
	cin>>nhom;
	
	Node * p = getNode(loptc, hocky, nhom, nienkhoa, mamh);
	if (p == NULL)
	{
		cout<<"Khong tim thay lop tin chi ban muon sua!"<<endl;
	}
	else
	{
		
		
		Lop lop;
		cout<<"Nhap nien khoa: ";
		fflush(stdin);
		cin.getline(lop.nienkhoa, 10);
		while (true) 
		{
			cout<<"Ma mon hoc: ";
			fflush(stdin);
			cin.getline(lop.mamh, 10);
			toUpper(mamh);
			if (searchMonHoc(arr, n, mamh) == false)
			{
				cout<<"Khong ton tai ma mon hoc nay! Vui long nhap lai."<<endl;
			}
			else 
			{
				break;
			}
		} 
		
		cout<<"Hoc ky: ";
		cin>>lop.hocky;
		cout<<"Nhom: ";
		cin>>lop.nhom;
		cout<<"So sinh vien toi da: ";
		cin>>lop.sosvmax;
		cout<<"So sinh vien toi thieu: ";
		cin>>lop.sosvmin;
		lop.malop = generateKey();
		lop.dssvdk=p->data.dssvdk;
		loptc = delLop(loptc, p->data.malop);
		loptc = insertLop(loptc, lop);
	}
}

void inDSLopTinChi(Node * loptc)
{
	system("cls");
	gotoXY(35, 0);
	cout<<"DANH SACH LOP TIN CHI"<<endl;
	gotoXY(10, 1);
	cout<<"Ma lop";
	gotoXY(20, 1);
	cout<<"Ma MH";
	gotoXY(35, 1);
	cout<<"Nien khoa";
	gotoXY(45, 1);
	cout<<"Hoc ky";
	gotoXY(55, 1);
	cout<<"Nhom";
	gotoXY(62, 1);
	cout<<"SV Min";
	gotoXY(70, 1);
	cout<<"SV Max";
	
	
}

void inDSSVDK(Node * loptc, Nodesv * head)
{
	int hocky;
	int nhom;
	char mamh[10];
	char nienkhoa[10];
	cout<<"Nhap nien khoa: ";
	fflush(stdin);
	cin.getline(nienkhoa, 10);
	cout<<"Ma mon hoc: ";
	fflush(stdin);
	cin.getline(mamh, 10);
	cout<<"Hoc ky: ";
	cin>>hocky;
	cout<<"Nhom: ";
	cin>>nhom;
	
	Node * p = getNode(loptc, hocky, nhom, nienkhoa, mamh);
	if (p == NULL)
	{
		cout<<"Khong tim thay lop tin chi ban can xem danh sach!"<<endl;
	}
	else
	{
		dsdk * ds = p->data.dssvdk;
		if (ds == NULL)
		{
			cout<<"Danh sach trong!"<<endl;
		}
		while (ds != NULL)
		{
			Sinhvien sv = getSV (head, ds->data.masv);
			cout<<ds->data.masv<<"\t"<<sv.ho<<" "<<sv.ten<<endl;
			ds = ds->next;
		}
	}
}




//menu
void quanlySV(Nodesv * &head)
{
	while (true)
	{
		system("cls");
		cout<<"1. Them danh sach sinh vien"<<endl;
		cout<<"2. Xoa sinh vien"<<endl;
		cout<<"3. Sua thong tin sinh vien"<<endl;
		cout<<"4. In danh sach sinh vien"<<endl;
		cout<<"5. Quay lai"<<endl;
		cout<<"Lua chon: ";
		int a;
		cin>>a;
		switch (a)
		{
			case 1:
				system("cls");
				themSinhVien(head);
				getchar();
				break;
			case 2:
				system("cls");
				xoaSinhVien(head);
				getchar();
				break;
			case 3:
				system("cls");
				suaSinhVien(head);
				getchar();
				break;
			case 4:
				system("cls");
				inDSSV(head);
				getchar();
				break;
			case 5:
				return;
				break;
			default:
				break;	
		}	
	}
}

void lopTC(Node* & loptc, MonHoc * arr[], int n, Nodesv * dssv)
{
	while (true)
	{
		system("cls");
		cout<<"1. Mo lop tin chi"<<endl;
		cout<<"2. Xoa lop tin chi"<<endl;
		cout<<"3. Sua lop tin chi"<<endl;
		cout<<"4. Danh sach sinh vien dang ky lop tin chi"<<endl;
		cout<<"5. Quay lai"<<endl;
		cout<<"Lua chon: ";
		int a;
		cin>>a;
		switch (a)
		{
			case 1:
				system("cls");
				moLopTinChi(loptc, arr, n);
				printtree(loptc);
				fflush(stdin);
				getchar();
				break;
			case 2:
				system("cls");
				xoaLopTinChi(loptc);
				fflush(stdin);
				getchar();
				break;
			case 3:
				system("cls");
				suaLopTinChi(loptc, arr, n);
				fflush(stdin);
				getchar();
				break;
			case 4:
				system("cls");
				inDSSVDK(loptc, dssv);
				fflush(stdin);
				getchar();
				break;
			case 5:
				return;
				break;
			default:
				break;	
		}	
	}
}

void quanlyMonHoc(MonHoc * arr[], int & n)
{
	while (true)
	{
		system("cls");
		cout<<"1. Them mon hoc"<<endl;
		cout<<"2. Xoa mon hoc"<<endl;
		cout<<"3. Sua mon hoc"<<endl;
		cout<<"4. Danh sach mon hoc"<<endl;
		cout<<"5. Quay lai"<<endl;
		cout<<"Lua chon: ";
		int a;
		cin>>a;
		switch (a)
		{
			case 1:
				system("cls");
				themMonHoc(arr, n);
			
				break;
			case 2:
				system("cls");
				xoaMonHoc(arr, n);
				break;
			case 3:
				system("cls");
				suaMonHoc(arr, n);
				break;
			case 4:
				system("cls");
				inDSMH(arr, n);
				getchar();
				break;
			case 5:
				return;
				break;
			default:
				break;	
		}	
	}
}

void quanlyDiem(MonHoc * arr[], int n, Node * &loptc, Nodesv * &dssv)
{
	while (true)
	{
		system("cls");
		cout<<"1. Nhap diem"<<endl;
		cout<<"2. Xem diem theo lop tin chi"<<endl;
		cout<<"3. Xem diem trung binh"<<endl;
		cout<<"4. Sua diem"<<endl;
		cout<<"5. Quay lai"<<endl;
		cout<<"Lua chon: ";
		int a;
		cin>>a;
		switch (a)
		{
			case 1:
				system("cls");
				nhapDiem(loptc, dssv);
				getchar();
				break;
			case 2:
				system("cls");
				inBangDiem(loptc, dssv, arr, n);
				getchar();
				break;
			case 3:
				system("cls");
				inDiemTrungBinh(loptc, dssv, arr, n);
				getchar();
				break;
			case 4:
				system("cls");
				suaDiem(loptc, dssv);
				getchar();
				break;
				break;
			case 5:
				return;
				break;
			default:
				break;	
		}
	}
}

void luuDuLieu(MonHoc * arr[], int n, Node * &loptc, Nodesv * &dssv)
{
	saveMonHoc(arr, n);
	saveLopTinChi(loptc);
	saveSinhVien(dssv);
	system("cls");
	cout<<"Du lieu da duoc luu"<<endl;
	fflush(stdin);
	getchar();
}

void toUpper (char *  s)
{
	for(int i=0;i<=strlen(s);i++) 
	{ 
    	if(s[i]>=97 && s[i]<=122)
    	{
			s[i]=s[i]-32;
    	}
   }
}

// in ra cac lop trong cung nien khoa va hoc ki de sv dang ki
void lopdk(Node * r,char nk[], int hk, MonHoc * arr[],int n,char * msv)
{
	if (r==NULL)
		return;
	
	dsdk * q=r->data.dssvdk;
	dsdk * p=NULL;
	int slot=0;
	while (q!=NULL)
	{
		
		slot++;
		if (strcmp(q->data.masv,msv)==0)
			p=q;
		q=q->next;
	}
	if (p==NULL)
	{
		if (strcmp(nk,r->data.nienkhoa)==0 && hk==r->data.hocky)
		{
			
		MonHoc * mh=getMH(arr,n,r->data.mamh);
		
		if (mh!=NULL)
			printf("%7d|%14s|%23s|%16d|%16d|%13d|\n",r->data.malop,r->data.mamh,mh->tenmh,r->data.sosvmax,r->data.sosvmin,slot);
			
		}
	}
	
		
	lopdk(r->left,nk,hk,arr,n,msv);
	lopdk(r->right,nk,hk,arr,n,msv);
}
// in ra cac lop da dk de sinh vien duoc phep huy
void lophuy(Node * r, MonHoc * arr[],int n,char * msv)
{
	if (r==NULL)
		return;
	dsdk * p=r->data.dssvdk;
	while (p!=NULL && strcmp(p->data.masv,msv)!=0)
	{
		p=p->next;
	}
	
	if (p!=NULL)
	{
		MonHoc * mh=getMH(arr,n,r->data.mamh);
			printf("%7d|%14s|%23s|%16d|%16d|\n",r->data.malop,r->data.mamh,mh->tenmh,r->data.sosvmax,r->data.sosvmin);
		}
		
	lophuy(r->left,arr,n,msv);
	lophuy(r->right,arr,n,msv);
}
void dkLopTC(char * msv,Node * ltc,MonHoc * arr[],int n)
{
	system("cls");
	cout<<"nhap nien khoa:";
	char nk[10];
	cin>>nk;
	cout<<"nhap hoc ky:";
	int hk;
	cin>>hk;
	while (1)
	{
	system("cls");
	cout<<"|DANH SACH CAC MON DUOC PHEP DANG KY                                                       |"<<endl;
	cout<<"ma lop |   ma mon hoc |  ten mon hoc          |   so sv toi da | so sv toi thieu|so luot da dk|"<<endl;
	cout<<"______________________________________________________________________________________________|"<<endl;
	lopdk(ltc,nk,hk,arr,n,msv);
	cout<<endl<<"______________________________________________________________________________________________|"<<endl<<endl;
	cout<<"|DANH SACH CAC LOP DA DANG KY                                                   |"<<endl;
	cout<<"ma lop |   ma mon hoc |  ten mon hoc          |   so sv toi da | so sv toi thieu|"<<endl;
	cout<<"________________________________________________________________________________|"<<endl;
	lophuy(ltc,arr,n,msv);
	cout<<endl<<"________________________________________________________________________________|"<<endl<<endl;
	cout<<"1. Dang ki"<<endl<<"2. huy lop"<<endl<<"3. thoat"<<endl;
	int c;
	cin>>c;
	switch(c)
	{
		case 1: 
			int  ml;
			do
			{
				cout<<"nhap ma lop muon dang ky (nhap -1 de ket thuc):";
				cin>>ml;
				Node * p=getNode(ltc,ml);
				if (p!=NULL)
				{
					addDK(p->data.dssvdk,msv,0);
				}
			}while (ml!=-1);
		break;
		case 2:
			
			do
			{
				cout<<"nhap ma lop muon huy dang ky (nhap -1 de ket thuc):";
				cin>>ml;
				Node * p=getNode(ltc,ml);
				if (p!=NULL)
				{
					delDK(p->data.dssvdk,msv);
				}
			}while (ml!=-1);
		break;
		case 3:return; break;
	}
	}
}
#endif
