package seu.assignment.scenario4;

class ChewDown implements ConsumingStyle {
   @Override
   public void haveFruits() {
      System.out.println("--------------ChewDown: Having Fruits");
   }

   @Override
   public void haveVegetables() {
      System.out.println("--------------ChewDown: Having Vegetables");

   }

   @Override
   public void haveMeats() {
      System.out.println("--------------ChewDown: Having Meats");

   }

   @Override
   public void haveDrinks() {
      System.out.println("--------------ChewDown: Having Drinks");

   }

   @Override
   public String digest() {
      return "Yummy";
   }
}