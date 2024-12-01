package seu.assignment.triple_bridge;

/**
 * @ClassName: Warn
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:56:57
 * @Input:
 * @Output:
 */
class Warn extends Logger {
   @Override
   public void log(String message) {
      System.out.println("Warn: ------------------------");
      System.out.println("Message: -> " + message);
      language.code();
      os.systemCalls();
      System.out.println("------------------------------");
      System.out.println();
   }
}