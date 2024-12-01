package seu.assignment.factory_method;

/**
 * @ClassName: GifReader
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/9 11:04:21
 * @Input:
 * @Output:
 */
class GifReader implements ImageReader {
   @Override
   public void readImage(String url) {
      if (url.endsWith(".gif")) {
         System.out.println("---------------GIF Reader Working On: " + url);
         return;
      }
      System.out.println("---------------Error Format For GIF Reader!");
   }
}