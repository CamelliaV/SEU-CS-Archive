package seu.assignment.scenario4;

class Pay implements Command {
   @Override
   public void execute(Staff staff) {
      System.out.println("Pay Command");
      staff.action();
   }
}