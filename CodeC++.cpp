#include<bits/stdc++.h>  
#include <iostream>
#include <fstream>
#include <ctime>
#include<stdio.h>
#include <unistd.h>
using namespace std;
class Source
{
public:
    Source()
    {

    }
    void xuatmang(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "\n";
        }
    }
    void taoarr(int arr[], int n)
    {
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand();
        }
    }
};
class Source100 :
    public Source {
public:
    int dulieu100[100];
    int n = 100;
    Source100() :Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\dauvao100.txt", ios::in);
        if (fsFile.eof())
        {
            cout << "Read done";
        }
        else
        {
            int tam;
            int i = 0;
            while (fsFile >> tam)
            {
                //cout<<tam<<"\n";
                this->dulieu100[i] = tam;
                i++;
            }
        }

        fsFile.close();
    }
    void taomang(int dl[], int n)
    {
        Source::taoarr(dl, n);
    }
    void xuatmang(int arr[], int n)
    {
        Source::xuatmang(arr, n);
    }

};
class Source250 :public Source {
public:
    int dulieu250[250];
    int n = 250;
    Source250() :Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\dauvao250.txt", ios::in);
        if (fsFile.eof())
        {
            cout << "Read done";
        }
        else
        {
            int tam;
            int i = 0;
            while (fsFile >> tam)
            {
                //cout<<tam<<"\n";
                this->dulieu250[i] = tam;
                i++;
            }
        }

        fsFile.close();
    }
    void taomang(int dl[], int n)
    {
        Source::taoarr(dl, n);
    }
    void xuatmang(int arr[], int n)
    {
        Source::xuatmang(arr, n);
    }
};
class Source500 : public Source {
public:
    int dulieu500[500];
    int n = 500;
    Source500() :Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\dauvao500.txt", ios::in);
        if (fsFile.eof())
        {
            cout << "Read done";
        }
        else
        {
            int tam;
            int i = 0;
            while (fsFile >> tam)
            {
                //cout<<tam<<"\n";
                this->dulieu500[i] = tam;
                i++;
            }
        }

        fsFile.close();
    }
    void taomang(int dl[], int n)
    {
        Source::taoarr(dl, n);
    }
    void xuatmang(int arr[], int n)
    {
        Source::xuatmang(arr, n);
    }
};
class Sort {
public:
    void inmang(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
};
class CoutingSort : public Sort {

public: void CountSort(int arr[], int n) {

	
    int arr1[40000];
    int count_arr[40000];
    int x = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
}


public:  void printArray(int arr[], int n)
{
    Sort::inmang(arr, n);
}
public: 	double ThoiGianThucHien(int arr[], int n)
{

    clock_t star = clock();
    
    CountSort(arr,n);
    sleep(1);
    clock_t end = clock();
    
    double d = (double)(end - star-1) / (CLOCKS_PER_SEC );
    return d;
}
};
class timSort : public Sort {
const int RUN = 32;

public: void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//  Chuc nang tron tron cac run da sap xep lai voi nhau
public:void merge(int arr[], int l, int m, int r)
{

    // Mang ban dau duoc chia lam hai mang trai va phai 
    // len1 => chieu dai mang trai && len2 => chieu dai mang phai 
    int len1 = m - l + 1, len2 = r - m;
   
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

	//Sau khi so sanh, ta tron 2 mang nay vao mot mang lon hon
    
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

	//Sao nhung phan tu con lai ben trai, neu co
    
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    //Sao nhung phan tu con lai ben phai, neu co 
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// Lap lai ham Timsort de sap xep arr[0..n-1] ( tuong tu voi sap xep tron)
 
public:void Sort(int arr[], int n)
{
	

    // Sap xep tung mang con voi kich thuoc RUN 
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + 31),
            (n - 1)));
	//Bat dau tron tu kich thuoc RUN ( hoac 32)
	//No se tron den kich thuoc 64, sau do la 128, den 256 ....
    
    for (int size = RUN; size < n;
        size = 2 * size)
    {
		//Chon diem bat dau cua mang ben trai.Ta bat dau tron arr[left..left+2*size-1]
		 
        for (int left = 0; left < n;
            left += 2 * size)
        {
        	//Tim diem ket thuc cua mang ben trai
			//mid+1 la diem bat dau cua mang ben phai
             
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1),
                (n - 1));

