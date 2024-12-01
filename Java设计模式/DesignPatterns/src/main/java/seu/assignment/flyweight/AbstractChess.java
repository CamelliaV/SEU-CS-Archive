package seu.assignment.flyweight;

/**
 * @ClassName: AbstractChess
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 16:19:55
 * @Input:
 * @Output:
 */
abstract class AbstractChess {
   protected String type;
   protected Integer x;
   protected Integer y;
   protected AbstractChess(String type) {
      this.type = type;
   }

   protected abstract void play(Integer x, Integer y);
}