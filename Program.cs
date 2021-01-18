using System;

namespace ThucTapCoSo
{
    class Demo
    {
        static void Main(string[] args)
        {
            //Đơn vị millisecond
            //Đếm thời gian cho Timsort
            
            Timsort a = new Timsort();
            CountingSort b = new CountingSort();
            DateTime startdate = DateTime.Now;
            a.SortArrayWithTimSort();
            DateTime finishDate = DateTime.Now;
            TimeSpan time = finishDate - startdate;
            Console.WriteLine("Start:=" + startdate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Finish:=" + finishDate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Total:=" + time.Milliseconds);
            Console.WriteLine();
            
            //Đếm thời gian cho Counting Sort
            DateTime startdate1 = DateTime.Now;
            b.SortArrayWithCountingSort();
            DateTime finishDate1 = DateTime.Now;
            TimeSpan time1 = finishDate1 - startdate1;
            Console.WriteLine("Start:=" + startdate1.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Finish:=" + finishDate1.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Total:=" + time1.Milliseconds);
            Console.WriteLine();
            
            Console.ReadKey();
             
            


         }
    }
 }
    
  

