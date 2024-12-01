package seu.assignment.triple_bridge;

/**
 * @ClassName: Logger
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:49:26
 * @Input:
 * @Output:
 */
abstract class Logger {
   protected OperatingSystem os;
   protected ProgrammingLanguage language;

   public abstract void log(String message);
   public void setOperatingSystem(OperatingSystem os) {
      this.os = os;
   }
   public void setProgrammingLanguage(ProgrammingLanguage language) {
      this.language = language;
   }
}