using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Analysis
    {
        public void ProgressExamResults()
        {
            int Passes = 0, Failures = 0, nCount = 1, Result = 0;//declare and initialize
            while(nCount <= 10)
            {
                Console.WriteLine("Please enter 1 to pass/ 2 to fail:");
                Result = Convert.ToInt32(Console.ReadLine());
                if (Result == 1) Passes += 1;
                else Failures += 1;
                nCount++;
            }//end while
            Console.WriteLine("Passes:{0}\nFailures:{1}", Passes, Failures);//show the results
            if (Passes >= 8)
            {
                Console.WriteLine("Raise Tuition!");
            }//end if
        }
    }
}
