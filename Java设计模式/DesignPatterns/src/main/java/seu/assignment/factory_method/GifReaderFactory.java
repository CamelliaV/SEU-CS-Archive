package seu.assignment.factory_method;

/**
 * @ClassName: GifReaderFactory
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/9 11:06:40
 * @Input:
 * @Output:
 */
class GifReaderFactory extends ImageReaderFactory {
   @Override
   public ImageReader createImageReader() {
      return new GifReader();
   }
}