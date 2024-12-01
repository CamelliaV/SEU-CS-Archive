package seu.assignment.abstract_factory;

/**
 * @ClassName: OracleFactory
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:32:06
 * @Input:
 * @Output:
 */
class OracleFactory implements DBFactory {
   @Override
   public Connection createConnection() {
      System.out.println("-------------OracleConnection Created!");
      return new OracleConnection();
   }

   @Override
   public Statement createStatement() {
      System.out.println("-------------OracleStatement Created!");
      return new OracleStatement();
   }
}