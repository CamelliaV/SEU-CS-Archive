package seu.assignment.bridge;

/**
 * @ClassName: RMVBFile
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:06:15
 * @Input:
 * @Output:
 */
class RMVBFile implements VideoFile {
	@Override
	public void decode(String osType, String fileName) {
		System.out.println("OS-Type: " + osType + "------- " + "FileName: " + fileName + ".rmvb");

	}
}