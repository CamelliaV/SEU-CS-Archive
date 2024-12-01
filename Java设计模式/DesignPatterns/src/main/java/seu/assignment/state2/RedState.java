package seu.assignment.state2;

/**
 * @ClassName: RedState
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 16:59:15
 * @Input:
 * @Output:
 */
class RedState extends AccountState {
   public RedState(AccountState state) {
      this.balance = state.balance;
      this.acc = state.acc;
   }

   @Override
   public void stateCheck() {
      if (balance >= 0) {
         System.out.println("-------------Red To Green State");
         acc.setState(new GreenState(this));
      }
      if (balance < 0 && balance >= -1000) {
         System.out.println("-------------Red To Yellow State");
         acc.setState(new YellowState(this));
      }
   }

   @Override
   public void withdraw(double amount) {
      System.out.println("-------------Fail to withdraw : Red State");
   }
}