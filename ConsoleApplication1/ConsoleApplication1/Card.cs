using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Card
    {
        private String face;
        private String suit;
        public Card(String cardFace,String cardSuit)
        {
            face = cardFace;
            suit = cardSuit;
        }//end constrcutor
        public override string ToString()
        {
            return face + "of" + suit+"\t";
        }//end overrides
    }
}
