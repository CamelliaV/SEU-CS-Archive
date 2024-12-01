package seu.assignment.final_scenario;

class ConsumingProcessImpl implements ConsumingProcess {

   @Override
   public void measureTemperature() {
      System.out.println("测体温");
   }

   @Override
   public void testAntigen() {
      System.out.println("使用抗原");

   }

   @Override
   public void consumeTablets() {
      System.out.println("使用药片");

   }

   @Override
   public void consumePapers() {
      System.out.println("使用纸巾");

   }

   @Override
   public String calm() {
      return "Better";
   }
}