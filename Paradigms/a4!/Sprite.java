import java.awt.Graphics;
import java.awt.Image;
import javax.imageio.ImageIO;
import java.io.File;
import java.io.IOException;

class Sprite
{
	private String jpgName;
	private int x;
	private int y;
	private Image image;

	public Sprite(String jpgName)
	{
		setImage(jpgName);
		this.x = 0;
		this.y = 0;
	}

	public int getX() {	return this.x; }
	public int getY() {	return this.y; }
	public void setX(int x) { this.x = x; }
	public void setY(int y) { this.y = y; }

	public void setImage(String imagePath) {
  	try {
    	image = ImageIO.read(new File(imagePath));
    } catch (IOException ioe) {
    	System.out.println("Unable to load image file.");
    }
	}
	public Image getImage() { return image; }

	public void update(Graphics g) {
		g.drawImage(getImage(), getX(), getY(), 60, 60, null);
	}
}
