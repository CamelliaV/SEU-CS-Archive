package seu.assignment.composition_uniformity;

/**
 * @ClassName: Apple
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/25 10:53:05
 * @Input:
 * @Output:
 */
class Apple implements FruitPlate {
	@Override
	public void eat() {
		System.out.println("[Apple] Sweet Apple");
	}

	@Override
	public void add(FruitPlate fruitPlate) {

	}

	@Override
	public void remove(FruitPlate fruitPlate) {

	}
}