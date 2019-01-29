//在这里创建一个抽象类，这个类的内容的身份，后缀Abstract用于辨识是抽象类
public abstract class IdentifyAbstract {
	public  String domain;

	public abstract void identifyShow();
	public abstract void identifyHide();

	public String getDomain() {
		return domain;
	}
}

