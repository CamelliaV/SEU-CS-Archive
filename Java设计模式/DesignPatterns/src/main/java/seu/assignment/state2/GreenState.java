package seu.assignment.state2;

/**
 * @ClassName: GreenState
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 16:54:37
 * @Input:
 * @Output:
 */
class GreenState extends AccountState {
   public GreenState(double balance, Account acc) {
      this.balance = balance;
      this.acc = acc;
   }

   public GreenState(AccountState state) {
      this.balance = state.balance;
      this.acc = state.acc;
   }

   @Override
   public void stateCheck() {
      if (balance < -1000) {
         System.out.println("-------------Green To Red State");
         acc.setState(new RedState(this));
      }
      if (balance < 0 && balance >= -1000) {
         System.out.println("-------------Green To Yellow State");
         acc.setState(new YellowState(this));
      }
   }
}