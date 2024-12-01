package seu.assignment.abstract_factory;

import com.sun.org.apache.xpath.internal.operations.Or;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:39:29
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      DBFactory mySQLFactory = new MySQLFactory();
      DBFactory oracleFactory = new OracleFactory();

      mySQLFactory.createConnection().connect();
      mySQLFactory.createStatement().execute();

      oracleFactory.createConnection().connect();
      oracleFactory.createStatement().execute();
   }
}