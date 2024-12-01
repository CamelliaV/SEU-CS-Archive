package seu.assignment.scenario3;

public interface DishBuilder {
	void buildRaw();
	void buildCooked();
	void buildDrink();
	Dish packageUp(String content);
}
