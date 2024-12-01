package seu.assignment.triple_bridge;

/**
 * @ClassName: Info
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:56:32
 * @Input:
 * @Output:
 */
class Info extends Logger {
   @Override
   public void log(String message) {
      System.out.println("Info: ------------------------");
      System.out.println("Message: -> " + message);
      language.code();
      os.systemCalls();
      System.out.println("------------------------------");
      System.out.println();
   }
}