dp = [[0 for x in range(52)] for y in range(52)]
for i in range(0, 51):
    dp[0][i] = 1
for i in range(1, 51):
    for j in range(1, 51):
        for k in range(1, i + 1):
            dp[i][j] += dp[i - k][j] * dp[k - 1][j - 1]
caseno = 1
while True:
    n, k = map(int, raw_input().split())
    if n == 0 and k == 0:
        break
    if caseno > 1:
        print
    print "Case " + str(caseno) + ": " + str(dp[n][k] - dp[n][k - 1])
    caseno += 1
