package seu.assignment.scenario4;

abstract class Seat {
   private String type;
   private Integer number;

   public Seat(Integer number) {

      this.number = number;
   }

   public Integer locate() {
      return number;
   }

   public void setNumber(Integer number) {
      this.number = number;
   }

   public String getType() {
      return type;
   }
}