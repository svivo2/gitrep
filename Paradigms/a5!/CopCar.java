import java.awt.Graphics;
import java.util.*;

public class CopCar extends Car
{
  private static int xRatio;
  private static int yRatio;
  private int xSign;
  private int ySign;

  public CopCar()
  {
    super("Cop Car", 5000, new Engine("V8", 30, 100), "cop-car.jpg");
    Random rand = new Random();
    this.xRatio = rand.nextInt(10) - 5;
    this.yRatio = rand.nextInt(10) - 5;
    this.xSign = 1;
    this.ySign = 1;
    this.fillUp();
  }
  @Override
  public void updateState(int width, int height) {
    if(super.getX() < 0 || super.getX() > width)
      this.xSign = this.xSign * -1;
    else if(super.getY() < 0 || super.getY() > height)
      this.ySign = this.ySign * -1;

    this.drive(2, this.xRatio * this.xSign, this.yRatio * this.ySign);
  }

  public void updateImage(Graphics g) {
    super.updateImage(g);
  }

}
