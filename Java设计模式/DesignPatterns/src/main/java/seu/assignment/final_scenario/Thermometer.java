package seu.assignment.final_scenario;

class Thermometer implements Item {
	@Override
	public void accept(Colleague colleague) {
		System.out.println("选中: " + this.getClass().getSimpleName());
		colleague.pick();
	}
	@Override
	public Double getPrice() {
		return 145.3;
	}
}