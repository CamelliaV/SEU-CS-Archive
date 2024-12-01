package seu.assignment.facade;

/**
 * @ClassName: CoffeeBar
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 21:35:37
 * @Input:
 * @Output:
 */
class CoffeeBar {
   public CoffeeBar() {}
   private Bean bean = new Bean();
   private Water water = new Water();
   private Method method = new Method();

   public Coffee getCoffee() {
      bean.fetchBean();
      water.boilWater();
      method.chooseMethod();
      return new Coffee();
   }
}