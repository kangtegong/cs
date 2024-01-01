public class UnicodeCodepoint {
	public static void main(String[] args) {
		int cp1 = "한".codePointAt(0);
		System.out.println("한: " + Integer.toHexString(cp1).toUpperCase());

		int cp2 = "글".codePointAt(0);
		System.out.println("글: " + Integer.toHexString(cp2).toUpperCase());
	}
}
