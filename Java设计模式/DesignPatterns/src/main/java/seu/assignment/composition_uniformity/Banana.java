package seu.assignment.composition_uniformity;

/**
 * @ClassName: Banana
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/25 10:53:12
 * @Input:
 * @Output:
 */
class Banana implements FruitPlate {
	@Override
	public void eat() {
		System.out.println("[Banana] Tasty Banana");
	}

	@Override
	public void add(FruitPlate fruitPlate) {

	}

	@Override
	public void remove(FruitPlate fruitPlate) {

	}
}