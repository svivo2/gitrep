import java.awt.Graphics;
import java.util.*;

public class RobberCar extends Car
{
  private int xRatio;
  private int yRatio;
  public RobberCar()
  {
    super("Robber Car", 20, new Engine("V8", 20, 200), "red-car.jpg");
    Random rand = new Random();
    this.xRatio = rand.nextInt(10) - 5;
    this.yRatio = rand.nextInt(10) - 5;
    this.fillUp();
  }

  @Override
  public void update(Graphics g) {
    // Move the sprite
    this.drive(40, this.xRatio, this.yRatio);
    super.update(g);
  }

}
