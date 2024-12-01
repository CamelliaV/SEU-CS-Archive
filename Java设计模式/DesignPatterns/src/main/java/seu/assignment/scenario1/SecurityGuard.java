package seu.assignment.scenario1;

/**
 * @ClassName: SecurityGuard
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/6 16:29:22
 * @Input:
 * @Output:
 */
class SecurityGuard implements Consignee {
   @Override
   public void reconcile() {
      System.out.println("Guard reconcile! ----------");
   }
}