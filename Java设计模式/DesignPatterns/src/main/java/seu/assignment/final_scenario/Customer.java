package seu.assignment.final_scenario;

class Customer extends Colleague {

	private String name;

	// private House house;

	private final ConsumingProcess consumingProcess = new ConsumingProcessImpl();

	public void consume() {
		System.out.println("现有药品：");
		if (list == null) {
			return;
		}
		list.stream().map(item -> item.getClass().getSimpleName()).forEach(System.out::println);
		System.out.println("使用过程：");
		consumingProcess.measureTemperature();
		consumingProcess.testAntigen();
		consumingProcess.consumeTablets();
		consumingProcess.consumePapers();
		System.out.println("Feel: " + consumingProcess.calm());
	}

	@Override
	public void purchase(Colleague colleague) {
		System.out.println("purchase at: " + colleague.getClass().getSimpleName());
	}

	@Override
	public void aftersale(Colleague colleague) {
		System.out.println("aftersale at: " + colleague.getClass().getSimpleName());
	}
}