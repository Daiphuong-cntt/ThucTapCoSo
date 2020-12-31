#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#define MAX 100


void PhatSinhNgauNhien(int a[])
{
	srand(time(0));
	for(int i=0;i<MAX;i++)
	{
		a[i]=(rand()%1500)-750; // ? dây các giá tr? ng?u nhiên s? n?m trong do?n [-30,30] .
	}
}

// Hàm xu?t m?ng các s? nguyên ng?u nhiên .
void XuatMang(int a[])
{
	for(int i=0;i<MAX;i++)
	{
		printf("%4d",a[i]);
	}
}

// Hàm hoán v? 2 s? nguyên.
void HoanVi(int &x,int &y)
{
	int temp=x;
	x=y;
	y=temp;
}


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


// Hàm s?p x?p m?ng các s? nguyên gi?m d?n b?ng thu?t toán Bubble Sort .
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

// Hàm chính .
int main()
{
	quaylai:printf("\n>>>>>>>>>>>>>>>>Chuong Trinh Do Time Cua Cac Thuat Toan Sap Xep:<<<<<<<<<<<<<<\n");
	int a[MAX],b[MAX],c[MAX],d[MAX],tieptuc; // Khai báo 4 m?ng a,b,c,d ?ng v?i 4 thu?t toán s?p x?p .
	


	// L?n s?p x?p th? hai - Thu?t Toán Quick Sort .
	int j=1000; 
	clock_t start2 = clock(); 
	while( j--> 0 )
	PhatSinhNgauNhien(b);
	printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan 1 La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(b);
	printf("\n");
	SapXepGiamDanBangThuatToanQuickSort(b,0,MAX-1);
	printf("\n------------Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Quick Sort La:------------\n");
	XuatMang(b);
	printf("\n");
	clock_t finish2 = clock(); 
	double duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;


	// L?n s?p x?p th? tu - Thu?t Toán Bubble Sort .
	int l=1000; 
	clock_t start4 = clock(); 
	while( l--> 0 )
	PhatSinhNgauNhien(d);
	printf("\n>>>>>>>>>>>>>>>Mang Phat Sinh Ngau Nhien Ban Dau Lan La:<<<<<<<<<<<<<<<<<<<<<<<<\n");
	XuatMang(d);
	printf("\n");
	SapXepGiamDanBangThuatToanBubbleSort(d);
	printf("\n-----------Mang Sau Khi Sap Xep Giam Dan Bang Thuat Toan Bubble Sort La:----------\n");
	XuatMang(d);
	printf("\n");
	clock_t finish4 = clock(); 
	double duration4 = (double)(finish4 - start4) / CLOCKS_PER_SEC;

	printf("\n");
	printf("Thoi gian thuc thi cua thuat toan Quick Sort la: %.2lf", duration2);// Tr? v? th?i gian s?p x?p c?a Thu?t Toán Quick Sort.
	printf("\n");
	printf("Thoi gian thuc thi cua thuat toan Bubble Sort la: %.2lf", duration4);// Tr? v? th?i gian s?p x?p c?a Thu?t Toán Bubble Sort.
	printf("\n");
	printf("\nBan co muon tiep tuc thuc hien chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc!");
	tieptuc=getch();
	if(tieptuc=='c'||tieptuc=='C')
	{
		system("cls"); // Xác nh?n khi ngu?i dùng b?m phím C trên bàn phím thì xóa di h?t t?t c? nh?ng d? li?u dã th?c thi tru?c dó d? chu?n b? cho l?n th?c thi m?i .
		goto quaylai; 
	}
}
