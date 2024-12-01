package seu.assignment.final_scenario;

class ShoppingCartBuilder {

   private final static ShoppingCartBuilder instance = new ShoppingCartBuilder();
   public ShoppingCart makeList() {
      ShoppingCart shoppingCart = new ShoppingCart();
      shoppingCart.addItem(new Tablets());
      shoppingCart.addItem(new Antigen());
      shoppingCart.addItem(new Paper());
      shoppingCart.addItem(new Thermometer());
      shoppingCart.addItem(new GramSensin());
      shoppingCart.addItem(new Tylenol());
      return shoppingCart;
   }

   public static ShoppingCartBuilder getInstance() {
      return instance;
   }
}