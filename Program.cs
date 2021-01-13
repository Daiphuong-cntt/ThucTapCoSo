using System;

namespace ThucTapCoSo
{
    class Demo
    {
        static void Main(string[] args)
        {
            DateTime startdate = DateTime.Now;
            CoutingSort.SortArrayWithCountingSort();
            DateTime finishDate = DateTime.Now;
            TimeSpan time = finishDate - startdate;
            Console.WriteLine("Start:=" + startdate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Finish:=" + finishDate.ToString("dd-MM-yyyy HH:mm:ss.fffffff"));
            Console.WriteLine("Total:=" + time.Ticks);
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
    
  

