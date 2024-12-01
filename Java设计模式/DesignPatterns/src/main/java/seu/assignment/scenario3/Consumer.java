package seu.assignment.scenario3;

class Consumer {
	private String name;
	private Order order;

	public Dish makeOrder() {
		return order.dispatch();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Order getOrder() {
		return order;
	}

	public void setOrder(Order order) {
		this.order = order;
	}

	public void consume(Dish dish) {
		System.out.println("---------Consumer: Dish consumed!");
		System.out.println("---------Consumer: Dish details");
		System.out.println(dish);
		System.out.println("---------Consumer: Order details");
		System.out.println(order);
	}

	@Override
	public String toString() {
		return "Consumer{" +
				"name='" + name + '\'' +
				", order=" + order +
				'}';
	}
}