import java.awt.Graphics;
import java.io.IOException;
import java.util.*;

class Model
{
  private ArrayList<Sprite> sprite;

  Model() throws IOException {
    this.sprite = new ArrayList<Sprite>();
    this.sprite.add(new Bank());
  }

  public void initialize(){
    this.sprite = new ArrayList<Sprite>();
    this.sprite.add(new RobberCar());
    RobberCar r = (RobberCar)this.sprite.get(0);
    r.setNumEscaped(0);
    r.setNumCaptured(0);
    this.sprite.set(0,new Bank());
  }

  public void addSprite(int x, int y){
    if((this.sprite.size() % 2) == 0)
    {
      this.sprite.add(new RobberCar());
    } else {
      this.sprite.add(new CopCar());
      this.sprite.get(this.sprite.size() - 1).setX(x);
      this.sprite.get(this.sprite.size() - 1).setY(y);
    }
  }

  public void update(Graphics g) {
    for(Sprite s : this.sprite)
	    s.updateImage(g);
  }

  public ArrayList<Sprite> getSprites() {
    return this.sprite;
  }
  public void updateScene(int width, int height) {
    synchronized (sprite)
    {
      ArrayList<Sprite> remove = new ArrayList<Sprite>();
      for(Sprite s : this.sprite) {
        s.updateState(width, height);
        for(Sprite t : this.sprite)
        {
          if((s instanceof CopCar) && (t instanceof RobberCar))
          {
            RobberCar r = (RobberCar)t;
            if ((s.overlaps(t)) && (!r.isCaptured()))
              r.captured();
            else if (r.hasEscaped())
            {
              remove.add(r);
            }
          }
        }
      }
      this.sprite.removeAll(remove);
    }
  }
}
