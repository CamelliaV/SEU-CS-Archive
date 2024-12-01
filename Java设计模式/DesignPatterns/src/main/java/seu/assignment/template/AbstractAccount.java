package seu.assignment.template;

/**
 * @ClassName: AbstractAccount
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 16:55:20
 * @Input:
 * @Output:
 */
abstract class AbstractAccount {
   protected Double balance;
   protected String type;

   protected AbstractAccount(String type, Double balance) {
      this.type = type;
      this.balance = balance;
   }

   public Double getBalance() {
      return balance;
   }

   public String getType() {
      return type;
   }

   public Double countSum() {
      System.out.println("----------------Type: " + this.type);
      return balance + countInterest();
   }

   public abstract Double countInterest();
}