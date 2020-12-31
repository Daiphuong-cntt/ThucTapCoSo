using System;
using System.Collections.Generic;
using System.Text;

namespace ThucTapCoSo
{
    class CoutingSort
    {
        static public void SortArrayWithCountingSort()
        {
            int[] arrayToSort = { 2, 6, 6, 10, 10, 3 };
            int[] sorted = CSort(arrayToSort);
            
        }

        static public int[] CSort(int[] array)
        {
            int[] count = new int[11];

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


            for (int i = 0; i < count.Length; i++)
            {
                Console.WriteLine(sorted[i]);

            }
            return sorted;

        }


    }
}

