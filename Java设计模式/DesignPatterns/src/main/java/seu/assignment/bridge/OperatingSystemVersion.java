package seu.assignment.bridge;

abstract class OperatingSystemVersion {
	protected VideoFile videoFile;

	public void setVideoFile(VideoFile videoFile) {
		this.videoFile = videoFile;
	}

	public abstract void play(String filename);
}
