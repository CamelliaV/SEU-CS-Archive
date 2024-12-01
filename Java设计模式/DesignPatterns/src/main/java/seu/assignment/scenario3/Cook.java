package seu.assignment.scenario3;

class Cook implements DishBuilder {
	private String name;

	@Override
	public void buildRaw() {
		System.out.println("----------------Cook: build raw");
	}

	@Override
	public void buildCooked() {
		System.out.println("----------------Cook: build cooked");
	}

	@Override
	public void buildDrink() {
		System.out.println("----------------Cook: build drink");
	}

	@Override
	public Dish packageUp(String content) {
		System.out.println("----------------Cook: package up");
		System.out.println("----------------Content: " + content);
		return new Dish(content, "black tea");
	}
}