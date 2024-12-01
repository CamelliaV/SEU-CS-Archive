package seu.assignment.triple_bridge;
import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 21:03:34
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      List<Logger> loggerList = new ArrayList<Logger>();
      Logger debug = new Debug();
      Logger warn = new Warn();
      Logger info = new Info();
      loggerList.add(debug);
      loggerList.add(warn);
      loggerList.add(info);

      List<OperatingSystem> osList = new ArrayList<>();
      OperatingSystem linux = new Linux();
      OperatingSystem macintosh = new Macintosh();
      OperatingSystem windows = new Windows();
      osList.add(linux);
      osList.add(macintosh);
      osList.add(windows);

      List<ProgrammingLanguage> languageList = new ArrayList<>();
      ProgrammingLanguage rust = new Rust();
      ProgrammingLanguage typeScript = new TypeScript();
      ProgrammingLanguage java = new Java();
      ProgrammingLanguage golang = new Golang();
      languageList.add(rust);
      languageList.add(typeScript);
      languageList.add(java);
      languageList.add(golang);

      for (Logger logger : loggerList) {
         for (ProgrammingLanguage language : languageList) {
            for (OperatingSystem os : osList) {
               logger.setOperatingSystem(os);
               logger.setProgrammingLanguage(language);
               logger.log("Camelia");
            }
         }
      }
   }
}