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
void maxHeapSort(int A[],int n,int i)
{
	int max=i;	// khoi tao phan tu lon nhat o goc
	int l=2*i+1;
	int r=2*i+2;
	
	// Dua he so lon nhat len lam goc
	if(n>l && A[l]>A[max])// Max nam ben trai
	{
		max=l;
	}
	if(n>r && A[r]>A[max])// Max nam ben phai
	{
		max=r;
	}
	// Do dua gia tri lon nhat len lam goc
	if(max !=i)
	{
		int tam=A[i];
		A[i]=A[max];
		A[max]=tam;
		// tiep tuc dua max len lam goc
		maxHeapSort(A,n,max);
	}
}
void HeapSort(int A[],int n)
{
	// Tim max cua Heap
	for(int i=n/2-1;i>=0;i--)
		maxHeapSort(A,n,i);
	// sau do dem max xuong cuoi Heap
	for(int i=n-1;i>0;i--)
	{
		int tam=A[0];
		A[0]=A[i];
		A[i]=tam;
		maxHeapSort(A,i,0);
	}	
}
int main()
{
	int A[100];
	int n;
	Nhapdl(A,n);
	printf("Mang vua nhap:");
	Xuatdl(A,n);
	
	HeapSort(A,n);
	printf("\nMerge Sort:");
	Xuatdl(A,n);
	return 0;
}