package seu.assignment.scenario3;

abstract class AbstractPlatform {
   private String name;

   public String getName() {
      return name;
   }

   public void setName(String name) {
      this.name = name;
   }

   public void responseToOrder(Kitchen kitchen, Order order) {
      order.setKitchen(kitchen);
   }
}