package seu.assignment.scenario3;

class Kitchen {

	private String name;
	private DishBuilder chief = new Cook();

	public Kitchen(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "Kitchen{" +
				"name='" + name + '\'' +
				'}';
	}

	public Dish cook(Order order) {
		chief.buildRaw();
		chief.buildCooked();
		chief.buildDrink();
		return chief.packageUp(order.getDishType());
	}
}