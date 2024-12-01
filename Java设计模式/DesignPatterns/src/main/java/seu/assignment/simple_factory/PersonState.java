package seu.assignment.simple_factory;

/**
 * @ClassName: PersonState
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 21:08:59
 * @Input:
 * @Output:
 */
class PersonState {

   private String identity;
   private String name;

   public void stateMe() {
      System.out.println("-------------State: ----------");
      System.out.println("-------------Identity: " + this.identity);
      System.out.println("-------------Name: " + this.name);
      System.out.println("-------------State End");
      System.out.println();
   }

   public PersonState() {}

   public void setIdentity(String identity) {
      this.identity = identity;
   }

   public void setName(String name) {
      this.name = name;
   }
}