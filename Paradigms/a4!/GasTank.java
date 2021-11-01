public class GasTank
{
  private int capacity = 0;
  private double level = 0;

  public GasTank(int capacity)
  {
    if (capacity > 0)
    {
      this.capacity = capacity;
    }
    else
    {
      this.capacity = 0;
    }
    this.level = 0;
  }
  public int getCapacity()
  {
    return this.capacity;
  }
  public double getLevel()
  {
    return this.level;
  }
  public void setLevel(double levelIn)
  {
    this.level = levelIn;
  }
}
