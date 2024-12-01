package seu.assignment.bi_adapter;

/**
 * @ClassName: CatDogBiAdapter
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 20:16:42
 * @Input:
 * @Output:
 */
class CatDogBiAdapter implements Cat, Dog {
	Cat cat;
	Dog dog;
	public CatDogBiAdapter(Cat cat, Dog dog) {
		this.cat = cat;
		this.dog = dog;
	}
	@Override
	public void catchMouse() {
		dog.shout();
	}

	@Override
	public void shout() {
		cat.catchMouse();
	}
}