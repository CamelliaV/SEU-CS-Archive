package seu.assignment.state2;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 20:39:37
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      Account camelia = new Account("Camelia", 1200);
      // ---- Green
      camelia.deposit(200);
      camelia.withdraw(1500);
      // ---- Yellow | Green
      camelia.deposit(100);
      camelia.withdraw(3000);
      // ---- Red
      camelia.deposit(100);
      camelia.withdraw(3000);
   }
}