package seu.assignment.composition_uniformity;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/25 11:03:59
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      // prepare some fruits
      FruitPlate apple = new Apple();
      FruitPlate banana1 = new Banana();
      FruitPlate banana2 = new Banana();
      FruitPlate pear = new Pear();

      // add to the plate
      FruitPlate fruitPlate = new Plate();
      fruitPlate.add(apple);
      fruitPlate.add(banana1);
      fruitPlate.add(banana2);
      fruitPlate.add(pear);

      // remove duplicate banana and eat the rest
      fruitPlate.remove(banana2);
      fruitPlate.eat(); // apple -> banana -> pear

      System.out.println("--------------------");

      // eat respectively
      apple.eat();
      banana1.eat();
      banana2.eat();
      pear.eat();
   }
}