package seu.assignment.observer;

import java.util.ArrayList;
import java.util.List;
import java.util.Observer;

/**
 * @ClassName: Department
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 21:50:14
 * @Input:
 * @Output:
 */
abstract class Department {
   protected List<Consignee> observers = new ArrayList<>();
   public void attach(Consignee observer) {
      this.observers.add(observer);
   }
   public void detach(Consignee observer) {
      this.observers.remove(observer);
   }
   public abstract void changeName(String name);
}