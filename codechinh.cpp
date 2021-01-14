#include<iostream>
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdio>
#include<fstream> 
#include <time.h>
#include <cstdlib>
#include<string>
#include <unistd.h>
#include<graphics.h>
using namespace std;
int time_delay=500;
class Source
{
public:
    Source()
    {

    }
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
};
class Source100: public Source{
    public:
    int dulieu100[100];
    int n=100;
    Source100():Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao100.txt", ios::in);
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
                this->dulieu100[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
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
    Source250():Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao250.txt", ios::in);
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
                this->dulieu250[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
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
    Source500():Source()
    {
    }
     void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao500.txt", ios::in);
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
                this->dulieu500[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
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
class radix: public Sort{
    public:
    //Lay so lon nhat trong day
    int getMax(int arr[], int n) 
    { 
        int mx = arr[0]; 
        for (int i = 1; i < n; i++) 
            if (arr[i] > mx) 
                mx = arr[i]; 
        return mx; 
    } 

    //sap xep day so
    void countSort(int arr[], int n, int exp) 
    { 
        int output[n];  
        int i, count[10] = { 0 }; 
  
        for (i = 0; i < n; i++)
        { 
            count[(arr[i] / exp) % 10]++;
           // sleep(500);
        } 
  
        for (i = 1; i < 10; i++)
        { 
            count[i] += count[i - 1];
            //sleep(500);
        } 
  
    
        for (i = n - 1; i >= 0; i--) { 
            output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
            count[(arr[i] / exp) % 10]--; 
            //sleep(500);
        } 
  
    
        for (i = 0; i < n; i++) 
        {
            arr[i] = output[i];
            //sleep(500);
        }
    } 
    void countSort_dohoa(int arr[], int n, int exp) 
{ 
    int output[n];  
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    for (i = 1; i < 10; i++)
	{ 
        count[i] += count[i - 1];
	}
  
    
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--;
		cleardevice(); 
	    Sort::screen(output,n);
        delay(10); 
    } 
  
    
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
        cleardevice(); 
	    Sort::screen(arr,n);
        delay(10);
        
}
float radixsort_dohoa(int arr[],int n)
{
	clock_t begin = clock(); 
	initwindow(800,1000);
        // Tim so lon nhat de lay so chu so nhieu nhat
        int m = getMax(arr, n); 
  
        // Thuc hien sap xep theo vi tri chu so, exp la vi tri chu so, i la so hien tai 
        for (int exp = 1; m / exp > 0; exp *= 10)
	    { 
            countSort_dohoa(arr, n, exp);
       
	    }
	    getch();
         clock_t end = clock();	
         //cout<<begin<<"\t"<<end<<endl;
         return (float)((end-begin)/CLOCKS_PER_SEC);
    
}
    float radixsort(int arr[], int n) 
    {
        clock_t begin = clock(); 
        // Tim so lon nhat de lay so chu so nhieu nhat
        int m = getMax(arr, n); 
  
        // Thuc hien sap xep theo vi tri chu so, exp la vi tri chu so, i la so hien tai 
        for (int exp = 1; m / exp > 0; exp *= 10)
	    { 
            countSort(arr, n, exp);
       
	    }
         clock_t end = clock();
         
         
         //cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
         //cout << fixed << setprecision(5) <<begin<<endl;
         //cout << fixed << setprecision(5) <<end<<endl;
         return (float)((end-begin)/CLOCKS_PER_SEC);
    } 
  
    // In mang sau khi sap xep 
    void inmang(int arr[], int n)
    { 
        Sort::inmang(arr,n);
    }

};
class insert:public Sort{
    public:
    float insertionSort(int arr[], int n)  
    { 
        clock_t begin = clock(); 
        int i, key, j;  
        for (i = 1; i < n; i++) 
        {  
            key = arr[i];  
            j = i - 1;  
  
            // Dich chuyen phan tu len truoc neu phan tu lon hon key
            while (j >= 0 && arr[j] > key) 
            {  
                arr[j + 1] = arr[j];  
                j = j - 1;  
            }  
            arr[j + 1] = key;
		      
        }
        clock_t end = clock();
         return (float)((end-begin)/CLOCKS_PER_SEC);
    }  
    float insertionSort_dohoa(int arr[], int n)  
{  
    int i, key, j; 
	initwindow(800,1000); 
	clock_t begin = clock();
    for (i = 1; i < n; i++) 
    {  
    	cleardevice();
        key = arr[i];  
        j = i - 1;  
  
        // Dich chuyen phan tu len truoc neu phan tu lon hon key
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;
			screen(arr,n);
        delay(10);
          
    }
    clock_t end = clock();
    
    return (float)((end-begin)/CLOCKS_PER_SEC);
   
    //closewindow();
  
}
    // ham in mang 
    void inmang(int arr[], int n)
        { 
            Sort::inmang(arr,n);
        }
};
int main()
{
    Source100 s100;
    Source250 s250;
    Source500 s500;
    radix ra100,ra250,ra500;
    insert ins100,ins250,ins500;
    s100.laymangfile();
    s250.laymangfile();
	s500.laymangfile();
    cout<<"size\t100\t250\t500"<<endl;
    cout<<"Radix Sort\t"<<ra100.radixsort(s100.dulieu100,s100.n)<<"\t"<<ra250.radixsort(s250.dulieu250,s250.n)<<"\t"<<ra500.radixsort(s500.dulieu500,s500.n);
    getch();
}