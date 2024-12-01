package seu.assignment.scenario3;

class Dish {
	private String toEat;

	private String toDrink;

	@Override
	public String toString() {
		return "Dish{" +
				"toEat='" + toEat + '\'' +
				", toDrink='" + toDrink + '\'' +
				'}';
	}

	public Dish(String toEat, String toDrink) {
		this.toEat = toEat;
		this.toDrink = toDrink;
	}

	public String getToEat() {
		return toEat;
	}

	public void setToEat(String toEat) {
		this.toEat = toEat;
	}

	public String getToDrink() {
		return toDrink;
	}

	public void setToDrink(String toDrink) {
		this.toDrink = toDrink;
	}


}