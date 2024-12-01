package seu.assignment.scenario2;

abstract class Participant {
   private String name;
   private Hotline mediator;

   public void setMediator(Hotline hotline) {
      this.mediator = hotline;
   }

   public abstract void act();
}