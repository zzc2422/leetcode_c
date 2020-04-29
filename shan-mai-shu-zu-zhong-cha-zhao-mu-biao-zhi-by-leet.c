typedef struct MountainArray MountainArray;
int get(MountainArray*, int index);
int length(MountainArray*);

int findInMountainArray(int target, MountainArray* ma_p) {
	int base = 0, len = length(ma_p);
	int left_value = get(ma_p, 0), right_value = get(ma_p, len - 1);
	while (1) {
		int left_length = len >> 1;
		int m_value = get(ma_p, base + left_length);
		int llm = left_value < m_value, mlr = m_value < right_value;
		if (!(llm ^ mlr)) {
			int tlm = target < m_value;
			if (llm ^ tlm) {
				len = left_length;
			} else {
				base += left_length;
				len -= left_length;
			}
			continue;
		}
	}
}