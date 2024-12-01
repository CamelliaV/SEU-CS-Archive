package seu.assignment.final_scenario;

import java.util.ArrayList;
import java.util.List;

class ShoppingCart {
   private List<Item> list = new ArrayList<>();

   public void addItem(Item item) {
      list.add(item);
   }

   public void checkOut(Colleague colleague) {
      for (Item i : list) {
         i.accept(colleague);
         System.out.println("---------ShoppingCart: checkout  " + i.getClass().getSimpleName() + "  " + i.getPrice());
      }
      System.out.println();
   }

   public List<Item> getList() {
      return list;
   }
}