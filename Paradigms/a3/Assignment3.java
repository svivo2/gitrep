import java.util.Scanner;
import java.awt.*;
import javax.swing.*;
import java.util.*;

public class Assignment3 extends JFrame
{
  public static void main(String[] args)
  {
    //instantiate variables
    JFrame frame = new JFrame();
    String carName = null;
    String engName = null;
    String input = null;
    int tank = 0;
    int mpg = 0;
    int maxSpeed = 0;
    int legs = 0;
    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;
    double leg[][] = new double[10][3];
    Scanner cin = new Scanner(System.in);
    boolean valid = false;

    //get car name
    carName = JOptionPane.showInputDialog(frame, "Please enter the car's description: ");
    System.out.println("carName = " + carName);

    //get tank capacity
    while(tank <= 0)
    {
      input = JOptionPane.showInputDialog(frame, "Please enter fuel tank capacity: ");
      try
      {
        tank = Integer.parseInt(input);
      }
      catch(Exception e)
      {
        JOptionPane.showMessageDialog(frame,"Invalid Input. Exiting...");
        System.exit(0);
      }
    }
    System.out.println("tank = " + tank);

    //get engine name
    engName = JOptionPane.showInputDialog(frame, "Please enter the engine's description: ");
    System.out.println("engName = " + engName);

    //get miles per gallon
    while(mpg <= 0)
    {
      input = JOptionPane.showInputDialog(frame, "Please enter MPG: ");
      try
      {
        mpg = Integer.parseInt(input);
      }
      catch(Exception e)
      {
        JOptionPane.showMessageDialog(frame,"Invalid Input. Exiting...");
        System.exit(0);
      }
    }
    System.out.println("mpg = " + mpg);

    //get max speed
    while(maxSpeed <= 0)
    {
      input = JOptionPane.showInputDialog(frame, "Please enter the max speed: ");
      try
      {
        maxSpeed = Integer.parseInt(input);
      }
      catch(Exception e)
      {
        JOptionPane.showMessageDialog(frame,"Invalid Input. Exiting...");
        System.exit(0);
      }
    }
    System.out.println("maxSpeed = " + maxSpeed);

    //create engine object
    Engine engine = new Engine(engName, mpg, maxSpeed);

    //create car object
    Car car = new Car(carName, tank, engine);

    //print out car description
    JOptionPane.showMessageDialog(frame, car.getDescription());
    System.out.println(car.getDescription());

    //get number of legs
    while(legs <= 0)
    {
      input = JOptionPane.showInputDialog(frame, "Please enter the number of legs: ");
      try
      {
        legs = Integer.parseInt(input);
      }
      catch(Exception e)
      {
        JOptionPane.showMessageDialog(frame,"Invalid Input.");
      }
    }
    System.out.println("legs = " + legs);

    //get info for each leg
    for(int i = 0;i < legs; i++)
    {
      //get distance
      while(leg[i][0] <= 0 || leg[i][0] > 600 || valid == false)
      {
        input = JOptionPane.showInputDialog(frame, "Please enter the distance for leg " + (i + 1) + ".");
        try
        {
          leg[i][0] = Integer.parseInt(input);
          valid = true;
        }
        catch(Exception e)
        {
          System.out.println("INVALID INPUT.");
          valid = false;
        }
      }
      valid = false;
      System.out.println("leg[" + i + "][0] = " + leg[i][0]);

      //get xratio
      while(valid == false)
      {
        input = JOptionPane.showInputDialog(frame, "Please enter the x ratio for leg " + (i + 1) + ".");
        try
        {
          leg[i][1] = Double.parseDouble(input);
          valid = true;
        }
        catch(Exception e)
        {
          System.out.println("INVALID INPUT.");
          valid = false;
        }
      }
      valid = false;
      System.out.println("leg[" + i + "][1] = " + leg[i][1]);

      //get yratio
      while(valid == false)
      {
        input = JOptionPane.showInputDialog(frame, "Please enter the y ratio for leg " + (i + 1) + ".");
        try
        {
          leg[i][2] = Double.parseDouble(input);
          valid = true;
        }
        catch(Exception e)
        {
          System.out.println("INVALID INPUT.");
          valid = false;
        }
      }
      valid = false;
      System.out.println("leg[" + i + "][2] = " + leg[i][2]);
    }

    //initialize drive panel
    DrivePanel trip = new DrivePanel();

    //start trip
    car.fillUp();
    for(int i = 0; i < legs; i++)
    {
      x1 = car.getX();
      y1 = car.getY();
      if(car.drive(leg[i][0],leg[i][1],leg[i][2]) == leg[i][0])
      {
        System.out.println("Completed leg" + (i + 1) + ".");
        x2 = car.getX();
        y2 = car.getY();
      }
      else
      {
        System.out.println("Could not complete leg" + (i + 1) + ", car ran out of gas.");
        x2 = car.getX();
        y2 = car.getY();
      }
      System.out.printf("Line Coordinates: (%.1f,%.1f),(%.1f,%.1f)\n",x1,y1,x2,y2);
      trip.addLine(x1, y1, x2, y2);
    }
    frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
    frame.getContentPane().add(trip);
    frame.setSize(600, 600);
    frame.setVisible(true);

  }
}
