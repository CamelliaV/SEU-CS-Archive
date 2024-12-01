package seu.assignment.builder;

/**
 * @ClassName: AbstractCharacterBuilder
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 21:51:23
 * @Input:
 * @Output:
 */
abstract class AbstractCharacterBuilder {
   protected Character character = new Character();
   protected abstract void buildGender();
   protected abstract void buildFace();
   protected abstract void buildSuit();
   protected abstract void buildHairstyle();

   public Character synthesizeCharacter() {
      buildGender();
      buildFace();
      buildSuit();
      buildHairstyle();
      return character;
   };
}