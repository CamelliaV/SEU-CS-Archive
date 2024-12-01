package seu.assignment.bridge;

/**
 * @ClassName: MPEGFile
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:07:02
 * @Input:
 * @Output:
 */
class MPEGFile implements VideoFile {
   @Override
   public void decode(String osType, String fileName) {
      System.out.println("OS-Type: " + osType + "------- " + "FileName: " + fileName + ".mpeg");

   }
}