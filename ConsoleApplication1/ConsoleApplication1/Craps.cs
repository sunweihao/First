using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Craps
    {
        //产生随机数
        private static Random randomNumbers = new Random();
        //游戏进行状态
        public enum Status { WON,LOST,CONTINUE};
        //骰子点数具体意义表示
        public enum DiceNames
        {
            SNAKE_EYES = 2,
            TREY = 3,
            SEVEN = 7,
            YO_LEVEN = 11,
            BOX_CARS = 12
        }
        public static void Run()
        {
            Status gameStatus =Status.CONTINUE;
            int myPoint = 0;
            int rollNum = RollDice();
            switch ((DiceNames)rollNum)
            {
                case DiceNames.SNAKE_EYES:
                case DiceNames.TREY:
                case DiceNames.BOX_CARS:
                    gameStatus = Status.LOST;
                    //Console.WriteLine("player loses!");
                    break;
                case DiceNames.SEVEN:
                case DiceNames.YO_LEVEN:
                    gameStatus = Status.WON;
                    //Console.WriteLine("player wins!");
                        break;
                default:
                    myPoint = rollNum;
                    break;
            }
            while(gameStatus == Status.CONTINUE)
            {
                rollNum = RollDice();
                if (rollNum == myPoint) gameStatus = Status.WON;
                else if ((DiceNames)rollNum == DiceNames.SEVEN) gameStatus = Status.LOST;
            }
            if (gameStatus == Status.WON) Console.WriteLine("player wins!");
            else Console.WriteLine("player loses!");


        }
        //掷骰子函数
        private static int RollDice()
        {
            //随机数模拟掷骰子
            int num_1 = randomNumbers.Next(1,7);
            int num_2 = randomNumbers.Next(1,7);
            int result = num_1 + num_2;
            Console.WriteLine("player rolled {0} + {1} ={2}",num_1,num_2,result);
            return result; 
        }
    }
}
