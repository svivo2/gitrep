import java.awt.Graphics;
import java.util.*;

public class RobberCar extends Car
{
  private int xRatio;
  private int yRatio;
  private boolean captured;
  private boolean escaped;
  private static int numCaptured;
  private static int numEscaped;
  public RobberCar()
  {
    super("Robber Car", 5000, new Engine("V8", 20, 200), "red-car.jpg");
    super.setX(300);
    super.setY(300);
    Random rand = new Random();
    this.xRatio = rand.nextInt(10) - 5;
    this.yRatio = rand.nextInt(10) - 5;
    this.fillUp();
    this.captured = false;
  }

  public int getNumEscaped(){return this.numEscaped;}
  public int getNumCaptured(){return this.numCaptured;}
  public void setNumEscaped(int n){ this.numEscaped = n;}
  public void setNumCaptured(int n){ this.numCaptured = n;}


  @Override //*** optimize ***
  public void updateState(int width, int height) {
    if(this.isCaptured())
      this.drive(0, this.xRatio, this.yRatio);
    else if ((super.getY() > height) && (!this.hasEscaped()))
      this.escaped();
    else if ((super.getY() < 0) && (!this.hasEscaped()))
      this.escaped();
    else if ((super.getX() > width) && (!this.hasEscaped()))
      this.escaped();
    else if ((super.getX() < 0) && (!this.hasEscaped()))
      this.escaped();
    else
      this.drive(4, this.xRatio, this.yRatio);
  }

  public void updateImage(Graphics g) {
    super.updateImage(g);
  }
  public void captured(){
    super.setImage("jail.jpg");
    this.captured = true;
    this.numCaptured++;
  }

  public boolean isCaptured(){
    return this.captured;
  }
  public void escaped()
  {
    this.escaped = true;
    this.numEscaped++;
    System.out.println("I'm Free!");
  }
  public boolean hasEscaped(){
    return this.escaped;
  }
}
