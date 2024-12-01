package seu.assignment.factory_method;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/9 11:10:40
 * @Input:
 * @Output:
 */
class Client {
   public static void main(String[] args) {
      String gifFile = "camelia.gif";
      String jpgFile = "cayena.jpg";

      ImageReaderFactory gifFactory = new GifReaderFactory();
      ImageReaderFactory jpgFactory = new JpgReaderFactory();

      ImageReader gifReader = gifFactory.createImageReader();
      ImageReader jpgReader = jpgFactory.createImageReader();

      // ----- for gif reader
      gifReader.readImage(gifFile);
      gifReader.readImage(jpgFile);

      // ----- for jpg reader
      jpgReader.readImage(gifFile);
      jpgReader.readImage(jpgFile);
   }
}