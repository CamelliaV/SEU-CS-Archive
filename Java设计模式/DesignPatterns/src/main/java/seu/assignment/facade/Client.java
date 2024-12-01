package seu.assignment.facade;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 21:48:18
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      // at home

      Home home = new Home(); // go home
      home.fetchBean();
      home.boilWater();
      home.chooseMethod();
      Coffee coffeeFromHome = home.getCoffee(); // nasty
      coffeeFromHome.drink();

      // at coffee-bar

      CoffeeBar coffeeBar = new CoffeeBar(); // go to coffee bar
      Coffee coffeeFromBar = coffeeBar.getCoffee(); // convenient
      coffeeFromBar.drink();
   }
}