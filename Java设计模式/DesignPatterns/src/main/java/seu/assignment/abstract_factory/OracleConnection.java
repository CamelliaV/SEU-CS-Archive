package seu.assignment.abstract_factory;

/**
 * @ClassName: OracleConnection
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:33:02
 * @Input:
 * @Output:
 */
class OracleConnection implements Connection {
   @Override
   public void connect() {
      System.out.println("-------------Oracle Connected!");
   }
}