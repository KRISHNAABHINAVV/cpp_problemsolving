class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) return false;

        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u',
                                       'A', 'E', 'I', 'O', 'U');

        boolean hasVowel = false;
        boolean hasConsonant = false;

        for (char c : word.toCharArray()) {
            if (!Character.isLetterOrDigit(c)) return false;

            if (Character.isLetter(c)) {
                if (vowels.contains(c)) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
}
