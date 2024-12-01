package seu.assignment.state2;

/**
 * @ClassName: AccountState
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 16:08:35
 * @Input:
 * @Output:
 */
abstract class AccountState {
   protected Account acc;
   protected double balance;

   public abstract void stateCheck();

   public void deposit(double amount) {
      this.balance += amount;
      stateCheck();
   }

   public void withdraw(double amount) {
      this.balance -= amount;
      stateCheck();
   }

}