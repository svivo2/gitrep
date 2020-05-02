import java.awt.Graphics;
import java.io.IOException;
import java.util.*;

class Model
{
  private ArrayList<Sprite> sprite;

  Model() throws IOException {
    this.sprite = new ArrayList<Sprite>();
  }

  public void addSprite(int x, int y){
    if((sprite.size() % 2) == 0)
    {
      this.sprite.add(new RobberCar());
      this.sprite.get(this.sprite.size() - 1).setX(x);
      this.sprite.get(this.sprite.size() - 1).setY(y);
    } else {
      this.sprite.add(new CopCar());
      this.sprite.get(this.sprite.size() - 1).setX(x);
      this.sprite.get(this.sprite.size() - 1).setY(y);
    }
  }

  public void update(Graphics g) {
    for(Sprite s : sprite)
	    s.update(g);
  }
  public ArrayList<Sprite> getSprites(){
    return this.sprite;
  }
}
