#include <iostream>
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdio>
#include <fstream> 
#include <time.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <graphics.h>
using namespace std;
class Source
{
public:
    void xuatmang(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<"\n";
        }
    }
    void taoarr(int arr[],int n)
    {
        srand(time(NULL));
        for(int i=0;i<n;i++)
        {
            arr[i]=rand();
        }
    }
    void laymangfile(char* s,int arr[])
    {
        fstream fsFile;
        fsFile.open(s, ios::in);
        if (fsFile.eof())
        {
            cout << "Read done";
        }
        else
        {
  		    int tam ;
            int i = 0;
            while (fsFile>>tam)
            {
                //cout<<tam<<"\n";
                arr[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
    }
};
class Source100: public Source{
    public:
    int dulieu100[100];
    int n=100;
    void laymangfile(char *s,int arr[]){
        Source::laymangfile(s,arr);
    }
    void taomang(int dl[],int n)
    {
        Source::taoarr(dl,n);
    }
    void xuatmang(int arr[],int n)
    {
        Source::xuatmang(arr,n);
    }

};
class Source250:public Source{
    public:
    int dulieu250[250];
    int n=250;
   	void laymangfile(char *s,int arr[]){
        Source::laymangfile(s,arr);
    }
    void taomang(int dl[],int n)
    {
        Source::taoarr(dl,n);
    }
    void xuatmang(int arr[],int n)
    {
        Source::xuatmang(arr,n);
    }
};
class Source500: public Source{
    public:
     int dulieu500[500];
    int n=500;
    void laymangfile(char *s,int arr[]){
        Source::laymangfile(s,arr);
    }
    void taomang(int dl[],int n)
    {
        Source::taoarr(dl,n);
    }
   void xuatmang(int arr[],int n)
    {
        Source::xuatmang(arr,n);
    }
};
class Sort{
public:

    void inmang(int arr[],int n)
    {
        for (int i = 0; i < n; i++) 
        	cout << arr[i] << " "; 
    }
    void hinhchunhat(int x1,int y1,int x2,int y2)
    {
	    line(x1,y1,x1,y2);
	    line(x1,y2,x2,y2);
	    line(x2,y2,x2,y1);
	    line(x2,y1,x1,y1);  
    } 
//in ra man hinh day so theo do hoa
void screen(int arr[], int n)
{
	int xstart=0,ystart=0;
	for(int i=0;i<n;i++)
	{
		hinhchunhat(xstart+i*800/n,	0,	xstart+(i+1)*800/n,	arr[i]/100);
	}
} 
};
class SelectionSort: public Sort 
	{
	// Ham doi cho hai so nguyen
	public: void swap(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
// Hàm selection sort
	public: void selectionSort(int arr[], int n)
    {
        int i, j, min_idx;

        // di chuyen ranh gioi cua mang da sap xep va chua sap xep
        for (i = 0; i < n - 1; i++)
        {
            // tim phan tu nho nhat trong mang chua sap xep
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // doi cho phan tu nho nhat voi phan tu dau tien
            swap(&arr[min_idx], &arr[i]);
        }
    }

public: void selectionSort_dohoa(int arr[], int n)
    {
        int i, j, min_idx;

        // di chuyen ranh gioi cua mang da sap xep va chua sap xep
        for (i = 0; i < n - 1; i++)
        {
            // tim phan tu nho nhat trong mang chua sap xep
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // doi cho phan tu nho nhat voi phan tu dau tien
            swap(&arr[min_idx], &arr[i]);
            cleardevice(); 
	    Sort::screen(arr,n);
        delay(1);
        }
        getch();
    }
    /* ham xuat mang */
	public:  void printArray(int arr[], int size)
    {
        Sort::inmang(arr,size);
    }
	double t_SelectionSort(int arr[],int n)
	{
		clock_t star = clock();
	
		selectionSort(arr,n);
		//	printArray(arr,n);
		sleep(1);
		clock_t end = clock();
		double d = (double)((end-star)-1)/CLOCKS_PER_SEC;
		return d;
	}
};


class TreeSort: public Sort {
	public: int key;
    TreeSort* left, * right;

public: TreeSort* newNode(int item) {
    TreeSort* temp = new TreeSort;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
public:
    Node() {

    }

public: void storeSorted(TreeSort* root, int arr[], int& i) {
          if (root != NULL) {
              storeSorted(root->left, arr, i);
              arr[i++] = root->key;
              storeSorted(root->right, arr, i);
          }
      }

//	Mot chuc nang tien ích de chèn mot
//      Nút voi khóa nhat dinh
public: TreeSort* insert(TreeSort* node, int key) {
        //Neu cây trong == null, tra ve mot Node moi 
          if (node == NULL) return newNode(key);

          
          if (key < node->key)
              node->left = insert(node->left, key);
          else if (key > node->key)
              node->right = insert(node->right, key);

          
          return node;
      }

      // Hàm này sap xep arr [0..n-1] bang cách su dung Tree Sort
public:  void treeSort(int arr[], int n) {
          struct TreeSort* root = NULL;

          // xay dung
          root = insert(root, arr[0]);
          for (int i = 1; i < n; i++)
              root = insert(root, arr[i]);

          // luu tru truyen tai
          int i = 0;
          storeSorted(root, arr, i);
      }
    void inmang(int arr[],int n)
    {
    	Sort::inmang(arr,n);
	}
	double t_TreeSort(int arr[],int n)
	{
		clock_t star = clock();
	//inmang(arr,n);
		treeSort(arr,n);
		sleep(1);
		clock_t end = clock();
		double d = (double)((end-star)-1)/CLOCKS_PER_SEC;
		return d;
	}
};
void laymang(Source100 &s100,Source250 &s250,Source500 &s500)
{
s100.laymangfile("D:\\thucTapCoSo\\dauvao100.txt",s100.dulieu100);
    //s100.taomang(s100.dulieu100,s100.n);
    s250.laymangfile("D:\\thucTapCoSo\\dauvao250.txt",s250.dulieu250);
    //s250.taomang(s250.dulieu250,s250.n);
	s500.laymangfile("D:\\thucTapCoSo\\dauvao500.txt",s500.dulieu500);	
}
int main()
{
	initwindow(800,1000);
	Source100 s100;
    Source250 s250;
    Source500 s500;
//    //radix ra100,ra250,ra500;
//    insert ins100,ins250,ins500;
//	SelectionSort ss100, ss250, ss500;
//    TreeSort ts100, ts250, ts500;
    int choose;
menu:
	//laymang(s100,s250,s500);
	cout<<"-------------------------"<<endl;
	cout<<"1.Selection Sort & Tree Sort"<<endl;
	cout<<"0. Thoat chuong trinh"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"Nhap lua chon cua ban:"<<endl;
	cout<<">>";cin>>choose;
	switch(choose)
	{
		case 0: return -1;
		break;
			case 1: 
		{
			SelectionSort ss100, ss250, ss500;
    		TreeSort ts100, ts250, ts500;
    		ss100.selectionSort(s100.dulieu100,s100.n);
			ss250.selectionSort(s250.dulieu250,s250.n);
			ss500.selectionSort(s500.dulieu500,s500.n);
	
			double sumSS100=0, sumSS250=0, sumSS500=0;
			double sumTS100=0, sumTS250=0, sumTS500=0;
	
			cout << "\nsize\t\t100\t250\t500";
			for (int i=0;i<10;i++)
			{
				//	cout<<"\n----------------------------------------------------";
				//	cout << "\nSelection Sort\t" << ss100.t_SelectionSort(s100_1.dulieu100,s100_1.n) << "\t" << ss250.t_SelectionSort(s250_1.dulieu250,s250_1.n) << "\t" << ss500.t_SelectionSort(s500_1.dulieu500,s500_1.n);
				//	cout << "\nTree Sort\t" << ts100.t_TreeSort(s100_1.dulieu100,s100_1.n) << "\t" << ts250.t_TreeSort(s250_1.dulieu250,s250_1.n) << "\t" << ts500.t_TreeSort(s500_1.dulieu500,s500_1.n);
				sumSS100 = sumSS100 + ss100.t_SelectionSort(s100.dulieu100,s100.n);
				sumSS250 = sumSS250 + ss250.t_SelectionSort(s250.dulieu250,s250.n);
				sumSS500 = sumSS500 + ss500.t_SelectionSort(s500.dulieu500,s500.n);
	
				sumTS100 = sumTS100 + ts100.t_TreeSort(s100.dulieu100,s100.n);
				sumTS250 = sumTS250 + ts250.t_TreeSort(s250.dulieu250,s250.n);
				sumTS500 = sumTS500 + ts500.t_TreeSort(s500.dulieu500,s500.n);
			}
				cout << "\nSelect Sort:\t" << sumSS100/10 << "\t" << sumSS250/10 << "\t" << sumSS500/10;
				cout << "\nTree Sort:\t" << sumTS100/10 << "\t" << sumTS250/10 << "\t" << sumTS500/10;
					int lc;
		cout<<"\nBan co muon bieu dien do hoa khong?(1:Co/0:Khong)"<<endl;
   		cout<<">>";cin>>lc;
   		if(lc==1)
   		{
   			laymang(s100,s250,s500);
			ss100.selectionSort_dohoa(s100.dulieu100,s100.n);
				ss250.selectionSort_dohoa(s250.dulieu250,s250.n);
				ss500.selectionSort_dohoa(s500.dulieu500,s500.n);
   		}
				break;
		}
		default :
  		cout <<"CHUONG TRINH KHONG CO CHUC NANG NAY !!";
			}
	do{
      cout<<"\nbam ENTER de ve menu";
      break;
  	}while(1);
  	fflush(stdin);
	getchar();
  system("cls");
 
  goto menu;
//    Source100 s;
//    Source100 s100_1,s100_2;
//    s100_1.laymangfile();
//    s100_1.taomang(s100_1.dulieu100,s100_1.n);
//    s100_2.laymangfile();
//    s100_2.taomang(s100_2.dulieu100,s100_2.n);
//    
//    Source250 s250_1,s250_2;
//    s250_1.laymangfile();
//    s250_1.taomang(s250_1.dulieu250,s250_1.n);
//    s250_2.laymangfile();
//    s250_2.taomang(s250_2.dulieu250,s250_2.n);
//    
//    Source500 s500_1,s500_2;
//    s500_1.laymangfile();
//    s500_1.taomang(s500_1.dulieu500,s500_1.n);
//    s500_2.laymangfile();
//    s500_2.taomang(s500_2.dulieu500,s500_2.n);
//
//	cout << "size\t\t100\t250\t500";
//	ss100.selectionSort(s100_1.dulieu100,s100_1.n);
//	ss250.selectionSort(s250_1.dulieu250,s250_1.n);
//	ss500.selectionSort(s500_1.dulieu500,s500_1.n);
//	cout << "\nSelection Sort\t" << ss100.ThoiGianThucHien(s100_1.dulieu100,s100_1.n) << "\t" << ss250.ThoiGianThucHien(s250_1.dulieu250,s250_1.n) << "\t" << ss500.ThoiGianThucHien(s500_1.dulieu500,s500_1.n);
//	cout << "\nTree Sort\t" << ss100.ThoiGianThucHien(s100_1.dulieu100,s100_1.n) << "\t" << ss250.ThoiGianThucHien(s250_1.dulieu250,s250_1.n) << "\t" << ss500.ThoiGianThucHien(s500_1.dulieu500,s500_1.n);
//	
//    getchar();
}

