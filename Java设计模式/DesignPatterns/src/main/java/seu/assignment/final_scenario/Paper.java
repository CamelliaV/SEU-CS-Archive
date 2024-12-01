package seu.assignment.final_scenario;

class Paper implements Item {
	@Override
	public void accept(Colleague colleague) {
		System.out.println("选中: " + this.getClass().getSimpleName());
		colleague.pick();
	}
	@Override
	public Double getPrice() {
		return 300.0;
	}
}