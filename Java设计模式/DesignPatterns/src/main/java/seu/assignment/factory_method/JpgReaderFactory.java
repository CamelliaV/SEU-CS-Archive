package seu.assignment.factory_method;

/**
 * @ClassName: JpgReaderFactory
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/9 11:04:59
 * @Input:
 * @Output:
 */
class JpgReaderFactory extends ImageReaderFactory {
   @Override
   public ImageReader createImageReader() {
      return new JpgReader();
   }
}