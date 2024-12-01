package seu.assignment.flyweight;

/**
 * @ClassName: WhiteChess
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 16:26:32
 * @Input:
 * @Output:
 */
class WhiteChess extends AbstractChess {

   protected WhiteChess() {
      super("White");
      System.out.println("---------White Chess Constructed");
   }

   @Override
   protected void play(Integer x, Integer y) {
      this.x = x;
      this.y = y;
      System.out.println("---------White Chess on: " + "(" + this.x + ", " + this.y + ")");
   }
}