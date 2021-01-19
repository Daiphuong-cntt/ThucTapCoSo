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
float thoigian[6];
float thoigiantb[6];
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
    Source100():Source()
    {
    }
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
    Source250():Source()
    {
    }
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
    Source500():Source()
    {
    }
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
           // delay(10);
            
        } 
        for (i = 1; i < 10; i++)
        { 
            count[i] += count[i - 1];
            //delay(10);
        } 
  
    
        for (i = n - 1; i >= 0; i--) { 
            output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
            count[(arr[i] / exp) % 10]--; 
           //delay(10);
        } 
  
    
        for (i = 0; i < n; i++) 
        {
            arr[i] = output[i];
            //delay(10);
        }
    } 
/*    void countSort_dohoa(int arr[], int n, int exp) 
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
        //delay(10); 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
        cleardevice(); 
	    Sort::screen(arr,n);
        delay(10);
        
}*/
/*float radixsort_dohoa(int arr[],int n)
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
         return (float)((end-begin)/CLOCKS_PER_SEC)*1000;
    
}*/
    float radixsort(int arr[], int n) 
    {
        //auto start = high_resolution_clock::now();
		clock_t t,t2; 
        // Tim so lon nhat de lay so chu so nhieu nhat
        t = clock();
        int m = getMax(arr, n); 
  
        // Thuc hien sap xep theo vi tri chu so, exp la vi tri chu so, i la so hien tai 
        for (int exp = 1; m / exp > 0; exp *= 10)
	    { 
            countSort(arr, n, exp);
       
	    }
	    //delay(50);
	     //sleep(1);
	     sleep(1);
         t2=clock();
        
         float time_taken = ((float)t)/CLOCKS_PER_SEC; // in seconds
         float time_taken2 = ((float)t2)/CLOCKS_PER_SEC;
        
         return (((float)time_taken2-time_taken-1)/CLOCKS_PER_SEC)*1000;
    } 
  
    // In mang sau khi sap xep 
    void inmang(int arr[], int n)
    { 
        Sort::inmang(arr,n);
    }

};
class insert:public Sort{
    public:
    float insertSort(int arr[], int n)  
    {
		clock_t t1,t2; 
        t1 = clock(); 
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
        //sleep(1);
        sleep(1);
        t2 = clock();
        float time_taken1 = ((float)t1)/CLOCKS_PER_SEC; // in seconds
         float time_taken2 = ((float)t2)/CLOCKS_PER_SEC;
        
         return (((float)time_taken2-time_taken1-1)/CLOCKS_PER_SEC)*1000;
    }  
/*    float insertionSort_dohoa(int arr[], int n)  
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
  
}*/
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
    //s100.laymangfile("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao100.txt",s100.dulieu100);
    s100.taomang(s100.dulieu100,s100.n);
    //s250.laymangfile("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao250.txt",s250.dulieu250);
    s250.taomang(s250.dulieu250,s250.n);
	//s500.laymangfile("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao500.txt",s500.dulieu500);
	s500.taomang(s500.dulieu500,s500.n);
    cout<<"size\t\t100\t\t250\t\t500"<<endl;
    
	for(int i=1;i<10;i++)
	{
		
		thoigian[0]=ra100.radixsort(s100.dulieu100,s100.n);
		thoigian[1]=ra250.radixsort(s250.dulieu250,s250.n);
		thoigian[2]=ra500.radixsort(s500.dulieu500,s500.n);
		thoigian[3]=ins100.insertSort(s100.dulieu100,s100.n);
		thoigian[4]=ins250.insertSort(s250.dulieu250,s250.n);
		thoigian[5]=ins500.insertSort(s500.dulieu500,s500.n);
    	printf("Radix Sort\t%f\t%f\t%f\n",thoigian[0],thoigian[1],thoigian[2]);
   		printf("insert Sort\t%f\t%f\t%f",thoigian[3],thoigian[4],thoigian[5]);
   		if(i==1)
   		{
   			thoigiantb[0]=thoigian[0];
   			thoigiantb[1]=thoigian[1];
   			thoigiantb[2]=thoigian[2];
   			thoigiantb[3]=thoigian[3];
   			thoigiantb[4]=thoigian[4];
   			thoigiantb[5]=thoigian[5];
		   }
		else
			{
				thoigiantb[0]=(thoigiantb[0]+thoigian[0])/2;
				thoigiantb[1]=(thoigiantb[1]+thoigian[1])/2;
				thoigiantb[2]=(thoigiantb[2]+thoigian[2])/2;
				thoigiantb[3]=(thoigiantb[3]+thoigian[3])/2;
				thoigiantb[4]=(thoigiantb[4]+thoigian[4])/2;
				thoigiantb[5]=(thoigiantb[5]+thoigian[5])/2;
			}
    	printf("\n\n");
	}
	cout<<"Thoi gian trung binh la:\n";
	printf("Radix Sort\t%f\t%f\t%f\n",thoigiantb[0],thoigiantb[1],thoigiantb[2]);
   		printf("insert Sort\t%f\t%f\t%f",thoigiantb[3],thoigiantb[4],thoigiantb[5]);
cout<<"\nXong";
}
