package seu.assignment.final_scenario;

class OnlineMedicineMall extends Colleague {
   private final Guide guide = new Guide();
   private final Pharmacist pharmacist = new Pharmacist();
   private final Diagnosis diagnosis = new Diagnosis();
   private final AfterSale afterSale = new AfterSale();

   private final Pharmacy pharmacy = new Pharmacy();
   private final PurchaseProcess purchaseProcess = guide;
   private final AftersaleProcess aftersaleProcess = afterSale;
   private final JingDongExpress jingDongExpress = new JingDongExpress();

   public OnlineMedicineMall() {
      guide.setNext(pharmacist);
      pharmacist.setNext(diagnosis);
   }

   public void guide() {
      guide.guide();
   }

   public void advise() {
      pharmacist.advise();
   }

   public void diagnose() {
      diagnosis.diagnose();
   }

   public void serve() {
      afterSale.serve();
   }

   public ShoppingCart makeList() {
      return pharmacy.makeList();
   }

   @Override
   public void purchase(Colleague colleague) {
      purchaseProcess.response();
      deliver(colleague);
   }

   @Override
   public void aftersale(Colleague colleague) {
      aftersaleProcess.response();
      deliver(colleague);
   }

   public void deliver(Colleague colleague) {
      ShoppingCart shoppingCart = makeList();
      list = shoppingCart.getList();
      shoppingCart.checkOut(colleague);
      colleague.deliver(list);
   }
}