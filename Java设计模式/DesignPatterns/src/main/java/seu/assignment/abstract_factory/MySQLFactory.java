package seu.assignment.abstract_factory;

/**
 * @ClassName: MySQLFactory
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:32:44
 * @Input:
 * @Output:
 */
class MySQLFactory implements DBFactory {
   @Override
   public Connection createConnection() {
      System.out.println("-------------MySQLConnection Created!");
      return new MySQLConnection();
   }

   @Override
   public Statement createStatement() {
      System.out.println("-------------MySQLStatement Created!");
      return new MySQLStatement();
   }
}