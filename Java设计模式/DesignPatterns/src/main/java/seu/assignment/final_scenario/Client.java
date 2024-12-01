package seu.assignment.final_scenario;

class Client {
	public static void main(String[] args) {
		System.out.println("初始状态");
		Customer camelia = new Customer();
		camelia.consume();
		OnlineMedicineMall mall = new OnlineMedicineMall();
		Mediator hotline = new Hotline();
		hotline.setCustomer(camelia);
		hotline.setMall(mall);
		System.out.println("处理过程");
		mall.purchase(camelia); //直接购买
//		hotline.handleRequest("purchase", camelia);
//		hotline.handleRequest("handle purchase", mall); //中介方式
		System.out.println("终止状态");
		camelia.consume();
	}
}