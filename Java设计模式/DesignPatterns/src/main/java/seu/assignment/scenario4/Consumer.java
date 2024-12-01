package seu.assignment.scenario4;

import java.util.Objects;
import java.util.Random;

class Consumer {
   private HallStrategy hall;

   private WindowStrategy windowStrategy;
   private Seat place;
   private Integer preferredNumber = new Random().nextInt(10);
   private ConsumingStyle style;
   private Command command;
   private AbstractRestaurant restaurant;

   public void goForDinner() {
      hall.dinner();
      style.haveFruits();
      style.haveVegetables();
      style.haveMeats();
      style.haveDrinks();
      System.out.println("------Feeling: " + style.digest());

   }

   public void chooseWindow() {
      for (Window w : restaurant) {
         if (Objects.equals(w.getNumber(), preferredNumber)) {
            System.out.println("----------Chose window: " + w.getNumber());
            return;
         }
      }
      System.out.println("----------No expected window: " + preferredNumber);
   }

   public void setConsumingStyle(ConsumingStyle style) {
      this.style = style;
   }

   public void searchForSeat(SeatSearching search) {
      place = search.accessSeats();
   }

   public void orderCommand(Staff staff) {
      command.execute(staff);
   }

   public void setCommand(Command command) {
      this.command = command;
   }

   public void setRestaurant(AbstractRestaurant restaurant) {
      this.restaurant = restaurant;
      this.hall = restaurant;
   }
}