package seu.assignment.scenario4;

class Clean implements Command {
   @Override
   public void execute(Staff staff) {
      System.out.println("Clean Command");
      staff.action();
   }
}