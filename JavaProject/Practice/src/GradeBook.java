import java.util.Scanner;
import java.io.*;
public class GradeBook {

    private String courseName;
    private int total;
    private int count;
    private int aCount;
    private int bCount;
    private int cCount;
    private int dCount;

    private String getCourseName(){
        return courseName;
    }
    private void setCourseName(String CourseName){
        courseName = CourseName;
    }
    public GradeBook(String theName){
        setCourseName(theName);
    }
    public void displayMessage(){
        System.out.printf("Welcome to the course of %s!\n",getCourseName());
    }
    public void inputGrades(){
        int grade = 0;
        System.out.println(//"%s\n%s\n%s\n%s\n",
                "Please enter the grade in the range of (0,100)"+
                //"Enter the end-of-file indicator to exit:",
                //"In linux/Mac enter the <Ctrl>+d,then press the Enter Key",
                //"In windows enter the <Ctrl>+z, then press the Enter key"
                "enter -1 to exit");

        Scanner input = new Scanner(System.in);
        while(input.hasNext()){
            grade = input.nextInt();
            if (grade == -1) break;
            total+=grade;
            count++;
            incrementGradeCount(grade);

        }//end while

    }
    private void incrementGradeCount(int grade){
        switch (grade/10){
            case 9:
            case 10:
                aCount++;
                break;
            case 8:
            case 7:
                bCount++;
                break;
            case 6:
                cCount++;
                break;
            default:
                dCount++;
                break;
        }
    }
    public void displayGrade(){
        double average;
        if (count != 0){
            average = (double)total/count;
            System.out.println("Display the grade:\n");
            System.out.printf("The total grade of the %d students is %d.\n",count,total);
            System.out.printf("The average grade of the %d students is %f\n",count,average);
            System.out.printf("The num of the scale of grade is:\n" +
                    "A:%d\nB:%d\nC:%d\nD:%d\n",aCount,bCount,cCount,dCount);
        }
        else System.out.println("No grade!");
    }
    public void IOGradeFromOrToFile(String pathName1,String pathName2)throws IOException{
        int grade = 0;
        double average;
        File file =new File(pathName1);
        Scanner input = new Scanner(file);
        while(input.hasNextLine()){
            grade = input.nextInt();
            System.out.println(grade);
            total += grade;
            count++;
        }
        average = total/count;
        FileWriter fileWriter = new FileWriter(pathName2);
        PrintWriter printWriter = new PrintWriter(fileWriter);
        printWriter.println("average is:"+average);
        printWriter.close();
        System.out.printf("the average is %f",average);
    }

}
