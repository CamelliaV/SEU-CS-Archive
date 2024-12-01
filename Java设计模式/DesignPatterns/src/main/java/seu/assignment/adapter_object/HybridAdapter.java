package seu.assignment.adapter_object;

/**
 * @ClassName: HybridAdapter
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/9/24 16:57:37
 * @Input:
 * @Output:
 */
class HybridAdapter implements Robot {
   Dog dog;
   Bird bird;
   public HybridAdapter(Dog dog, Bird bird) {
      this.dog = dog;
      this.bird = bird;
   }

   @Override
   public void cry() {
      bird.cry();
   }

   @Override
   public void move() {
      dog.run();
   }
}