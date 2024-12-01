package seu.assignment.state2;

/**
 * @ClassName: YellowState
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 16:23:34
 * @Input:
 * @Output:
 */
class YellowState extends AccountState {

   public YellowState(AccountState state) {
      this.acc = state.acc;
      this.balance = state.balance;
   }

   @Override
   public void stateCheck() {
      if (balance < -1000) {
         System.out.println("-------------Yellow To Red State");
         acc.setState(new RedState(this));
      }
      if (balance >= 0) {
         System.out.println("-------------Yellow To Green State");
         acc.setState(new GreenState(this));
      }
   }
}