﻿using System;
using System.Collections.Generic;
using System.Text;

namespace ThucTapCoSo
{
    class CoutingSort
    {
        static public void SortArrayWithCountingSort()
        {
            string file = @"D:\\input.txt";

                // Lưu giá trị của mảng
                string[] lines = File.ReadAllLines(file);

                

                int[] arr = new int[lines.Length];
                for (int i = 0; i < lines.Length; i++)
                {
                    arr[i] = int.Parse(lines[i]);
                }

            int[] sorted = CSort(arrayToSort);
            int m = arrayToSort.Length;
            Console.WriteLine("The given array : ");
            for (int i = 0; i < m; i++)
            {
                Console.Write(arrayToSort[i] + " ");

            }
            Console.Write("\n");
            int n = sorted.Length;
            Console.WriteLine(" After Couting Sort: ");
            for (int i = 0; i < n; i++)
            {
                Console.Write(sorted[i]+ " ");
               
            }
            Console.Write("\n");
            
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


            
            return sorted;

        }


    }
}
