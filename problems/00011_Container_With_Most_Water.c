int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

int min(int x, int y)
{
	if (x > y) return y;
	else return x;
}

int maxArea(int* height, int heightSize) {
	int result = 0;
	int i = 0;
	int j = heightSize - 1;
	while (i < j) {
		int area = min(height[i], height[j]) * (j - i);
		result = max(result, area);
		if (height[i] < height[j]) i++;
		else j--;
	}
	return result;
}