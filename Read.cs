using System;
using System.Collections.Generic;
using System.IO;
using System.Text;


namespace ThucTapCoSo
{
    public class Read
    {



        protected static string file = @"D:\\input10.txt";
        protected static string file1 = @"D:\\input100.txt";
        protected static string file2 = @"D:\\input500.txt";
        protected static string[] lines = File.ReadAllLines(file);
        protected static int[] arr = new int[lines.Length];

        public virtual void Readfile()
        {

            for (int i = 0; i < lines.Length; i++)
            {
                //Ép kiểu
                arr[i] = int.Parse(lines[i]);
            }

        }
    }
}
