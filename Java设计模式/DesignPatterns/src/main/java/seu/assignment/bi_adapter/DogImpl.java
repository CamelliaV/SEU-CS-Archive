package seu.assignment.bi_adapter;

/**
 * @ClassName: DogImpl
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 20:03:55
 * @Input:
 * @Output:
 */
class DogImpl implements Dog {
	@Override
	public void shout() {
		System.out.println("[DogImpl] Shout like a dog");
	}
}