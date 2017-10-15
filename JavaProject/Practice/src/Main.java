import java.io.IOException;
import java.util.Scanner;
import java.io.File;
import javax.swing.JFrame;
import java.util.Random;
import java.io.*;
import java.util.regex.*;

public class Main
{

    public static void main(String[] args)throws IOException {
        //test class DrawPanel

//        DrawPanel panel = new DrawPanel();
//
//        JFrame application = new JFrame();
//        //terminate the application while the window is closed
//        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        application.add(panel);
//        application.setSize(230,250);
//        application.setVisible(true);

        //test format-specifier
        /*double amount;
        double principle = 1000.0;
        double rate =0.05;

        System.out.printf("%s%20s\n","Year","Amount Every Year");

        for (int i = 1;i<=10;i++){
            amount = principle*Math.pow(rate+1,i);
            System.out.printf("%4d%,20.2f\n",i,amount);
        }*/

        //test GradeBook
        //GradeBook myGradeBook = new GradeBook("Java");
        //myGradeBook.displayMessage();
        //myGradeBook.inputGrades();
        //myGradeBook.displayGrade();
        //myGradeBook.IOGradeFromOrToFile("D:\\learning\\Second-first\\Java\\JavaProject\\Practice\\src\\input.txt","OutPut.txt");

        //Test Craps
        //Craps craps = new Craps();
        //craps.Run();
        //normalRandom(2,4);
        int[] sum = {2,4,3,7,6,10,22,11,8};
        //QuickSort(sum,0,sum.length-1);
        //sort(sum,0,sum.length-1);
        //sort1(sum);
        sort2(sum,0,sum.length-1);
        for (int element:sum) {
            System.out.println(element);
        }
    }
    //生成五十个呈正态分布的随机数
//    public static void normalRandom(double miu,double sigma2){
//        Random randomNumbers = new Random();
//        double normNum = 0;
//        for (int i =0;i<50;i++){
//            normNum = Math.sqrt(sigma2)*randomNumbers.nextGaussian()+miu;
//            System.out.printf("%f\n",normNum);
//        }
//    }
    public static void QuickSort(int[] nSum,int low, int high){
        int base = nSum[low];
        if (low>=high) return;
        while(low<high){
            while(low<high && nSum[high]>=base){
                high--;
            }
            if (low<high) nSum[low++] = nSum[high];
            while (low<high && nSum[low] < base){
                low++;
            }
            if (low<high) nSum[high--] = nSum[low];
        }
        nSum[low] = base;
        QuickSort(nSum,0,low-1);
        QuickSort(nSum,low+1,nSum.length-1);
    }
    //降序
    public static void sort1(int[] a){
        for (int i = 0; i < a.length; i++) {
            for (int j = i+1; j <a.length ; j++) {
                if (a[i]<a[j]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    public static void sort(int a[], int low, int hight) {
        int i, j, index;
        if (low > hight) {
            return;
        }
        i = low;
        j = hight;
        index = a[i]; // 用子表的第一个记录做基准
        while (i < j) { // 从表的两端交替向中间扫描
            while (i < j && a[j] >= index)
                j--;
            if (i < j)
                a[i++] = a[j];// 用比基准小的记录替换低位记录
            while (i < j && a[i] < index)
                i++;
            if (i < j) // 用比基准大的记录替换高位记录
                a[j--] = a[i];
        }
        a[i] = index;// 将基准数值替换回 a[i]
        sort(a, low, i - 1); // 对低子表进行递归排序
        sort(a, i + 1, hight); // 对高子表进行递归排序

    }
    public static void sort2(int a[], int low, int hight) {
        int i, j, index;
        if (low > hight) {
            return;
        }
        i = low;
        j = hight;
        index = a[j]; // 用子表的第一个记录做基准
        while (i < j) { // 从表的两端交替向中间扫描
            while (i < j && a[i] >= index)
                i++;
            if (i < j)
                a[j--] = a[i];// 用比基准小的记录替换低位记录
            while (i < j && a[j] < index)
                j--;
            if (i < j) // 用比基准大的记录替换高位记录
                a[i++] = a[j];
        }
        a[j] = index;// 将基准数值替换回 a[i]
        sort2(a, low, j - 1); // 对低子表进行递归排序
        sort2(a, j + 1, hight); // 对高子表进行递归排序

    }

}
