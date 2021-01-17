using System;

namespace ThucTapCoSo
{
    class Demo
    {
        static void Main(string[] args)
        {
            //Đếm thời gian cho Counting Sort
            DateTime startdate = DateTime.Now;
            CoutingSort.SortArrayWithCountingSort();
            DateTime finishDate = DateTime.Now;
            TimeSpan time = finishDate - startdate;
            Console.WriteLine("Start:=" + startdate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Finish:=" + finishDate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Total:=" + time.Ticks);
            Console.WriteLine();
             //Đếm thời gian cho Timsort
            DateTime startdate = DateTime.Now;
            TimSort.SortArrayWithTimSort();
            DateTime finishDate = DateTime.Now;
            TimeSpan time = finishDate - startdate;
            Console.WriteLine("Start:=" + startdate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Finish:=" + finishDate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Total:=" + time.Ticks);



            Console.ReadKey();
         }
    }
 }
    
  

