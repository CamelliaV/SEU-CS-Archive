package seu.assignment.final_scenario;

class Guide extends PurchaseProcess {

   public void guide() {
      System.out.println("--------Guide: some guide about medicine choices");
   }

   @Override
   public void response() {
      guide();
      next.response();
   }
}