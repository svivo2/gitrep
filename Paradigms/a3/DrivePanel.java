import java.awt.*;
import javax.swing.*;
import java.util.*;

public class DrivePanel extends JPanel
{
  private final ArrayList<Line> lines = new ArrayList<Line>();

  public void addLine(float x1, float y1, float x2, float y2) {
      this.lines.add(new Line(x1, y1, x2, y2));
  }

  public void paintComponent(Graphics g) {
      for(final Line r : lines) {
          r.paint(g);
      }
  }
  public ArrayList<Line> getLines(){
    return this.lines;
  }
}

class Line {
    private final float x1;
    private final float x2;
    private final float y1;
    private final float y2;

    public Line(float x1, float y1, float x2, float y2) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }

    public void paint(Graphics g) {
        g.drawLine((int)this.x1,(int)(600 - this.y1),(int)this.x2,(int)(600 - this.y2));
        g.drawString("(" + (int)this.x2 + "," + (int)this.y2 + ")",(int)this.x2,(int)(600 - this.y2));
    }
}
