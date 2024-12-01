package seu.assignment.final_scenario;

abstract class AftersaleProcess {
   protected AftersaleProcess next;

   public void setNext(AftersaleProcess next) {
      this.next = next;
   }

   public abstract void response();
}