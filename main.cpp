#include <iostream>
#include "monhoc.h"
#include "lopTC.h"
#include "store.h"
#include "xuli.h"
#include "dangki.h"

using namespace std;

Node * loptc= NULL;  // node root cua cay nhi phan
MonHoc * Monhoc[300]; // mang con tro
int n=0;
Nodesv * dssv= NULL; // danh sach lien ket

void menugiaovu();
void menusinhvien();

void mainmenu()//lua chon che do nguoi dung (giao vu/ sinh vien)
{
	bool is_Exit = false;
	
	while (!is_Exit) 
	{
		system("cls");
		gotoXY(35,3);
		cout<<"CHUONG TRINH QUAN LY TIN CHI MON HOC"<<endl;
		gotoXY(35,4);
		cout<<"1. Giao vu"<<endl;
		gotoXY(35,5);
		cout<<"2. Sinh vien"<<endl;
		gotoXY(35,6);
		cout<<"3. Thoat"<<endl;
		
		cout<<"Chon che do nguoi dung: ";
		int a;
		fflush(stdin);
		cin>>a;
		if (a==1)
			menugiaovu();// vao menu giao vu
		if (a==2)
			{
				menusinhvien(); //vao menu sinh vien
				getchar();	
			}
		if (a==3)
		{
			is_Exit = true; //thoat
		
		}
	}
	
}
//cac thao tac cua giao vu
void menugiaovu()
{
	bool is_Back = false;
	while (!is_Back)
	{
		system("cls");
		cout<<"GIAO VU"<<endl;
		cout<<"1. Lop tin chi"<<endl;
		cout<<"2. Quan ly sinh vien"<<endl;
		cout<<"3. Quan ly mon hoc"<<endl;
		cout<<"4. Quan ly diem"<<endl;
		cout<<"5. Luu du lieu"<<endl;
		cout<<"6. Quay lai"<<endl;
		cout<<"Nhap lua chon cua ban: ";
		int a;
		cin>>a;
		switch (a)
		{
			case 1:
				
				lopTC(loptc, Monhoc, n, dssv);//quan li lop tin chi (xuli.h)
				
				break;
			case 2:
				quanlySV(dssv); //quan li sinh vien (xuli.h)
				break;
			case 3:
				quanlyMonHoc(Monhoc, n); //quan li mon hoc (xuli.h)
				break;
			case 4:
				quanlyDiem(Monhoc, n, loptc, dssv); //quan li diem (xuli.h)
				break;
			case 5:
				luuDuLieu(Monhoc, n, loptc, dssv);// luu du lieu
				break;
			case 6:
				is_Back = true;// thoat
				break;
			
		}
	}
}

//menu
void menusinhvien()
{
	system("cls");
	char input[12];
	cout<<"Nhap ma sinh vien cua ban: ";
	fflush(stdin);
	cin.getline(input, 12);
	while (searchSV(dssv, input) == false)
	{
		cout<<"Ma sinh vien ban nhap khong ton tai!"<<endl;
		return;
	}
	system("cls");
	cout<<"1. dang ki lop tinh chi"<<endl;
	cout<<"2. thoat"<<endl;
	int a;
	cin>>a;
	
	switch(a)
	{
		case 1:dkLopTC(input,loptc,Monhoc,n);//dang ki tin chi
			break;
		case 2: return;break;
	}
}

int main()
{
	//lay du lieu tu file nap vao chuong trinh
	loptc = loadLopTinChi();  
	loadMonHoc(Monhoc, n);   
	dssv = loadSinhVien();    
	//---------------------------------------
	

	// in ra menu chinh
	mainmenu();
	
	//luu tat ca cac du lieu truoc khi thoat
	saveLopTinChi(loptc);
	saveMonHoc(Monhoc, n);
	saveSinhVien(dssv);
	//------------------------------------
	
}
