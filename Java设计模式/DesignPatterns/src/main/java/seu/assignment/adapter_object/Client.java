package seu.assignment.adapter_object;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 17:01:42
 * @Input:
 * @Output:
 */
class Client {
	public static void main(String[] args) {
		Dog dog = new Dog();
		Bird bird = new Bird();
		Robot robot = new HybridAdapter(dog, bird);
		robot.cry(); // like a bird
		robot.move(); // like a dog
	}
}