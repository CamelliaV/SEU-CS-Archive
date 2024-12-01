package seu.assignment.scenario4;

class Client {
   public static void main(String[] args) {
      Consumer camelia = new Consumer();
      AbstractRestaurant taoBeiRestaurant = new TaoBeiRestaurant();
      camelia.setConsumingStyle(new ChewDown());
      camelia.setRestaurant(taoBeiRestaurant);
      camelia.chooseWindow();
      camelia.searchForSeat(new SeatSearching());
      camelia.goForDinner();
      camelia.setCommand(new Pay());
      camelia.orderCommand(new Reception());
      camelia.setCommand(new Clean());
      camelia.orderCommand(new Cleaner());

      System.out.println();
      System.out.println();

      camelia.setRestaurant(new MeiYuanRestaurant());
      camelia.chooseWindow();
      camelia.searchForSeat(new SeatSearching());
      camelia.goForDinner();
      camelia.setCommand(new Pay());
      camelia.orderCommand(new Reception());
      camelia.setCommand(new Clean());
      camelia.orderCommand(new Cleaner());
   }
}