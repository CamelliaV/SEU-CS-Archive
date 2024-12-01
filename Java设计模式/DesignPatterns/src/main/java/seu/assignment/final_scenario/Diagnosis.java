package seu.assignment.final_scenario;

class Diagnosis extends PurchaseProcess {

   public void diagnose() {
      System.out.println("--------Diagnosis: detailed diagnose about illness");
   }

   @Override
   public void response() {
      diagnose();
   }
}