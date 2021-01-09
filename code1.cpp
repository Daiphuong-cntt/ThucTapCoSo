#include<iostream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#define MAX 20
using namespace std;


class sort{
	public:
		void PhatSinhNgauNhien(int a[])
		{
		srand(time(0));
		for(int i=0;i<MAX;i++)
			{
			a[i]=(rand()%1500)-750; 
			}
		}
	public:
	void XuatMang(int a[])
	{
		for(int i=0;i<MAX;i++)
		{
			cout << a[i]<< " ";
		
		}
	}
	public:
	void HoanVi(int &x,int &y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	public:
	void SapXepGiamDanBangThuatToanQuickSort(int a[],int left,int right)
	{
		int i,j,x;
		if(left>=right)
		{
			return;
		}
		x=a[(left+right)/2]; // Ch?n ph?n t? gi?a làm giá tr? m?c .
		i=left;
		j=right;
		while(i<j)
			{
			while(a[i]>x) // ? dây là s?p gi?m d?n
			{
				i++;
			}
			while(a[j]<x) // ? dây là s?p gi?m d?n
			{
				j--;
			}
			if(i<=j)
			{
			HoanVi(a[i],a[j]);
			i++;
			j--;
		}
	}
	SapXepGiamDanBangThuatToanQuickSort(a,left,j);
	SapXepGiamDanBangThuatToanQuickSort(a,i,right);
}

public:
void SapXepGiamDanBangThuatToanBubbleSort(int a[])
{
    for(int i=0;i<MAX-1;i++)
	{
		for(int j=MAX-1;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				HoanVi(a[j],a[j-1]);
			}
		}
	}
}
public:
void Xuat()
{
	quaylai:cout <<"\n>>>>>>>>>>>>>>>>Chuong Trinh Do Time Cua Cac Thuat Toan Sap Xep:<<<<<<<<<<<<<<\n";
	int b[MAX],d[MAX],tieptuc;
	int j=1000; 
	clock_t start1 = clock(); 
	while( j--> 0 )
	PhatSinhNgauNhien(b);
	cout <<"\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan 1 La:<<<<<<<<<<<<<<<<<<<<<<<<\n";
	XuatMang(b);
	printf("\n");
	SapXepGiamDanBangThuatToanQuickSort(b,0,MAX-1);
	cout <<"\n------------Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Quick Sort La:------------\n";
	XuatMang(b);
	cout <<"\n";
	clock_t finish1 = clock(); 
	double duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
	
	
	int l=1000; 
	clock_t start2 = clock(); 
	while( l--> 0 )
	PhatSinhNgauNhien(d);
	cout <<"\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan La:<<<<<<<<<<<<<<<<<<<<<<<<\n";
	XuatMang(d);
	cout <<"\n";
	SapXepGiamDanBangThuatToanBubbleSort(d);
	cout <<"\n-----------Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Bubble Sort La:----------\n";
	XuatMang(d);
	cout <<"\n";
	clock_t finish2 = clock(); 
	double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;


	cout <<"\nThoi gian thuc thi cua thuat toan Quick Sort la: "<< duration1<<endl;
	
		cout <<"\nThoi gian thuc thi cua thuat toan Bubble Sort la: "<< duration2<<endl;
	
	cout <<"\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!";
	tieptuc= getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls");
		goto quaylai; 
	}
	
}	
};

int main()
{
    sort s;
	s.Xuat(); 

	return 0;
}
