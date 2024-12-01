package seu.assignment.flyweight;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 16:39:02
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      ChessFactory chessFactory = ChessFactory.getInstance();
      AbstractChess white1 = chessFactory.getChess("White");
      AbstractChess white2 = chessFactory.getChess("White");
      AbstractChess white3 = chessFactory.getChess("White");
      AbstractChess black1 = chessFactory.getChess("Black");
      AbstractChess black2 = chessFactory.getChess("Black");
      white1.play(1, 7);
      white2.play(2, 5);
      white3.play(3, 7);
      black1.play(2, 0);
      black2.play(9, 0);
   }
}