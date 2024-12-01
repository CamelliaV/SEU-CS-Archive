package seu.assignment.scenario4;

import java.util.ArrayList;
import java.util.List;

class SeatSearching {
   private List<Seat> allSeats = new ArrayList<>();

   public SeatSearching() {
      updateSeats();
   }

   // for simplicity, technically should be maintained by the restaurant it belongs to
   private void updateSeats() {
      allSeats.add(new Sofa(0));
      allSeats.add(new Sofa(1));
      allSeats.add(new Sofa(2));
      allSeats.add(new Sofa(3));
      allSeats.add(new Sofa(4));
      allSeats.add(new Sofa(5));
      allSeats.add(new SoftSeat(6));
      allSeats.add(new SolidSeat(7));
   }

   public Seat accessSeats() {
      if (allSeats.size() == 0) {
         updateSeats();

      }

      return allSeats.remove(0);
   }
}