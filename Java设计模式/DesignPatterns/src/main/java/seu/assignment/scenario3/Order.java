package seu.assignment.scenario3;

class Order {
	private String dishType;
	private String address;
	private AbstractPlatform platform;
	private Kitchen kitchen;

	public String getDishType() {
		return dishType;
	}

	public void setDishType(String dishType) {
		this.dishType = dishType;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public AbstractPlatform getPlatform() {
		return platform;
	}

	public void setPlatform(AbstractPlatform platform) {
		this.platform = platform;
	}

	public Kitchen getKitchen() {
		return kitchen;
	}

	@Override
	public String toString() {
		return "Order{" +
				"dishType='" + dishType + '\'' +
				", address='" + address + '\'' +
				", platform=" + platform +
				", kitchen=" + kitchen +
				'}';
	}

	public void setKitchen(Kitchen kitchen) {
		this.kitchen = kitchen;
	}

	public Order(String dishType, String address, AbstractPlatform platform, Kitchen kitchen) {
		this.dishType = dishType;
		this.address = address;
		this.platform = platform;
		this.kitchen = kitchen;
	}

	public Dish dispatch() {
		return kitchen.cook(this);
	}
}