            // tron nhung mang con arr[left.....mid] &  arr[mid+1....right] 
            merge(arr, left, mid, right);
        }
    }
}






public:  void printArray(int arr[], int n)
{
    Sort::inmang(arr, n);
}
public: 	double ThoiGianThucHien(int arr[], int n)
{

    clock_t star = clock();
    Sort(arr,n);
    sleep(1);
    clock_t end = clock();
     
    double d = (double)(end - star-1) / (CLOCKS_PER_SEC );
    return d;
}

};


int main()
{


    timSort tsort100, tsort250, tsort500;
    CoutingSort csort100, csort250, csort500;

    Source100 s;
    Source100 s100_1, s100_2;
    s100_1.laymangfile();
    s100_1.taomang(s100_1.dulieu100, s100_1.n);
    s100_2.laymangfile();
    s100_2.taomang(s100_2.dulieu100, s100_2.n);

    Source250 s250_1, s250_2;
    s250_1.laymangfile();
    s250_1.taomang(s250_1.dulieu250, s250_1.n);
    s250_2.laymangfile();
    s250_2.taomang(s250_2.dulieu250, s250_2.n);

    Source500 s500_1, s500_2;
    s500_1.laymangfile();
    s500_1.taomang(s500_1.dulieu500, s500_1.n);
    s500_2.laymangfile();
    s500_2.taomang(s500_2.dulieu500, s500_2.n);
    
    printf("Chay truoc 1 lan \n ");
	cout << "Size\t\t100\t250\t500";
	tsort100.Sort(s100_1.dulieu100, s100_1.n);
    tsort250.Sort(s250_1.dulieu250, s250_1.n);
    tsort500.Sort(s500_1.dulieu500, s500_1.n);
    csort100.CountSort(s100_2.dulieu100, s100_2.n);
    csort250.CountSort(s250_2.dulieu250, s250_2.n);
    csort500.CountSort(s500_2.dulieu500, s500_2.n);
    
    cout << "\nTimSort\t\t" << tsort100.ThoiGianThucHien(s100_1.dulieu100, s100_1.n) << "\t" << tsort250.ThoiGianThucHien(s250_1.dulieu250, s250_1.n) << "\t" << tsort500.ThoiGianThucHien(s500_1.dulieu500, s500_1.n);
    cout << "\nCouting Sort\t" << csort100.ThoiGianThucHien(s100_2.dulieu100, s100_2.n) << "\t" << csort250.ThoiGianThucHien(s250_2.dulieu250, s250_2.n) << "\t" << csort500.ThoiGianThucHien(s500_2.dulieu500, s500_2.n);
	double sumTimS100=0, sumTimS250=0, sumTimS500=0;
	double sumCountS100=0, sumCountS250=0, sumCountS500=0;
	int a;
	printf("\nNhap vao so lan can tinh trung binh cua thuat toan :  ");
	scanf("%d",&a);
	printf("\nThoi gian trung binh cua thuat toan sau %d lan chay \n",a);
	cout << "Size\t\t100\t250\t500";
	for(int i= 0;i<a;i++){
		// tinh thoi gian trung binh sau 10 lan thuc hien thuat toan
    	sumTimS100 = sumTimS100 + tsort100.ThoiGianThucHien(s100_1.dulieu100, s100_1.n);
		sumTimS250 = sumTimS250 + tsort250.ThoiGianThucHien(s250_1.dulieu250, s250_1.n);
		sumTimS500 = sumTimS500 + tsort500.ThoiGianThucHien(s500_1.dulieu500, s500_1.n);
		
		sumCountS100 = sumCountS100 + csort100.ThoiGianThucHien(s100_2.dulieu100, s100_2.n);
		sumCountS250 = sumCountS250 + csort250.ThoiGianThucHien(s250_2.dulieu250, s100_2.n);
		sumCountS500 = sumCountS500 + csort500.ThoiGianThucHien(s500_2.dulieu500,s500_2.n);
	}
	cout << "\nMerge Sort :\t" << sumTimS100/a << "\t" << sumTimS250/a << "\t" << sumTimS500/a;
	cout << "\nHeap Sort :\t" << sumCountS100/a << "\t" << sumCountS250/a << "\t" << sumCountS500/a;
	return 0;

    
    

}
