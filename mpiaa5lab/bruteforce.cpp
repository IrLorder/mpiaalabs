#include "bruteforce.h"
#include "sha256.h"

std::vector<std::string> passwords;
void push(std::string const& chars, size_t max_len, std::string const& cur) {
	if (cur.length() == max_len)
		return;

	for (char c : chars) {
		std::string next = cur + c;

		passwords.push_back(next);
		push(chars, max_len, next);
	}
}

std::vector<std::string> all_words(const std::string& alphabet, int max_length) {
	passwords.clear();
	push(alphabet, max_length, "");

	return passwords;
}

std::string bruteforce(const std::string &alphabet, int max_length, const std::string &password_hash) {
    // Try to crack password by brute force, using all possible passwords with given alphabet and max length.
    // Use sha256(string) function to compute password's hash and match it with given hash.
    // Return password for which hashes are matched.
    // Return empty string if password isn't found.

    for (const auto &password: all_words(alphabet, max_length)) {
        if (sha256(password) == password_hash) {
            return password;
        }
    }
    return "";
}
