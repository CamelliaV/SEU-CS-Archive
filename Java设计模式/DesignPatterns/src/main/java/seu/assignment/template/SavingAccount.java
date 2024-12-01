package seu.assignment.template;

/**
 * @ClassName: SavingAccount
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 17:00:06
 * @Input:
 * @Output:
 */
class SavingAccount extends AbstractAccount {

   public SavingAccount(String type, Double balance) {
      super(type, balance);
   }

   @Override
   public Double countInterest() {
      System.out.println("----------------Saving Account Interest: balance * 10");
      return this.balance * 10;
   }
}