package seu.assignment.state;

/**
 * @ClassName: Primary
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 15:34:17
 * @Input:
 * @Output:
 */
class Primary implements Level {
	@Override
	public void play() {
		System.out.println("---------------Play Game");
	}

	@Override
	public boolean doubleScore() {
		System.out.println("---------------!!!!Not Allowed");
		return false;
	}

	@Override
	public void changeCards() {
		System.out.println("---------------!!!!Not Allowed");
	}

	@Override
	public void peekCards() {
		System.out.println("---------------!!!!Not Allowed");
	}
}