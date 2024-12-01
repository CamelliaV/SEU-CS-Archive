package seu.assignment.bridge;

/**
 * @ClassName: LinuxVersion
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:04:40
 * @Input:
 * @Output:
 */
class LinuxVersion extends OperatingSystemVersion {
   @Override
   public void play(String filename) {
      this.videoFile.decode("Linux", filename);
   }
}