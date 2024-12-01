package seu.assignment.abstract_factory;

/**
 * @ClassName: MySQLConnection
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:33:12
 * @Input:
 * @Output:
 */
class MySQLConnection implements Connection {
   @Override
   public void connect() {
      System.out.println("-------------MySQL Connected!");
   }
}