package seu.assignment.flyweight;

/**
 * @ClassName: BlackChess
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 16:31:02
 * @Input:
 * @Output:
 */
class BlackChess extends AbstractChess {

   protected BlackChess() {
      super("Black");
      System.out.println("---------Black Chess Constructed");
   }

   @Override
   protected void play(Integer x, Integer y) {
      this.x = x;
      this.y = y;
      System.out.println("---------Black Chess on: " + "(" + this.x + ", " + this.y + ")");
   }
}