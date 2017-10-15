using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class GradeBook
    {
        public const int Const = 0;
        public String CourseName { get; set; }//end property
        public GradeBook(String courseName)
        {
            CourseName = courseName;
        }//end constrcutor
        public void DisplayMessage(String CourseName)
        {
            Console.WriteLine("Welcome to the course of {0}!", CourseName);
        }//end displaymessage
        public void DetermineGradeAverage()
        {
            int Grade = 0;
            int Count = 1;
            int Total = 0;
            int Average = 0;
            while(Count <= 10)
            {
                Console.WriteLine("Please enter the grade:");
                Grade = Convert.ToInt32(Console.ReadLine());
                Total += Grade;
                Count++;
            }//end while
            Average = Total / 10;
            Console.WriteLine("The total grade of the class is {0}", Total);
            Console.WriteLine("The average grade of the class is {0}", Average);
        }//end determinegradeaverage;
    }
}
