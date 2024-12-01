package seu.assignment.observer;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 22:00:29
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      Department department = new ConcreteDepartment();
      List<Teacher> teacherList = new ArrayList<>();
      Teacher jupyter = new Teacher("Jupyter");
      Teacher camelia = new Teacher("Camelia");
      Teacher ellie = new Teacher("Ellie");
      Teacher roxana = new Teacher("Roxana");
      Teacher vivienne = new Teacher("Vivienne");

      teacherList.add(jupyter);
      teacherList.add(camelia);
      teacherList.add(ellie);
      teacherList.add(roxana);
      teacherList.add(vivienne);

      List<Student> studentList = new ArrayList<>();
      Student ruby = new Student("Ruby");
      Student fiona = new Student("Fiona");
      Student illyana = new Student("Illyana");
      Student helga = new Student("Helga");

      studentList.add(ruby);
      studentList.add(fiona);
      studentList.add(illyana);
      studentList.add(helga);

      teacherList.forEach(department::attach);
      studentList.forEach(department::attach);
      System.out.println("Switch to -------------- AI");
      department.changeName("Artificial Intelligence");
      System.out.println();
      System.out.println("Switch to -------------- CS");
      department.changeName("Computer Science");
   }
}