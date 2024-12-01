package seu.assignment.facade;

/**
 * @ClassName: Home
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 21:32:29
 * @Input:
 * @Output:
 */
class Home {
   private Bean bean = new Bean();
   private Water water = new Water();
   private Method method = new Method();
   public Home() {}
   public void fetchBean() {
      bean.fetchBean();
   }
   public void boilWater() {
      water.boilWater();
   }
   public void chooseMethod() {
      method.chooseMethod();
   }
   public Coffee getCoffee() {
      return new Coffee();
   }
}