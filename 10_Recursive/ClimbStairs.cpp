int climbStairs(int n) {
    int arr[3] = {0, 1, 2};
    for (int i = 3; i <= n; i++)
        arr[i % 3] = arr[(i - 1) % 3] + arr[(i - 2) % 3];
    return arr[n % 3];
}

int climbStairs(int n) {
    if (n < 2)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}