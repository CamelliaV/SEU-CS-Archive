package seu.assignment.bridge;

/**
 * @ClassName: WindowsVersion
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:04:47
 * @Input:
 * @Output:
 */
class WindowsVersion extends OperatingSystemVersion {
   @Override
   public void play(String filename) {
      this.videoFile.decode("Windows", filename);

   }
}