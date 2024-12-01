package seu.assignment.scenario1;

import java.util.ArrayList;
import java.util.List;
import java.util.Observer;

/**
 * @ClassName: CustomerService
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/6 16:30:01
 * @Input:
 * @Output:
 */
class CustomerService {
   private List<Consignee> guards = new ArrayList<>();

   public void callGuards() {
      guards.forEach(Consignee::reconcile);

   }
}