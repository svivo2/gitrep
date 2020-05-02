import java.awt.Graphics;
import java.util.*;

public class CopCar extends Car
{
  private static int xRatio;
  private static int yRatio;

  public CopCar()
  {
    super("Cop Car", 30, new Engine("V8", 30, 100), "cop-car.jpg");
    Random rand = new Random();
    this.xRatio = rand.nextInt(10) - 5;
    this.yRatio = rand.nextInt(10) - 5;
    this.fillUp();
  }

  public void update(Graphics g) {
    // Move the sprite
    this.drive(20, this.xRatio, this.yRatio);
    super.update(g);
  }

}
