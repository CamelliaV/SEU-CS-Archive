package seu.assignment.flyweight;

import java.util.HashMap;

/**
 * @ClassName: ChessFactory
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 16:32:47
 * @Input:
 * @Output:
 */
class ChessFactory {
   private static ChessFactory chessFactory = new ChessFactory();
   private final HashMap<String, AbstractChess> pool = new HashMap<>();
   public static ChessFactory getInstance() {
      return chessFactory;
   }
   public AbstractChess getChess(String type) {
      AbstractChess chess = this.pool.get(type);
      if (chess == null) {
         if (type.equals("White")) {
            chess = new WhiteChess();
         } else if (type.equals("Black")) {
            chess = new BlackChess();
         } else {
            chess = null;
         }
      }
      if (chess != null) {
         this.pool.put(type, chess);
      }
      return chess;
   }
}