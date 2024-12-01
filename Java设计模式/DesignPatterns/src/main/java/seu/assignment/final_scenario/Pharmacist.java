package seu.assignment.final_scenario;

class Pharmacist extends PurchaseProcess {

   public void advise() {
      System.out.println("--------Pharmacist: some advice about medicine");
   }

   @Override
   public void response() {
      advise();
      next.response();
   }
}