package seu.assignment.final_scenario;

import java.util.List;

abstract class Colleague {

	protected Mediator mediator;

	protected List<Item> list;

	public void pick() {
		System.out.println("已确认选择");
	}

	public void deliver(List<Item> list) {
		this.list = list;
	}

	public abstract void purchase(Colleague colleague);
	public abstract void aftersale(Colleague colleague);
	public void singleAction(String message) {} // omitted
}
