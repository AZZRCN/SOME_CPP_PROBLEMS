#undef max
#define max(a,b) ((a)>(b)?(a):(b))
void deal(int source[], int dp_result[],int cur_limit)//最长上升子序列
{
	for (int i = 1; i <= cur_limit; i++)
		for (int j = 1; j < i; j++)
			if (source[j] < source[i])
				dp_result[i] = max(dp_result[i], dp_result[j] + 1);
}