#include "include_all.h"

static void _tra(char table_aa[26][26]) {
	int is_changed;
	do {
		is_changed = 0;
		for (int from = 0; from != 26; from++) {
			for (int to = 0; to != from; to++) {
				for (int i = 0; i != 26; i++) {
					if (i == from || i == to) {
						continue;
					}
					int from_to_i = table_aa[from][i] |
							table_aa[i][from];
					int i_to_to = table_aa[to][i] |
						      table_aa[i][to];
					if (from_to_i && i_to_to &&
					    !table_aa[from][to]) {
						is_changed = 1;
						table_aa[from][to] = 1;
					}
				}
			}
		}
	} while (is_changed);
	for (int i = 0; i != 26; i++) {
		table_aa[i][i] = 1;
	}
}

bool equationsPossible(char* equ_ba[], int equ_amount) {
	char table_aa[26][26];
	memset(table_aa, 0, sizeof(table_aa));
	for (char* const* equ_bp = equ_ba; equ_bp != equ_ba + equ_amount;
	     equ_bp++) {
		const char* equ_str_a = *equ_bp;
		if (equ_str_a[1] == '=') {
			char from = equ_str_a[0], to = equ_str_a[3];
			if (from < to) {
				char c = from;
				from = to;
				to = c;
			}
			table_aa[from - 'a'][to - 'a'] = 1;
		}
	}
	_tra(table_aa);
	for (char* const* equ_bp = equ_ba; equ_bp != equ_ba + equ_amount;
	     equ_bp++) {
		const char* equ_str_a = *equ_bp;
		if (equ_str_a[1] == '!') {
			char from = equ_str_a[0], to = equ_str_a[3];
			if (from < to) {
				char c = from;
				from = to;
				to = c;
			}
			if (table_aa[from - 'a'][to - 'a']) {
				return false;
			}
		}
	}
	return true;
}