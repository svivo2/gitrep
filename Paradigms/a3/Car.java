public class Car
{
  private String description = "";
  private int x, y = 0;
  private GasTank tank;
  private Engine engine;

  public Car(String description, int maxFuel, Engine engine)
  {
    if(description.length() > 0)
      this.description = description;
    else
      this.description = "Generic Auto";

    if(engine == null)
      this.engine = new Engine("",0,0);
    else
      this.engine = engine;

    if(maxFuel > 0)
      this.tank = new GasTank(maxFuel);
    else
      this.tank = new GasTank(0);
  }

  public String getDescription()
  {
    return this.description + " (engine: " +
      this.engine.getDescription() + ") Fuel: " + String.format("%.2f", this.tank.getLevel())
       + "/" + this.tank.getCapacity() + ", Location: ("
      + this.x + "," + this.y + ")";
  }

  public int getX()
  {
    return this.x;
  }

  public int getY()
  {
    return this.y;
  }

  public double getFuelLevel()
  {
    return this.tank.getLevel();
  }

  public int getMPG()
  {
    return this.engine.getMPG();
  }

  public void fillUp()
  {
    this.tank.setLevel(this.tank.getCapacity());
  }

  public int getMaxSpeed()
  {
    return this.engine.getMaxSpeed();
  }

  public double drive(double distance, double xRatio, double yRatio)
  {
    if((this.getMPG() * this.getFuelLevel()) < distance)
    {
      int newDistance = (int)(this.getMPG() * this.getFuelLevel());
      this.x = this.x + (int)((((newDistance) * xRatio)/(Math.pow(((xRatio * xRatio) + (yRatio * yRatio)),0.5))) + 0.5);
      this.y = this.y + (int)((((newDistance) * yRatio)/(Math.pow(((xRatio * xRatio) + (yRatio * yRatio)),0.5))) + 0.5);
      this.tank.setLevel(this.getFuelLevel() - (((double)newDistance)/this.getMPG()));
      System.out.println("Ran out of gas after driving " +
      newDistance + " miles.");
      return (newDistance);
    }
    else
    {
      this.x = this.x + (int)(((distance * xRatio)/(Math.pow(((xRatio * xRatio) + (yRatio * yRatio)),0.5))) + 0.5);
      this.y = this.y + (int)(((distance * yRatio)/(Math.pow(((xRatio * xRatio) + (yRatio * yRatio)),0.5))) + 0.5);
      this.tank.setLevel(this.getFuelLevel() - ((double)distance/this.getMPG()));
      return distance;
    }
  }
}
