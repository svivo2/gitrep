public class Engine
{
  private String description = "";
  private int mpg, maxSpeed = 0;

  public Engine(String description, int mpg, int maxSpeed)
  {
    if(description.length() > 0 )
    {
      this.description = description;
    }
    else
    {
      this.description = "Generic Engine";
    }
    if (mpg > 0)
    {
      this.mpg = mpg;
    }
    else
    {
      this.mpg = 0;
    }
    if (maxSpeed > 0)
    {
      this.maxSpeed = maxSpeed;
    }
    else
    {
      this.maxSpeed = 0;
    }
  }
  public String getDescription()
  {
    return this.description + "(MPG: " + this.mpg +
      ", Max Speed: " + this.maxSpeed + ")";
  }
  public int getMPG()
  {
    return this.mpg;
  }
  public int getMaxSpeed()
  {
    return this.maxSpeed;
  }
}
