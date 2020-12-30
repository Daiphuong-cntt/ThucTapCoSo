#include<stdio.h>

void Nhapdl(int A[],int &n)
{
	printf("Nhap So luong pt cua mang: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("A[%d]: ",i+1);
		scanf("%d",&A[i]);
	}
}
void Xuatdl(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",A[i]);
	}
}

void Merge(int A[],int l,int r,int m)
{
	// kich thuoc 2 mang con
	int n1=m+1-l;
	int n2=r-m;
	
	// tao 2 mang con
	int L[n1];
	int R[n2];
	
	// sao chep dl vao 2 mang
	for(int i=0;i<n1;i++)
	{
		L[i]=A[l+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j]=A[m+1+j];
	}
	
	// gop 2 mang con
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	
	// sap xep cac phan tu con lai vao mang
	while(i<n1)	// mang trai L
	{
		A[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)	// mang phai R
	{
		A[k]=R[j];
		j++;
		k++;
	}
}

// Ham tach mang va sap xep lai
void MergeSort(int A[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		// ham de qui de tach mang
		MergeSort(A,l,m);
		MergeSort(A,m+1,r);
		// Tron 2 mang
		Merge(A,l,r,m);
	}
}
int main()
{
	int A[100];
	int n;
	Nhapdl(A,n);
	printf("Mang vua nhap:");
	Xuatdl(A,n);
	
	MergeSort(A,0,n-1);
	printf("\nChuoi sau sap xep:");
	Xuatdl(A,n);
	return 0;
}