#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>


using namespace std;

class Source
{
	public:
    Source()
	{
		
	}
    void DocFile(char* s,int arr[])
    {
        fstream F;
        F.open(s, ios::in);
        if (F.eof())
        {
            cout << "Doc file thanh cong !";
        }
        else
        {
  		    int tam ;
            int i = 0;
            while (F >> tam)
            {
                arr[i] = tam;
                i++;
            }
        }
        F.close();
    }
    void XuatMang(int arr[],int n)
    {
    	cout << "\nMang chua sap xep:\n";
        for(int i = 0 ; i < n ; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
class Source100: public Source
{
	public:
	int dulieu100[100];
	int n = 100;
	Source100(): Source()
	{
	
	}
	void LayMangFile100(char *s, int dulieu100[])
	{
		Source::DocFile(s,dulieu100);	
	}
	void XuatMang100(int dulieu100[],int n)
	{
		Source::XuatMang(dulieu100,n);
	}
};
class Source250: public Source
{
	public:
	int dulieu250[250];
	int n = 250;
	Source250(): Source()
	{
	
	}
	void LayMangFile250(char *s, int dulieu250[])
	{
		Source::DocFile(s,dulieu250);	
	}
	void XuatMang250(int dulieu250[],int n)
	{
		Source::XuatMang(dulieu250,n);
	}
};
class Source500: public Source
{
	public:
	int dulieu500[500];
	int n = 500;
	Source500(): Source()
	{
	
	}
	void LayMangFile500(char *s, int dulieu500[])
	{
		Source::DocFile(s,dulieu500);	
	}
	void XuatMang500(int dulieu500[],int n)
	{
		Source::XuatMang(dulieu500,n);
	}
};


class Sort{
	public: void inmang(int arr[],int n)
    {
    	cout << "\nMang sau sap xep\n";
        for (int i = 0 ; i < n ; i++) 
        cout << arr[i] << " "; 
    }
};
class QuickSort: public Sort
{	public :
	void HoanVi(int& x, int& y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
		void InMang(int arr[], int n)
	{
		cout << "\nQuick Sort:\n";
		Sort::inmang(arr, n);
	}


	void quickSort(int a[], int left, int right)
	{
		int i, j, x;
		if (left >= right)
		{
			return;
		}
		x = a[(left + right) / 2];
		i = left;
		j = right;
		while (i < j)
		{
			while (a[i] > x)
			{
				i++;
			}
			while (a[j] < x)
			{
				j--;
			}
			if (i <= j)
			{
				HoanVi(a[i], a[j]);
				i++; j--;
			}
		}
		quickSort(a, left, j);
		quickSort(a, i, right);
		
	}
	


	
   double t_QuickSort (int arr[], int n)
	{
			int j = 1000;
		clock_t start1 = clock();
		

		quickSort(arr, 0,n - 1);
		sleep(1);
		clock_t finish1 = clock();
		double duration1 = (double)(finish1-1 - start1) / (CLOCKS_PER_SEC);
		return duration1;
	}
};



class BubbleSort : public Sort
{
	public:
			void HoanVi(int& x, int& y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
		void bubbleSort(int arr[],int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (arr[j] > arr[j - 1])
				{
					HoanVi(arr[j], arr[j - 1]);
				}
			}
		}
	}
 
	
	void InMang (int arr[], int n)
	{
		cout << "\nBubble Sort:\n";
		Sort::inmang(arr, n);
	}
	// tinh thoi gian thuc hien thuat toan HeapSort
	double t_BubbleSort(int arr[], int n)
	{

		clock_t start2 = clock();

		bubbleSort(arr, n);
	sleep(1);
		clock_t finish2 = clock();
		double duration2 = (double)(finish2 - start2-1) / CLOCKS_PER_SEC;
		return duration2;
	}
};

int main()
{
	Source100 s100_1, s100_2;
	s100_1.LayMangFile100("H:\\dauvao100.txt", s100_1.dulieu100);
	s100_2.LayMangFile100("H:\\dauvao100.txt", s100_2.dulieu100);
	
	Source250 s250_1, s250_2;
	s250_1.LayMangFile250("H:\\dauvao250.txt", s250_1.dulieu250);
	s250_2.LayMangFile250("H:\\dauvao250.txt", s250_2.dulieu250);
	
	Source500 s500_1, s500_2;
	s500_1.LayMangFile500("H:\\dauvao500.txt",s500_1.dulieu500);
	s500_2.LayMangFile500("H:\\dauvao500.txt",s500_2.dulieu500);
	
	QuickSort qs100, qs250, qs500;
	BubbleSort bs100, bs250, bs500;
double sqs100=0, sqs250=0, sqs500=0;
double sbs100=0, sbs250=0, sbs500=0;
	// hien thi
	cout << "Size\t\t100\t250\t500";
//	cout << "\nQuick Sort\t" << qs100.t_QuickSort(s100_1.dulieu100,s100_1.n) << "\t" << qs250.t_QuickSort(s250_1.dulieu250,s250_1.n) << "\t" << qs500.t_QuickSort(s500_1.dulieu500,s500_1.n);
//cout << "\nbubble Sort\t"  << hs100.t_BubbleSort(s100_2.dulieu100,s100_2.n)  << "\t" << hs250.t_BubbleSort(s250_2.dulieu250,s250_2.n)  << "\t" << hs500.t_BubbleSort(s500_2.dulieu500,s500_2.n);
	for(int i=0;i<=10;i++)
	{	sqs100 = sqs100 + qs100.t_QuickSort(s100_1.dulieu100,s100_1.n);
		sqs250 = sqs250 + qs250.t_QuickSort(s250_1.dulieu250,s250_1.n);
		sqs500 = sqs500 + qs500.t_QuickSort(s500_1.dulieu500,s500_1.n);
		
		sbs100 = sbs100 + bs100.t_BubbleSort(s100_2.dulieu100,s100_2.n);
		sbs250 = sbs250 + bs250.t_BubbleSort(s250_2.dulieu250,s250_2.n);
		sbs500 = sbs500 + bs500.t_BubbleSort(s500_2.dulieu500,s500_2.n);
	}
	cout << "\nQuick Sort :\t" << sqs100/10 << "\t" << sqs250/10 << "\t" << sqs500/10;
	cout << "\nBubble Sort :\t" << sbs100/10 << "\t" << sbs250/10 << "\t" << sbs500/10;
    return 0;
}