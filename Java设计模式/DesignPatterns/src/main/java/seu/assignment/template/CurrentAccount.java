package seu.assignment.template;

/**
 * @ClassName: CurrentAccount
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 17:05:49
 * @Input:
 * @Output:
 */
class CurrentAccount extends AbstractAccount {

   public CurrentAccount(String type, Double balance) {
      super(type, balance);
   }

   @Override
   public Double countInterest() {
      System.out.println("----------------Current Account Interest: balance * 5");
      return this.balance * 5;
   }
}