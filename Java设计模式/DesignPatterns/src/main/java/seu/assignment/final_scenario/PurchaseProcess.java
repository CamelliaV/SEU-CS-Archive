package seu.assignment.final_scenario;

abstract class PurchaseProcess {
   protected PurchaseProcess next;

   public void setNext(PurchaseProcess next) {
      this.next = next;
   }

   public abstract void response();
}