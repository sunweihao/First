import java.awt.*;
import javax.swing.JPanel;

public class DrawPanel extends JPanel
{
    public void paintComponent(Graphics g){
        super.paintComponent(g);

        /*int width = getWidth();
        int height =getHeight();

        //draw a line from (0,0) to (width,height)
        g.drawLine(0,0,width,height);

        //draw a line from (width,0) to (0,height)
        g.drawLine(width,0,0,height);*/

        //draw the face
        g.setColor(Color.YELLOW);
        g.fillOval(10,10,200,200);
        //draw the eyes
        g.setColor(Color.BLACK);
        g.fillOval(55,65,30,30);
        g.fillOval(135,65,30,30);
        //draw the mouth
        g.fillOval(50,110,130,70);
        //touch up the mouth into a smile
        g.setColor(Color.YELLOW);
        g.fillRect(50,110,130,35);
        g.fillOval(50,120,130,45);

    }//end paintComponent
}//end class DrawPanel
