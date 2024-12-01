package seu.assignment.bridge;

/**
 * @ClassName: AVIFile
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:06:21
 * @Input:
 * @Output:
 */
class AVIFile implements VideoFile {
	@Override
	public void decode(String osType, String fileName) {
		System.out.println("OS-Type: " + osType + "------- " + "FileName: " + fileName + ".avi");
	}
}