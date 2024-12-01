package seu.assignment.bridge;

/**
 * @ClassName: FLVFile
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:06:41
 * @Input:
 * @Output:
 */
class FLVFile implements VideoFile {
   @Override
   public void decode(String osType, String fileName) {
      System.out.println("OS-Type: " + osType + "------- " + "FileName: " + fileName + ".flv");

   }
}