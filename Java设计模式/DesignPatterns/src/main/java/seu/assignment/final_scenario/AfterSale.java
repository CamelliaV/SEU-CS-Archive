package seu.assignment.final_scenario;

class AfterSale extends AftersaleProcess {
   public void serve() {
      System.out.println("--------Aftersale: after-sale services");
   }

   @Override
   public void response() {
      serve();
   }
}