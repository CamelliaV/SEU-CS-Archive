package seu.assignment.bridge;

/**
 * @ClassName: WMVFile
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:06:28
 * @Input:
 * @Output:
 */
class WMVFile implements VideoFile {
   @Override
   public void decode(String osType, String fileName) {
      System.out.println("OS-Type: " + osType + "------- " + "FileName: " + fileName + ".wmv");
   }
}