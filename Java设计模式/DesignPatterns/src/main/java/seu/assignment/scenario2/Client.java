package seu.assignment.scenario2;

class Client {
   public static void main(String[] args) {
      Consumer camelia = new Consumer();
      SuNing suNing = new SuNing();
      NanJingDaJin nanJingDaJin = new NanJingDaJin();
      ShangHaiDaJin shangHaiDaJin = new ShangHaiDaJin();
      suNing.contactNanJing(camelia, nanJingDaJin);
      suNing.contactShangHai(camelia, shangHaiDaJin);

   }
}