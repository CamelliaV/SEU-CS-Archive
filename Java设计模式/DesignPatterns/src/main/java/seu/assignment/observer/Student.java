package seu.assignment.observer;

/**
 * @ClassName: Student
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 21:53:18
 * @Input:
 * @Output:
 */
class Student implements Consignee {
   private String name;
   private String department;

   public Student(){}
   public Student(String name) {
      this.name = name;
   }
   @Override
   public void respond(String departmentName) {
      this.department = departmentName;
      System.out.println("Student: " + name + " -> Department: " + department + " ! ---------");
   }
}