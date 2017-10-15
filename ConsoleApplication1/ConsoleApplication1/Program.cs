using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //GradeBook
            //GradeBook myGradeBook = new GradeBook("C#");
            //myGradeBook.DisplayMessage(myGradeBook.CourseName);
            //myGradeBook.DetermineGradeAverage();

            //Analysis

            //Analysis analysis = new Analysis();
            //analysis.ProgressExamResults();
            //test Craps
            //Craps.Run();

            //Test Card
            DeckOfCards deckOC = new DeckOfCards();
            deckOC.Shuffle();
            while(deckOC.currentCard< 52)
            {
                deckOC.DealCard();
                if((deckOC.currentCard+1)%4 == 0 )
                {
                    Console.WriteLine();
                }
                deckOC.currentCard++;
            }
        }
    }
}
