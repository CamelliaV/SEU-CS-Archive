package seu.assignment.final_scenario;

class Pharmacy {
   public ShoppingCart makeList() {
      return ShoppingCartBuilder.getInstance().makeList();
   }
}