import java.util.Random;
/**
 * Created by 孙伟浩 on 2017/9/27.
 */

public class Craps {
    private static final Random randomNumbers = new Random();
    private enum Status{WON,LOST,CONTINUE};
    private static final int SNAKE_EYES = 2;
    private static final int TREY = 3;
    private static final int SEVEN = 7;
    private static final int YO_LEVEL = 11;
    private static final int BOX_CAPS = 12;
    //the craps process
    public void Run(){
        //game status
        Status gameStatus;
        //save the roll point if the gamestatus is continue
        int myPoint = 0;
        //save the roll point
        int diceNum = RollDice();
        switch(diceNum){
            case SEVEN:
            case YO_LEVEL:
                gameStatus = Status.WON;
                break;
            case SNAKE_EYES:
            case TREY:
            case BOX_CAPS:
                gameStatus = Status.LOST;
                break;
            default:
                gameStatus = Status.CONTINUE;
                myPoint = diceNum;
                break;
        }
        while(gameStatus == Status.CONTINUE){
            diceNum = RollDice();
            if (diceNum == myPoint) gameStatus = Status.WON;
            else if (diceNum == SEVEN) gameStatus = Status.LOST;
        }
        if (gameStatus == Status.LOST) System.out.println("player loses!");
        else System.out.println("player wins!");
    }
    private int RollDice(){
        int num_1 = 1+randomNumbers.nextInt(6);
        int num_2 = 1+randomNumbers.nextInt(6);
        int result = num_1+num_2;
        System.out.printf("rolled %d + %d = %d\n",num_1,num_2,result);
        return result;
    }

}
