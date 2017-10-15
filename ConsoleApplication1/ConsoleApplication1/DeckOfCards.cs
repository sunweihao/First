using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class DeckOfCards
    {
        private Card[] deck;
        public int currentCard = 0;
        private const int NUMBER_OF_CARDS = 52;
        private Random randomNumbers;
        
        public DeckOfCards()
        {
            String[] faces = {"Ace","Deuce","Three","Four","Five","Six","Seven",
                "Eight","Nine","Ten","Jack","Queen","King"};
            String[] suits = { "Hearts", "Diamonds", "Clubs", "Spades" };

            deck = new Card[NUMBER_OF_CARDS];
            randomNumbers = new Random(NUMBER_OF_CARDS);

            for (int i = 0; i < NUMBER_OF_CARDS; i++)
            {
                deck[i] =new Card(faces[i % 13], suits[i / 13]);
            }
        } //end constrcutor
        public void Shuffle()
        {
            currentCard = 0;
            for(int first = 0; first < NUMBER_OF_CARDS; first++)
            {
                int second = randomNumbers.Next(NUMBER_OF_CARDS);
                Card temp = deck[first];
                deck[first] = deck[second];
                deck[second] = deck[first];
            }
        }
        public void DealCard()
        {
            if (currentCard < NUMBER_OF_CARDS)
            {
                Console.Write(deck[currentCard].ToString());
            }
            else return;
        }
    }
}
