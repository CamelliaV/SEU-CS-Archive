package seu.assignment.state2;

/**
 * @ClassName: Account
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 16:09:10
 * @Input:
 * @Output:
 */
class Account {
   private AccountState state;
   private String owner;

   public Account(String owner, double init) {
      this.owner = owner;
      this.state = new GreenState(init, this);
   }

   public void setState(AccountState state) {
      this.state = state;
   }

   public void deposit(double amount) {
      System.out.println("-------------Deposit: " + amount);

      state.deposit(amount);
   }

   public void withdraw(double amount) {
      System.out.println("-------------Withdraw: " + amount);

      state.withdraw(amount);
   }

}