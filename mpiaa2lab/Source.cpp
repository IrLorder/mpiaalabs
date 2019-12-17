#include "library.h"

struct Graph {


};

int main()
{
	setlocale(0, "");
	int n = 0;
	int count = 0;
	ifstream in("input.txt");
	// ���� ���� �� ��������
	if (!in)
	{
		printf_s("�� ������� ������� ���� input.txt");
		in.close();
		_getch();
		return 0;
	}
	// ����������� ���������� ������ � �������.
	in >> n;
	if (n <= 0) {
		printf_s("���������� ������ ������������� �������� ���� ������ 0");
		_getch();
		return 0;
	}
	// и���
	int a, b;
	g.resize(n);
	gr.resize(n);
	while (!in.eof()) {
		in >> a >> b;
		// �������� ������������ �� ����� ������ �������������, �� ��� ������ 0.
		if (((a > n) || (b > n)) || ((a <= 0) || (b <= 0))) {
			printf_s("���������� ��������� � ��������� ��������� ���������� ������� �����������.\n������ ������ ������ ���� �������������� � �� ��������� n");
			in.close();
			_getch();
			return 0;
		}
		else
			g[a - 1].push_back(b - 1);
		gr[b - 1].push_back(a - 1);
	}
	// ������������ ������� used ����������� n
	used.assign(n, false);
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	used.assign(n, false);
	ofstream fout("output.txt");
	for (int i = 0; i < n; i++)
	{
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			// ����� ���
			if (component.size() > 1)
			{
				for (size_t j = 0; j < component.size(); j++)
					fout << component[j] + 1 << " ";
				fout << endl;
				count++;
			}
			component.clear();
		}
	}
	in.close();
	fout.close();
	if (count == 0) {
		printf_s("�� ������� ��������� �� ����� ���");
		_getch();
		return 0;
	}
}