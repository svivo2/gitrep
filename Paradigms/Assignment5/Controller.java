
import java.awt.Graphics;
import java.io.IOException;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.Timer;
import javax.swing.SwingUtilities;

class Controller implements MouseListener, KeyListener
{
  Model model;
  View view;

  Controller() throws IOException, Exception {
    model = new Model();
    view = new View(this);
  }

  public void update(Graphics g) {
    this.model.update(g);
  }

  public void mousePressed(MouseEvent e) {
	  if (SwingUtilities.isLeftMouseButton(e)) {
		  // Gets here is left mouse button was clicked
      this.model.addSprite(e.getX(),e.getY());
      this.view.repaint();
		} else if (SwingUtilities.isRightMouseButton(e))  {
		  // Gets here if right mouse button was clicked
      this.model.updateScene(this.view.getWidth(), this.view.getHeight());
      this.view.repaint();
    }
  }

  public void mouseReleased(MouseEvent e) {    }
  public void mouseEntered(MouseEvent e) {    }
  public void mouseExited(MouseEvent e) {    }
  public void mouseClicked(MouseEvent e) {    }

  public void keyPressed(KeyEvent e) {  }
  public void keyReleased(KeyEvent e) {  }
  public void keyTyped(KeyEvent e) {
    char c = e.getKeyChar();
    if (c == 'n'){
      for(Sprite s : this.model.getSprites()){
        if(s instanceof RobberCar){
          RobberCar r = (RobberCar)s;
          System.out.println("Captured: " + r.getNumCaptured());
          System.out.println("Escaped: " + r.getNumEscaped());
          break;
        }
      }
    }
    else if (c == 'r'){
      this.model.initialize();
      this.view.repaint();
    }
    else if (c == 's')
    {
      Thread t = new Thread(new SpriteMover(this.model, this.view));
      t.start();
    }
  }

  public static void main(String[] args) throws Exception {
    //  Use the following line to determine which directory your program
    //  is being executed from, since that is where the image files will
    //  need to be.
    //System.out.println("cwd=" + System.getProperty("user.dir"));
    new Controller();
  }
}
