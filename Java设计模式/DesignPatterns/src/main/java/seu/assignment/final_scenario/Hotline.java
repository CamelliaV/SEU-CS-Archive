package seu.assignment.final_scenario;

import java.util.Objects;

class Hotline implements Mediator {

   private Colleague customer;

   private Colleague mall;
   @Override
   public void setCustomer(Colleague customer) {
      this.customer = customer;
   }
   @Override
   public void setMall(Colleague mall) {
      this.mall = mall;
   }

   @Override
   public void handleRequest(String message, Colleague colleague) {
      switch (message) {
         case "purchase":
            customer.purchase(mall);
            break;
         case "aftersale":
            customer.aftersale(mall);
            break;
         case "handle purchase":
            mall.purchase(customer);
            break;
         case "handle aftersale":
            mall.aftersale(customer);
            break;
         default:
            break;
      }
   }
}