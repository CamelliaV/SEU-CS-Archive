package seu.assignment.factory_method;

/**
 * @ClassName: JpgReader
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/9 11:01:30
 * @Input:
 * @Output:
 */
class JpgReader implements ImageReader {
   @Override
   public void readImage(String url) {
      if (url.endsWith(".jpg")) {
         System.out.println("---------------JPG Reader Working On: " + url);
         return;
      }
      System.out.println("---------------Error Format For JPG Reader!");
   }
}