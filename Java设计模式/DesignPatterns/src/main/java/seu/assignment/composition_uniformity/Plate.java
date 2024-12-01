package seu.assignment.composition_uniformity;

import java.util.ArrayList;

/**
 * @ClassName: Plate
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/25 10:53:42
 * @Input:
 * @Output:
 */
class Plate implements FruitPlate {
	private ArrayList<FruitPlate> fruits = new ArrayList<>();
	@Override
	public void eat() {
		fruits.forEach(FruitPlate::eat);
	}

	@Override
	public void add(FruitPlate fruitPlate) {
		fruits.add(fruitPlate);
	}

	@Override
	public void remove(FruitPlate fruitPlate) {
		fruits.remove(fruitPlate);
	}
}