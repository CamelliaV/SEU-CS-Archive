package seu.assignment.composition_uniformity;

/**
 * @ClassName: Pear
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/25 10:53:18
 * @Input:
 * @Output:
 */
class Pear implements FruitPlate {
	@Override
	public void eat() {
		System.out.println("[Pear] Fragrant Pear");
	}

	@Override
	public void add(FruitPlate fruitPlate) {

	}

	@Override
	public void remove(FruitPlate fruitPlate) {

	}
}