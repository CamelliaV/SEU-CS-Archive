package seu.assignment.bi_adapter;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 20:22:03
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      Cat cat = new CatImpl();
      Dog dog = new DogImpl();
      CatDogBiAdapter biAdapter = new CatDogBiAdapter(cat, dog);
      biAdapter.catchMouse(); // like a dog
      biAdapter.shout(); // like a cat
   }
}