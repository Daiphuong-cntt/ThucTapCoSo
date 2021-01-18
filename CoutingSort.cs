using System;
using System.Collections.Generic;
using System.Text;

namespace ThucTapCoSo
{
     public class CountingSort : Read
    {

        

        

        public override void Readfile()
        {
            base.Readfile();
        }
        
        public void SortArrayWithCountingSort()
        {
            base.Readfile();
            
                int[] sorted = CSort(arr);
           
            Console.WriteLine("The given array : ");
            
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
               
            }
            
            Console.WriteLine("After Couting Sort: ");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(sorted[i]+ " ");
               
            }
            Console.Write("\n");
        }

        public int[] CSort(int[] array)
        {
            int[] count = new int[1000000];

            for (int i = 0; i < array.Length; i++)
            {
                int value = array[i];
                count[value]++;
            }

            for (int i = 1; i < count.Length; i++)
            {
                count[i] = count[i] + count[i - 1];
            }

            int[] sorted = new int[array.Length];

            for (int i = array.Length - 1; i >= 0; i--)
            {
                int value = array[i];
                int position = count[value] - 1;
                sorted[position] = value;

                count[value]--;
            }           
            return sorted;
        }

        
    }
}

