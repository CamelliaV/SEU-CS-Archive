package seu.assignment.scenario3;

class Client {
   public static void main(String[] args) {
      AbstractPlatform platformA = new MeiTuan();
      AbstractPlatform platformB = new JiuLongHuRestaurant();
      Kitchen kitchenA = new Kitchen("KitchenA");
      Kitchen kitchenB = new Kitchen("KitchenB");
      Consumer camelia = new Consumer();
      camelia.setName("Camelia");
      Order firstOrder = new Order("friedChicken", "SEU", platformA, null);
      platformA.responseToOrder(kitchenA, firstOrder);
      camelia.setOrder(firstOrder);
      camelia.consume(camelia.makeOrder());
      System.out.println();

      Order secondOrder = new Order("applePie", "SEU", platformB, null);
      platformB.responseToOrder(kitchenB, secondOrder);
      camelia.setOrder(secondOrder);
      camelia.consume(camelia.makeOrder());
   }
}